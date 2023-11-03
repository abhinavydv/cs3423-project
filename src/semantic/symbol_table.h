#include <stdlib.h>
#include <stdio.h>

enum Type {
    STRUCT,
    FUNCTION,
    IMPORT,
    GLOBAL,
    SCOPEBLOCK // if, repeat or any other scope block
};

enum ID_Type {

    INT,
    REAL,
    CURVE,
    COMPLEX,
    VECTOR,
    MATRIX,
    ARRAY,
    POINTER
};

typedef struct datatype {

    ID_Type id_type;
    ID_Type return_type;
    size_t offset;
    char * dtname;

    struct datatype * subdatatype;

} * DataType;

typedef struct symbol_table_data{

    size_t ST_id;
    Type type;
    DataType datatype;
    char * name;

    SymbolTable Parameters; // for function and curve
    SymbolTable SubSymbolTable;

} *SymbolTableData;

typedef struct symbol_table {

    SymbolTableData * SymbolTableDatalist;
    size_t nextp;
    size_t maxlistsize;
    struct symbol_table * ParentSymbolTable;

} *SymbolTable ;