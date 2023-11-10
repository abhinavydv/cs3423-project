#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

typedef struct var_type var_type;
typedef struct st_entry st_entry;
typedef struct symbol_table symbol_table;
typedef struct id id;
typedef struct id_list id_list;
typedef struct state state;


// Enum for type of variable
typedef enum {
    PRIMITIVE,
    ARRAY,
    CURVE_T,
    FUNCTION,
    STRUCT_T,
    POINTER,
    SYMBOL_TABLE
} Type;


// structs
struct var_type {
    Type type;              // type of variable
    char *name;             // name of type (e.g. "int", "real", "char", etc.)
    var_type *subtype;      // type of elements in array (e.g. "int" in "int[5]")
    int length;             // length if it is an array (e.g. 5 for "int[5]")
    int num_args;           // number of template arguments (e.g. 1 for "vector<int>")
    var_type *args;         // array of template arguments (e.g. "int" in "vector<int>")
    int num_vars;           // number of variables used in curve
    char **vars;            // array of variables used in curve
};


struct st_entry {
    char *name;             // name of variable
    var_type *type;         // type of variable
    symbol_table *subtable; // subtable for structs, functions and blocks
};


struct symbol_table {
    int size;               // number of entries
    int filled;             // number of entries filled
    int level;              // level of the scope
    bool parameters;        // true if this table stores parameters of a function
    bool is_incomplete;     // true if this table belongs to a function that is declared but not defined
    st_entry *entries;      // array of entries
    symbol_table *parent;   // parent table
};


struct id {
    char *id;
    int num_stars;
    int num_braks;
    int *brak_vals;
};


struct id_list {
    id id;
    id_list *next;
};


struct state {
    char* text;
    var_type type;
    id_list *curr_id_list;
    int count;
    var_type *type_list;
};


typedef struct {
    int row;
    int col;
    int last_row;
    int last_col;
} position;


// functions
symbol_table *st_create(int size, int level, bool parameters);
// void st_insert_default_types(); // insert pre-defined types into symbol table
void st_insert(symbol_table *st, st_entry entry);
void st_insert_vars(symbol_table*, id_list*, var_type);
void st_insert_var(symbol_table*, id, var_type);
void st_insert_curve(symbol_table*, id, id_list*, int);
void st_insert_struct(symbol_table*, char *name, symbol_table*);
void st_insert_func(symbol_table*, char*, var_type, symbol_table*);
void init_var_type(var_type*);
void init_id(id*);
void st_print_type(var_type*, int);
void st_print_entry(st_entry*, int);
void st_print_table(symbol_table *);

bool struct_type_defined(st_entry *entry); // checks if struct is defined
bool is_iterable(var_type *type); // checks if type is iterable
st_entry *struct_ptr(); //returns struct declaration entry
void myprintf(int level, char *format, ...);
int is_convertible(var_type *type1, var_type *type2);   // return 0 if same type, -1 if not convertible, return 1 if 1st to 2nd else return 2
bool is_assignable(var_type *type1, var_type *type2);   // return 0 if same type, -1 if not convertible, return 1 if 1st to 2nd else return 2
var_type *get_type_of_var(symbol_table *st, char *name);    // return pointer to variable type if found else return NULL
var_type *get_type_of_member(symbol_table *st, var_type *type, char *name);    // return pointer to variable type if found else return NULL
void update_pos_info(position *pos, int row, int col);
var_type *get_item_type(var_type *type); // return type of item in array or vector
bool is_number(var_type *type); // checks if type is number
bool is_int(var_type *type); // checks if type is number

// return 0 if matched
// return 1 if length problem
// return n+1 if nth argument has wrong type
int is_function_matched(symbol_table*, char*, var_type*, int); // checks if function is matched
int is_object_function_matched(symbol_table*, var_type *, char*, var_type*, int); // checks if object function is matched
bool is_initializer_list_matched(symbol_table*, var_type *type, var_type *list, int count); // checks if initializer list is matched

#endif
