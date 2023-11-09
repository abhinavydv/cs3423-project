#include "symbol_table.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


void myprintf(int level, char *format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    vprintf(format, args);
    va_end(args);
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
    st->entries = malloc(sizeof(st_entry) * size);
    st->parent = NULL;
    return st;
}


void st_insert(symbol_table *st, st_entry entry) {
    if (st->filled == st->size) {
        st->size *= 2;
        st->entries = realloc(st->entries, sizeof(st_entry) * st->size);
    }
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


void st_insert_var(symbol_table *st, id id, var_type type) {
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
    entry.type->type = STRUCT_T;
    entry.subtable = subtable;
    st_insert(st, entry);
}


void st_insert_curve(symbol_table *st, char *name, id_list *list, int count){
    st_entry entry;
    entry.name = strdup(name);
    entry.type = malloc(sizeof(var_type));
    init_var_type(entry.type);
    entry.type->type = CURVE_T;
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
                    myprintf(level, ">>>\n");
                    st_print_type(&type->args[i], level+1);
                    myprintf(level, "<<<\n");
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
            myprintf(level, "type:\n");
            st_print_type(type->subtype, level+1);
            break;
        case CURVE_T:
            myprintf(level, "curve:");
            if (type->num_vars){
                myprintf(level, "\nnum_vars: %d\n", type->num_vars);
                myprintf(level, "vars: ");
            }
            for (int i = 0; i < type->num_vars; i++) {
                myprintf(level, "%s ", type->vars[i]);
            }
            myprintf(level, "\n");
            break;
        default:
            myprintf(level, "unknown type\n");
    }
}


void st_print_entry(st_entry *entry, int level) {
    myprintf(level, "name: %s\n", entry->name);
    st_print_type(entry->type, level);
    if (entry->subtable != NULL) {
        st_print_table(entry->subtable);
    }
}


void st_print_table(symbol_table *st) {
    myprintf(st->level, "Symbol table (level %d, %d entries):\n", st->level, st->filled);
    for (int i = 0; i < st->filled; i++) {
        st_print_entry(&st->entries[i], st->level);
        printf("\n");
    }
    myprintf(st->level, "Symbol table (level %d) end:\n", st->level);
}


bool struct_type_defined(st_entry *entry) {
    // find the declaration
    // symbol_table *st = global_table;
    symbol_table *st;
    
}