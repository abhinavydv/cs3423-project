
struct var_type;
struct st_entry;
struct symbol_table;


// Enum for type of variable
typedef enum {
    ARRAY,
    CURVE,
    FUNCTION,
    STRUCT,
    PRIMITIVE,
} Type;


struct var_type {
    Type type;              // type of variable
    char *name;             // name of type (e.g. "int", "real", "char", etc.)
    int length;             // length of array (e.g. 5 for "int[5]")
    int num_args;           // number of template arguments (e.g. 1 for "vector<int>")
    struct var_type *args;  // array of template arguments (e.g. "int" in "vector<int>")
    int num_vars;           // number of variables used in curve
    char **vars;            // array of variables used in curve
};


struct st_entry {
    char *name;                     // name of variable
    struct var_type *type;          // type of variable
    struct symbol_table *subtable;  // subtable for structs, functions and blocks
};


struct symbol_table {
    int size;                   // number of entries
    struct st_entry *entries;   // array of entries
};


typedef struct var_type var_type;
typedef struct st_entry st_entry;
typedef struct symbol_table symbol_table;
