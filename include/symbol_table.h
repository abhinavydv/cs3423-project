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
    PRIMITIVE,      // int, real, char, bool, vector, complex, etc.
    ARRAY,          // int a[<NUMBER>];
    CURVE_T,        // curve f(<variables>)
    FUNCTION,       // function
    STRUCT_T,       // struct
    POINTER,        // pointer to a type (e.g. int*)
    SYMBOL_TABLE,   // denotes a symbol table entry
    NOT_DEFINED,    // denotes that the variable was not declared
} Type;


// structs
struct var_type {
    Type type;          // type of variable
    char *name;         // name of type (e.g. "int", "real", "char", etc.)
    var_type *subtype;  // type of elements in array (e.g. "int" in "int[5]")
    int length;         // length if it is an array (e.g. 5 for "int[5]")
    int num_args;       // number of template arguments (e.g. 1 for "vector<int>")
    var_type *args;     // array of template arguments (e.g. "int" in "vector<int>")
    int num_vars;       // number of variables used in curve
    char **vars;        // array of variables used in curve
};


struct st_entry {
    char *name;             // name of variable
    var_type *type;         // type of variable
    int index;              // index of this entry in the symbol table
    symbol_table *subtable; // subtable for structs, functions and blocks
    symbol_table *parent;   // parent table in which this entry is present
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
    char *id;               // name of id
    int num_stars;          // number of stars in pointer
    int num_braks;          // number of brackets in array
    int *brak_vals;         // array of values in brackets
};


// a list of ids. Used in parser to pass the id_list and insert
struct id_list {
    id id;
    id_list *next;
};


struct state {
    char* text;                 // text being parsed
    var_type type;              // type of variable
    id_list *curr_id_list;      // current id list
    int count;                  // number of types in type_list
    var_type *type_list;        // list of types
    char *code;                 // code to be inserted for this non-terminal
    char **code_list;           // list of codes
    int code_count;             // number of codes in code_list
    bool has_assignargs;        // true if assignargs (eg x=2) is present
    bool is_arrow;              // true if arrow (eg x->y) is present
};


typedef struct {
    int row;
    int col;
    int last_row;
    int last_last_row;
    int last_col;
    int last_last_col;
} position;


typedef struct errors {
    char *msg;
    position pos;
    struct errors *next;
} errors;


// functions
symbol_table *st_create(int size, int level, bool parameters);
void st_insert_default_types(); // insert pre-defined types into symbol table (vector, complex)
void st_insert_default_functions(); // insert pre-defined functions into symbol table (print, read, sin, cos, etc.)
void st_insert(symbol_table *st, st_entry entry);
void st_insert_vars(symbol_table*, id_list*, var_type);
void st_insert_var(symbol_table*, id, var_type);
void st_insert_curve(symbol_table*, id, id_list*, int);
void st_insert_struct(symbol_table*, char *name, symbol_table*);
void st_insert_func(symbol_table*, char*, var_type, symbol_table*);
void init_var_type(var_type*);
void init_id(id*);
var_type *gen_type(id id, var_type type);
void st_print_type(var_type*, int);
void st_print_entry(st_entry*, int);
void st_print_table(symbol_table *);

bool struct_type_defined(symbol_table* st, st_entry *entry); // checks if struct is defined
bool is_iterable(var_type *type); // checks if type is iterable. true if it is an array or vector
st_entry *struct_ptr(st_entry *entry, symbol_table *st); //returns struct declaration entry
void myprintf(int level, char *format, ...);
int is_convertible(var_type *type1, var_type *type2);   // return 0 if same type, -1 if not convertible, return 1 if 1st to 2nd else return 2
bool is_assignable(var_type *type1, var_type *type2);   // return 0 if same type, -1 if not convertible, return 1 if 1st to 2nd else return 2
var_type *get_type_of_var(symbol_table *st, char *name);    // return pointer to variable type if found else return NULL
var_type *get_type_of_member(symbol_table *st, var_type *type, char *name);    // return pointer to variable type if found else return NULL
void update_pos_info(position *pos, int row, int col);
var_type *get_item_type(var_type *type); // return type of item in array or vector
bool is_number(var_type *type); // checks if type is number
bool number_comparable(var_type *type); // checks if type is number
bool is_int(var_type *type); // checks if type is number
st_entry *find_in_one_table(symbol_table *st, char *name);
st_entry *find_in_table(symbol_table *st, char *name); // return pointer to entry if found else return NULL

bool is_declared(symbol_table *st, char *name); // checks if variable is declared
bool is_function_matched(symbol_table*, char*, var_type*, int); // checks if function is matched
bool is_function_def_matched(symbol_table*, char*, var_type*, int); // checks if function is matched
var_type *get_obj_func_ret_type(symbol_table*, var_type *, char*, var_type*, int); // get the type of function call from object and functin name. Call yyerror and return NULL if not found
bool is_initializer_list_matched(symbol_table*, var_type *type, var_type *list, int count); // checks if initializer list is compatible with type
var_type *get_compatible_type_logical(var_type *type1, var_type *type2); // return compatible type of two types for logical operator. call yyerror if not compatible
var_type *get_compatible_type_arithmetic(var_type *type1, var_type *type2); // return compatible type of two types for arithmetic operator. call yyerror if not compatible
var_type *get_compatible_type_comparison(var_type *type1, var_type *type2); // return compatible type of two types for comparison operator. call yyerror if not compatible
var_type *get_compatible_type_bitwise(var_type *type1, var_type *type2); // return compatible type of two types for bitwise operator. call yyerror if not compatible
bool are_types_equal(var_type *type1, var_type *type2); // return true if types are compatible else return false
bool check_ret_type(symbol_table *st, var_type *type); // return true if return type is compatible else return false
bool is_printable(var_type *type); // return true if type is printable else return false
bool verify_temp_params(char *name, var_type *type); // return true if template parameters are valid else return false
void yyerror(char *);

char *format_string(char *format, ...);
char *increase_indent(char* code, int indents);

#endif
