- Symbol table entry
    - id
    - type
    - size (size of array types)
    - scope
    - table (pointer to symbol table for function types)

- type
    - type (array, curve, function, struct, primitive)
    - name (int, real, char, bool, void, etc.)
    - temp_args (template arguments if any)

- Symbol table
    - entries (linked list of symbol table entries)
    - parent (pointer to parent symbol table)
    - children (list of pointers to children symbol tables)
    - scope (scope of symbol table)
