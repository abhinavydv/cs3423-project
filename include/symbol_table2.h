#include <stdlib.h>
#include <stdio.h>

typedef struct symbol_table *SymbolTable ;


typedef struct state {
    int num_stars;
    int num_braks;
    int *brak_vals;
} state;

enum Type {
    STRUCT,
    FUNCTION,
    GLOBAL,
    SCOPEBLOCK // if, repeat or any other scope block
};

enum ID_Type {

    INT,
    REAL,
    CURVE_T,
    COMPLEX,
    VECTOR,
    MATRIX,
    ARRAY,
    POINTER
};

typedef struct datatype {

    enum ID_Type id_type;
    enum ID_Type return_type;
    size_t offset;
    char * dtname;

    struct datatype * subdatatype;

} * DataType;

typedef struct symbol_table_data{

    size_t ST_id;
    enum Type type;
    DataType datatype;
    char * name;

    SymbolTable Parameters; // for function and curve
    SymbolTable SubSymbolTable;

} *SymbolTableData;

struct symbol_table {

    SymbolTableData * SymbolTableDatalist;
    size_t nextp;
    size_t maxlistsize;
    struct symbol_table * ParentSymbolTable;

};