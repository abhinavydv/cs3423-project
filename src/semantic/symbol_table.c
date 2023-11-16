#include "symbol_table.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char * datatype[16][2] = {
        {"bool","1"},
        {"char","1"},
        {"int8","1"},
        {"uint8","1"},
        {"int16","2"},
        {"uint16","2"},
        {"int","4"},
        {"uint","4"},
        {"int32","4"},
        {"uint32","4"},
        {"real32","4"},
        {"int64","8"},
        {"uint64","8"},
        {"real","8"},
        {"real64","8"},
        {"complex","9"}
};

void myprintf(int level, char *format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; i <= level; i++) {
        printf("  ");
    }
    vprintf(format, args);
    va_end(args);
}

int int_len(int num) {
    int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

// only %s and %d are supported
char *format_string(char *format, ...) {
    va_list args;
    va_start(args, format);
    int size = 8;
    int curr_pos = 0;
    char *str = malloc(size);
    while (*format){
        if (*format == '%'){
            format++;
            switch (*format) {
                case 's':
                    char *arg = va_arg(args, char*);
                    str[curr_pos] = 0;
                    curr_pos += strlen(arg);
                    if (size <= curr_pos - 1){
                        size *= 2;
                        str = realloc(str, size);
                    }
                    strcat(str, arg);
                    break;
                case 'd':
                    int num = va_arg(args, int);
                    str[curr_pos] = 0;
                    curr_pos += int_len(num);
                    if (size <= curr_pos - 1){
                        size *= 2;
                        str = realloc(str, size);
                    }
                    sprintf(str, "%s%d", str, num);
                    break;
                case '%':
                    if (curr_pos == size)
                        str = realloc(str, size *= 2);
                    str[curr_pos] = *format;
                    break;
                default:
                    printf("Error: format string not supported\n");
                    break;
            }
        } else {
            if (curr_pos == size)
                str = realloc(str, size *= 2);
            str[curr_pos] = *format;
            curr_pos++;
        }
        format++;
    }
    va_end(args);
    return str;
}

void init_var_type(var_type *type) {
    type->type = PRIMITIVE;
    type->name = NULL;
    type->length = 0;
    type->num_args = 0;
    type->args = NULL;
    type->num_vars = 0;
    type->vars = NULL;
}


void init_id(id *id) {
    id->id = NULL;
    id->num_stars = 0;
    id->num_braks = 0;
    id->brak_vals = NULL;
}


symbol_table *st_create(int size, int level, bool parameters) {
    symbol_table *st = malloc(sizeof(symbol_table));
    st->size = size;
    st->level = level;
    st->parameters = parameters;
    st->is_incomplete = false;
    st->entries = malloc(sizeof(st_entry) * size);
    st->parent = NULL;
    return st;
}


void st_insert(symbol_table *st, st_entry entry) {
    if (st->filled == st->size) {
        st->size *= 2;
        st->entries = realloc(st->entries, sizeof(st_entry) * st->size);
    }
    entry.index = st->filled;
    entry.parent = st;
    st->entries[st->filled++] = entry;
}


var_type *gen_type(id id, var_type type){
    var_type *new_type = malloc(sizeof(var_type));
    init_var_type(new_type);

    if (id.num_stars){
        new_type->type = POINTER;
        id.num_stars--;
    } else if (id.num_braks){
        new_type->type = ARRAY;
        new_type->length = id.brak_vals[0];
        id.num_braks--;
        id.brak_vals++;
    } else {
        *new_type = type;
        return new_type;
    }
    new_type->subtype = gen_type(id, type);
    return new_type;
}


bool is_declared(symbol_table *st, char *name){
    if (find_in_one_table(st,name)!=NULL)
    {
        return true;
    }
    if (st->parent && st->parent->parameters && find_in_one_table(st->parent,name)!=NULL)
    {
        return true;
    }
    return false;
}


void st_insert_var(symbol_table *st, id id, var_type type) {
    if (is_declared(st,id.id))
    {
        yyerror(format_string("Error: variable %s already declared\n", id.id));
    }
    st_entry entry;
    entry.name = strdup(id.id);
    entry.type = gen_type(id, type);
    entry.subtable = NULL;
    st_insert(st, entry);
}


void st_insert_vars(symbol_table *st, id_list* list, var_type type) {
    while (list){
        st_insert_var(st, list->id, type);
        list = list->next;
    }
}


void st_insert_struct(symbol_table *st, char *name, symbol_table *subtable) {
    st_entry entry;
    entry.name = strdup(name);
    entry.type = malloc(sizeof(var_type));
    init_var_type(entry.type);
    entry.type->name = strdup(name);
    entry.type->type = STRUCT_T;
    entry.subtable = subtable;
    st_insert(st, entry);
}


void st_insert_curve(symbol_table *st, id name, id_list *list, int count){
    // printf("%s %d %d %p\n", name.id, name.num_stars, name.num_braks, name.brak_vals);
    st_entry entry;
    entry.name = strdup(name.id);
    var_type type;
    init_var_type(&type);
    type.type = CURVE_T;
    entry.type = gen_type(name, type);
    entry.type->num_vars = count;
    if (count)
        entry.type->vars = malloc(sizeof(char*) * count);
    for (int i = 0; i < count; i++){
        entry.type->vars[i] = strdup(list->id.id);
        list = list->next;
    }
    entry.subtable = NULL;
    st_insert(st, entry);
}


void st_insert_func(symbol_table *st, char *name, var_type type, symbol_table* subtable){
    st_entry entry;
    entry.name = strdup(name);
    entry.type = malloc(sizeof(var_type));
    init_var_type(entry.type);
    entry.type->name = strdup(name);
    entry.type->type = FUNCTION;
    id new_id = {name, 0, 0, 0};
    entry.type->subtype = gen_type(new_id, type);
    entry.subtable = subtable;
    st_insert(st, entry);
}


void st_print_type(var_type *type, int level) {
    // printf("type: %d\n", type->type);
    // printf("type_name: %s\n", type->name);
    // if (type->subtype != NULL) {
    //     printf("subtype:\n");
    //     st_print_type(type->subtype);
    // }
    // if (type->length != 0)
    // printf("length: %d\n", type->length);
    // printf("num_args: %d\n", type->num_args);
    // for (int i = 0; i < type->num_args; i++) {
    //     printf(">>>\n");
    //     st_print_type(&type->args[i]);
    //     printf("<<<\n");
    // }
    // printf("num_vars: %d\n", type->num_vars);
    // printf("vars:\n");
    // for (int i = 0; i < type->num_vars; i++) {
    //     printf("%s ", type->vars[i]);
    // }

    switch (type->type) {
        case PRIMITIVE:
            myprintf(level, "primitive: %s\n", type->name);
            if (type->num_args > 0) {
                myprintf(level, "num_args: %d\n", type->num_args);
                myprintf(level, "args:\n");
                for (int i = 0; i < type->num_args; i++) {
                    st_print_type(&type->args[i], level+1);
                }
            }
            break;
        case POINTER:
            myprintf(level, "pointer:\n");
            st_print_type(type->subtype, level+1);
            break;
        case ARRAY:
            myprintf(level, "array:\n");
            st_print_type(type->subtype, level+1);
            myprintf(level, "length: %d\n", type->length);
            break;
        case STRUCT_T:
            myprintf(level, "struct:\n");
            break;
        case FUNCTION:
            myprintf(level, "function:\n");
            myprintf(level, "name: %s\n", type->name);
            myprintf(level, "return type:\n");
            st_print_type(type->subtype, level+1);
            break;
        case CURVE_T:
            myprintf(level, "curve:");
            if (type->num_vars){
                printf("\n");
                myprintf(level+1, "num_vars: %d\n", type->num_vars);
                myprintf(level+1, "vars: ");
            }
            for (int i = 0; i < type->num_vars; i++) {
                printf("%s ", type->vars[i]);
            }
            myprintf(level, "\n");
            break;
        default:
            myprintf(level, "unknown type\n");
    }
}


void st_print_entry(st_entry *entry, int level) {
    if (entry->type->type != SYMBOL_TABLE){
        myprintf(level, "name: %s\n", entry->name);
        st_print_type(entry->type, level);
    }
    if (entry->subtable != NULL) {
        st_print_table(entry->subtable);
    }
}


void st_print_table(symbol_table *st) {
    myprintf(st->level-1, "Symbol table (level %d, %d entries):", st->level, st->filled);
    if (st->parameters) {
        printf(" (parameters)");
    }
    if (st->is_incomplete) {
        printf(" (incomplete)");
    }
    printf("\n");
    for (int i = 0; i < st->filled; i++) {
        st_print_entry(&st->entries[i], st->level);
        printf("\n");
    }
    myprintf(st->level-1, "Symbol table (level %d) end:\n", st->level);
}

void update_pos_info(position *pos, int row, int col) {
    pos->last_last_row = pos->last_row;
    pos->last_last_col = pos->last_col;
    pos->last_row = pos->row;
    pos->last_col = pos->col;
    pos->row = row;
    pos->col = col;
}


st_entry *find_in_one_table(symbol_table *st, char *name) {
    for (int i = 0; i < st->filled; i++)
    {
        if (st->entries[i].name && strcmp(st->entries[i].name,name)==0)
        {
            return &st->entries[i];
        }
    }
    return NULL;
}


st_entry *find_in_table(symbol_table *st, char *name) {
    while(st!=NULL){
        st_entry *entry = find_in_one_table(st,name);
        if (entry != NULL)
        {
            return entry;
        }
        // for (int i = 0; i < st->filled; i++)
        // {
        //     // printf("%s %s\n",st->entries[i].name,name);
        //     if (st->entries[i].name && strcmp(st->entries[i].name,name)==0)
        //     {
        //         return &st->entries[i];
        //     }
        // }
        st=st->parent;
    }
    return NULL;
}

st_entry *struct_ptr(st_entry *entry, symbol_table *st) {
    // find the declaration of the entry
    // symbol_table *st = global_table;
    return find_in_table(st,entry->type->name);
}

bool is_iterable(var_type *type) {
    return (type->type == ARRAY || type->type == PRIMITIVE && strcmp(type->name, "vector") == 0);
}

bool struct_type_defined(symbol_table *st, st_entry *entry) {
    // symbol_table *st = global_table;
    if (struct_ptr(entry,st)!=NULL)
    {
        return true;
    }
    return false;
}

int getsize(char * typename){


    int numtype = 16;
    for (int i=0; i< numtype; i++){

        if (strcmp(typename,datatype[i][0]) == 0){
            return datatype[i][1][0] - '0';
        }
    }
    return 0;
}

int is_convertible(var_type *type1, var_type *type2) {
    if (are_types_equal(type1,type2))
        return 0;
    else if (type1->type == CURVE_T && is_number(type2)){
        return 0;
    } else if (is_number(type1) && type2->type == CURVE_T){
        return 0;
    }
    if (type1->type != type2->type)
        return -1;
    if (type1->type == NOT_DEFINED)
        return -1;
    if (type1->type == PRIMITIVE){
        if (strcmp(type1->name, "vector") && strcmp(type2->name, "vector")){
            return 0;
        }
        int size1 = getsize(type1->name);
        int size2 = getsize(type2->name);
        if(size1 == size2){
            return 0;
        }
        else if (size1 > size2){
            return 2; // type2 get converted to type1
        }
        else {
            return 1; //  type1 get converted to type2
        }
    } else if (type1->type == POINTER) {
        return is_convertible(type1->subtype, type2->subtype);
    } else if (type1->type == ARRAY) {
        return type1->length == type2->length && is_convertible(type1->subtype, type2->subtype);
    } else {
        return -1;
    }
}

bool is_assignable(var_type *type1, var_type *type2){
    if (type1->type == NOT_DEFINED || type2->type == NOT_DEFINED)
        return false;
    if (is_convertible(type1,type2)==0 || is_convertible(type1,type2)==2)
    {
        return true;
    }
    return false;
}

var_type *get_type_of_var(symbol_table *st, char *name) {
    st_entry *entry = find_in_table(st,name);
    if(entry != NULL) {
        if (entry->type->type == FUNCTION)
            return entry->type->subtype;
        return entry->type;
    }
    var_type *type = malloc(sizeof(var_type));
    init_var_type(type);
    type->type = NOT_DEFINED;
    return type;
}

var_type *get_item_type(var_type *type){
    if(type->type = ARRAY) return type->subtype;
    return &type->args[0];
}

var_type *get_type_of_member(symbol_table *st, var_type *type, char *name) {
    st_entry *struct_ptr = find_in_table(st,type->name);
    if (struct_ptr==NULL) {
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    st_entry *desired = find_in_table(struct_ptr->subtable,name);
    if (desired==NULL) {
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    return desired->type;
}

bool is_function_matched(symbol_table* st, char* name, var_type* type_list, int arg_num){
    st_entry *function_ptr = find_in_table(st,name);
    if (function_ptr==NULL)
    {
        return false;
    }

    if (arg_num!=function_ptr->subtable->filled-1)
    {
        return false;
    }

    for (int i = 0; i < arg_num; i++)
    {
        if (!is_assignable(&type_list[i],function_ptr->subtable->entries[i].type))
        {
            return false;
        }
    }

    return true;
}

bool is_function_def_matched(symbol_table* st, char* name, var_type* type_list, int arg_num){
    st_entry *function_ptr = find_in_table(st,name);
    if (function_ptr==NULL) {
        return false;
    }
    if (arg_num!=function_ptr->subtable->filled-1) {
        return false;
    }
    for (int i = 0; i < arg_num; i++) {
        if (!are_types_equal(&type_list[i],function_ptr->subtable->entries[i].type)) {
            return false;
        }
    }

    return true;
}

bool is_int(var_type *type){
    return (
        type->type == PRIMITIVE && (
            strcmp(type->name, "int") == 0 ||
            strcmp(type->name, "int8") == 0 ||
            strcmp(type->name, "int16") == 0 ||
            strcmp(type->name, "int32") == 0 ||
            strcmp(type->name, "int64") == 0
        )
    );
}

bool is_real(var_type *type){
    return (
        type->type == PRIMITIVE && (
            strcmp(type->name, "real") == 0 ||
            strcmp(type->name, "real32") == 0 ||
            strcmp(type->name, "real64") == 0
        )
    );
}

bool is_number(var_type *type){
    return is_int(type) || is_real(type);
}

bool is_initializer_list_matched(symbol_table* st, var_type *type, var_type *list, int count){
    return true;
}

var_type *get_compatible_type_logical(var_type *type1, var_type *type2){
    int a = is_convertible(type1,type2);
    if (a==-1){
        yyerror("Incompatible Operand types");
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    if (a==0 || a==2){
        return type2;
    }
    return type1;
}

var_type *get_compatible_type_arithmetic(var_type *type1, var_type *type2){
    int a = is_convertible(type1,type2);
    if (a==-1){
        yyerror("Incompatible Operand types");
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    if (a==0 || a==2){
        return type2;
    }
    return type1;
}

var_type *get_compatible_type_comparison(var_type *type1, var_type *type2){
    int a = is_convertible(type1,type2);
    if (a==-1){
        yyerror("Incompatible Operand types");
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    if (a==0 || a==2){
        return type2;
    }
    return type1;
}

var_type *get_compatible_type_bitwise(var_type *type1, var_type *type2){
    int a = is_convertible(type1,type2);
    if (a==-1){
        yyerror("Incompatible Operand types");
        var_type *type = malloc(sizeof(var_type));
        init_var_type(type);
        type->type = NOT_DEFINED;
        return type;
    }
    if (a==0 || a==2){
        return type2;
    }
    return type1;
}

bool are_types_equal(var_type *type1, var_type* type2){
    if (type1 == type2)
        return true;
    if (!type1 || !type2) {
        return false;
    }
    if (type1->type != type2->type) {
        return false;
    }
    if (type1->type == NOT_DEFINED) {
        return false;
    }
    if (type1->type == CURVE_T) {
        return true;
    }
    if (type1->type == PRIMITIVE && strcmp(type1->name, type2->name) != 0) {
        return false;
    }
    else if (type1->type == ARRAY || type1->type == POINTER){
        if (type1->length != type2->length)
            return false;
        return are_types_equal(type1->subtype, type2->subtype);
    } else if (type1->type == STRUCT_T || type1->type == FUNCTION) {
        if (strcmp(type1->name, type2->name) != 0) {
            return false;
        }
    }

    return true;
}

bool check_ret_type(symbol_table *st, var_type *type){
    while (!st->parameters){
        st = st->parent;
    }
    for (int i=0; i<st->parent->filled; i++){
        if (st->parent->entries[i].subtable == st){
            if (is_assignable(st->parent->entries[i].type->subtype, type)){
                return true;
            } else {
                return false;
            }
        }
    }

    return false;
}
