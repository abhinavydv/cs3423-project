%{
    #include "symbol_table.h"
    #define YYSTYPE state

    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #include <string.h>


    // variables
    extern FILE  *yyin, *yyout, *parsed_file, *cpp_file;
    char *input_file;
    position pos_info = {0};   // used for error reporting
    symbol_table *global_table;
    symbol_table *curr_table;
    st_entry *func_def_entry;
    state yylval;
    var_type curr_type;
    bool create_cpp_file = false, print_spaces = false;

    errors *err = NULL;
    errors *prev_err = NULL;

    // functions
    int yylex();
    void yyerror(char * msg);
    void print_errs();

    void label(char * msg){
        fprintf(parsed_file," /* %s */ ",msg);
    }

    void add_headers(FILE *file){
        fprintf(
            file,
            "#include <iostream>\n"
            "#include <expr_base.hpp>\n\n"
        );
    }
%}

%token DATA_TYPE IDENTIFIER STRING IN DOTS
%token CHAR RETURN INTEGER CURVE DOLLAR_ID
%token FOR STRUCT AUG_ASSIGN DIFF
%token VOID ARROW COMPARE AND OR SHIFT DECREMENT INCREMENT
%token REAL IF ELSE DOT PRINT IMAG
%token REPEAT UNTIL BREAK CONTINUE IMPORT TRUE FALSE FUNC

%%
start           :  program  {
                    if (err == NULL){
                        add_headers(cpp_file);
                        fprintf(cpp_file, "%s", $1.code);
                    }
                }
                |  error ';' {yyerror("Syntax error"); print_errs(); exit(1);}

// the program
program         :  global_decl program  {
                    $$.code = format_string("%s%s", $1.code, $2.code);
                    free($1.code);
                    free($2.code);
                }
                |  {$$.code = format_string("");}

// all global statements allowed
global_decl     :  decl_only ';'    {
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  function {
                    func_def_entry = NULL;
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  FUNC funcDef ';' {
                    curr_table->is_incomplete = true;
                    curr_table = curr_table->parent;    // exit the parameter table
                    func_def_entry = NULL;
                    $$.code = format_string("\n%s;\n\n", $2.code);
                    free($2.code);
                }
                |  struct   {
                    $$.code = format_string("\n%s;\n\n", $1.code);
                    free($1.code);
                }
                |  import   {
                    $$.code = format_string("//\n");
                    free($1.code);
                }
                |  ';'    {
                    $$.code = format_string(";\n");
                }

// struct defs
struct          :  STRUCT IDENTIFIER {
                    label("Struct def");
                    symbol_table *new_table = st_create(8, curr_table->level+1, false);
                    st_insert_struct(curr_table, $2.text, new_table);
                    new_table->parent = curr_table;
                    curr_table = new_table;
                } '{' declarations '}' {
                    curr_table = curr_table->parent;

                    $$.code = format_string("\nstruct %s {\n%s};\n\n", $2.text, increase_indent($5.code, 1));
                    free($5.code);
                }

// function defs
function        :  FUNC funcDef  '{' {
                    // is_incomplete should be true otherwise throw error
                    if (curr_table->is_incomplete){
                        curr_table->is_incomplete = false;
                        symbol_table *new_table = st_create(8, curr_table->level+1, false);
                        st_entry entry;
                        entry.name = 0;
                        entry.type = malloc(sizeof(var_type));
                        init_var_type(entry.type);
                        entry.type->type = SYMBOL_TABLE;
                        entry.subtable = new_table;
                        new_table->parent = curr_table;
                        st_insert(curr_table, entry);
                        curr_table = new_table;
                    }
                    else {
                        $$.error = true;
                        yyerror("Function Redefined!!");
                    }
                } statements '}'    {
                    curr_table = curr_table->parent;
                    if (!$$.error){
                        curr_table = curr_table->parent;
                    }
                    char *icode = increase_indent($5.code, 1);
                    $$.code = format_string("%s{\n%s}\n\n", $2.code, icode);
                    free($2.code);
                    free($5.code);
                    free(icode);
                }

// function header defs
funcDef         :  starred_rettype IDENTIFIER {
                    // check if id and type exist in table if id match but return type do not return error
                    // if both match do not do anything and check parameters type and number
                    // if not matches proceed with new entry

                    func_def_entry = find_in_table(curr_table, $2.text);
                    if (func_def_entry == NULL){
                        symbol_table *new_table = st_create(8, curr_table->level+1, false);
                        st_insert_func(curr_table, $2.text, $1.type, new_table);
                        new_table->parent = curr_table;
                        curr_table = new_table;
                        curr_table->is_incomplete = true;
                        curr_table->parameters = true;
                    } else if (!are_types_equal(func_def_entry->type->subtype, &$1.type)){
                        yyerror("Function Redefined with different type!!");
                    } else {
                        curr_table = func_def_entry->subtable;
                    }
                } '(' params ')' {
                    label("Function def");
                    if (func_def_entry != NULL){
                        if (!is_function_matched(curr_table, func_def_entry->name, $5.type_list, $5.count)){
                            yyerror("Function definition does not match declaration");
                        }
                        func_def_entry = NULL;
                    }

                    $$.code = format_string("%s %s(%s)", $1.code, $2.text, $5.code);
                    free($1.code);
                    free($5.code);
                }

starred_rettype :  starred_rettype '*' {
                    $$.type.type = POINTER;
                    $$.type.subtype = malloc(sizeof(var_type));
                    *$$.type.subtype = $1.type;
                    $$.code = format_string("%s*", $1.code);
                    free($1.code);
                }
                |  ret_type {
                    $$ = $1;
                }

ret_type        :  type     {
                    $$ = $1;
                }
                |  CURVE    {
                    init_var_type(&$$.type);
                    $$.type.type = CURVE_T;
                    $$.code = format_string("Expression");
                }
                |  VOID     {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
                    $$.code = format_string("void");
                }

// function parameters
params          :  param_list   {
                    $$ = $1;
                }
                |   {
                    $$.type_list = NULL;
                    $$.count = 0;
                    $$.code = format_string("");
                }
param_list      :  type_defs    {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;
                    $$.code = format_string("%s", $1.code);
                    free($1.code);
                }
                |  param_list ',' type_defs {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count++;
                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }

// type definitions for function parameters
type_defs       :  type decl_id {
                    $$.type = $1.type;
                    if (func_def_entry == NULL){
                        st_insert_var(curr_table, $2.curr_id_list->id, $1.type);
                    }
                    $$.code = format_string("%s %s", $1.code, $2.code);
                    free($1.code);
                    free($2.code);
                }
                |  CURVE decl_id    {
                    init_var_type(&$$.type);
                    $$.type.type = CURVE_T;
                    if (func_def_entry == NULL){
                        st_insert_curve(curr_table, $2.curr_id_list->id, NULL, 0);
                    }
                    $$.code = format_string("Expression %s", $2.code);
                    free($2.code);
                }

type            :  DATA_TYPE temp_params {
                    init_var_type(&$$.type);
                    $$.type.num_args = $2.type.num_args;
                    $$.type.args = $2.type.args;

                    if ($2.type.num_args > 0 && !verify_temp_params($1.text, &$2.type)){
                        yyerror("Invalid template parameters");
                    }
                    // if (strcmp($1.text, "complex") == 0){
                    //     $$.type.name = "Complex";
                    // } else {
                    //     $$.type.name = $1.text;
                    // }

                    $$.type.name = $1.text;
                    $$.code = format_string("%s%s", lg_type_to_cpp_type($1.text), $2.code);
                    free($2.code);
                }
                |  IDENTIFIER   {
                    init_var_type(&$$.type);
                    if (find_in_table(curr_table, $1.text) == NULL){
                        yyerror(format_string("Type '%s' not defined", $1.text));
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type.name = $1.text;
                    }
                    $$.code = format_string("%s", $1.text);
                }

// template paramaters
temp_params     :  '<' typelist '>' {
                    $$.type.num_args = $2.type.num_args;
                    $$.type.args = $2.type.args;
                    $$.code = format_string("<%s>", $2.code);
                    free($2.code);
                }
                |   {
                    $$.type.num_args = 0;
                    $$.type.args = NULL;
                    $$.code = format_string("");
                }

typelist        :  starred_rettype {
                    $$.type.num_args = 1;
                    $$.type.args = (var_type *)malloc(sizeof(var_type));
                    $$.type.args[0] = $1.type;
                    $$.code = $1.code;
                }
                |  starred_rettype ',' typelist    {
                    $$.type.num_args = $3.type.num_args + 1;
                    $$.type.args = (var_type *)malloc($$.type.num_args * sizeof(var_type));
                    $$.type.args[0] = $1.type;
                    for (int i = 0; i < $3.type.num_args; i++){
                        $$.type.args[i+1] = $3.type.args[i];
                    }
                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }

// block of statements
block           : '{' {
                    symbol_table *new_table = st_create(8, curr_table->level+1, false);
                    st_entry entry;
                    entry.name = 0;
                    entry.type = malloc(sizeof(var_type));
                    init_var_type(entry.type);
                    entry.type->type = SYMBOL_TABLE;
                    entry.subtable = new_table;
                    new_table->parent = curr_table;
                    st_insert(curr_table, entry);
                    curr_table = new_table;
                } statements '}'    {
                    curr_table = curr_table->parent;
                    $$.code = format_string("{\n%s}", increase_indent($3.code, 1));
                }

statements      :  statement statements {
                    $$.code = format_string("%s%s", $1.code, $2.code);
                    free($1.code);
                    free($2.code);
                }
                |   {
                    $$.code = format_string("");
                }

// Following are all the statements allowed
statement       :  decl_assgn ';'   {
                    label("Declaration");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  multi_assign ';' {
                    label("Assignment");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  augAssign ';'    {
                    label("Augmented Assignment");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  ret              {
                    label("Return");
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  conditional  {
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  loop      {
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  forLoop  {
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  print    {
                    $$.code = format_string("%s\n", $1.code);
                    free($1.code);
                }
                |  call ';'         {
                    label("Function Call");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  obj_call ';'     {
                    label("Object Function Call");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  differentiate ';' {
                    label("Differentiate");
                    $$.code = format_string("%s;\n", $1.code);
                    free($1.code);
                }
                |  block        {
                    $$.code = $1.code;
                }
                |  BREAK ';'        {
                    label("Break");
                    $$.code = format_string("%s;\n", $1.text);
                }
                |  CONTINUE ';'     {
                    label("Continue");
                    $$.code = format_string("%s;\n", $1.text);
                }
                |  ';'            {
                    $$.code = format_string(";\n");
                }

// import statements
import          :  IMPORT STRING ';'    {
                    $$.code = format_string("//\n");
                }

// list of declarations (for structs)
declarations    :  decl_only ';' {label("Declaration");} declarations   {
                    $$.code = format_string("%s;\n%s", $1.code, $4.code);
                    free($1.code);
                    free($4.code);
                }
                |   {
                    $$.code = format_string("");
                }

// declarations only. No assignment (for global declration)
decl_only       :  type decl_id_list    {
                    st_insert_vars(curr_table, $2.curr_id_list, $1.type);
                    $$.code = format_string("%s %s", $1.code, $2.code);
                    free($1.code);
                    free($2.code);
                }
                |  CURVE curve_decl_list    {
                    $$.code = format_string("Expression %s", $2.code);
                    free($2.code);
                }

// list of curve identifiers
curve_decl_list :  curve_decl_list ',' curve_decl   {
                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  curve_decl   {
                    $$.code = $1.code;
                }

// identifier for a curve
curve_decl      :  IDENTIFIER '(' idlist ')'    {
                    id new_id = {$1.text, 0, 0, 0};
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    $$.curr_id_list->next = 0;
                    $$.curr_id_list->id = new_id;
                    $$.count = 1;
                    st_insert_curve(curr_table, new_id, $3.curr_id_list, $3.count);

                    $$.code = format_string("%s", $1.text);
                    free($3.code);
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;
                    var_type type;
                    init_var_type(&type);
                    type.type = CURVE_T;
                    st_insert_vars(curr_table, $1.curr_id_list, type);
                    $$.code = $1.code;
                }

// list of declaration identifiers.
decl_id_list    :  decl_id ',' decl_id_list {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;
                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.code = $1.code;
                }

// declaration identifier with star
decl_id         :  '*' decl_id  {
                    $$ = $2;
                    $$.curr_id_list->id.num_stars++;
                    $$.code = format_string("*%s", $2.code);
                    free($2.code);
                }
                |  decl_id2     {
                    $$ = $1;
                }

// declaration identifier with square brackets
decl_id2        :  decl_id2 '[' INTEGER ']' {
                    $$ = $1;
                    $$.curr_id_list->id.num_braks++;
                    if ($$.curr_id_list->id.num_braks == 1){
                        $$.curr_id_list->id.brak_vals = (int *)malloc(sizeof(int));
                    }
                    else{
                        $$.curr_id_list->id.brak_vals = (int *)realloc($$.curr_id_list->id.brak_vals, $$.curr_id_list->id.num_braks * sizeof(int));
                    }
                    $$.curr_id_list->id.brak_vals[$$.curr_id_list->id.num_braks - 1] = atoi($3.text);

                    $$.code = format_string("%s[%s]", $1.code, $3.text);
                    free($1.code);
                }
                |  IDENTIFIER   {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    $$.curr_id_list->next = 0;
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;

                    $$.code = format_string("%s", $1.text);
                }

// Declaration with/without assignment
decl_assgn      :  type {curr_type = $1.type;} assignList  {
                    st_insert_vars(curr_table, $3.curr_id_list, $1.type);

                    $$.code = format_string("%s %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  CURVE curveAssignList    {
                    $$.code = format_string("Expression %s", $2.code);
                    free($2.code);
                }

// list of IDs/assignments of curves for declarations
curveAssignList :  curveAssignList ',' curve_assign  {
                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  curve_assign  {
                    $$.code = $1.code;
                }

// ID/Assignment for a curve
curve_assign    :  curve_decl '=' rhs   {
                    var_type type;
                    init_var_type(&type);
                    type.type = CURVE_T;
                    var_type *new_type = gen_type($1.curr_id_list->id, type);
                    if (!is_assignable(new_type, &$3.type)){
                        yyerror("Invalid assignment");
                    }

                    $$.code = format_string("%s = %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  curve_decl   {
                    $$.code = $1.code;
                }

// list of IDs/assignments for declarations
assignList      :  assign_decl ',' assignList   {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;

                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  assign_decl  {
                    $$.curr_id_list = $1.curr_id_list;

                    $$.code = $1.code;
                }
                |  decl_id ',' assignList   {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;

                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;

                    $$.code = $1.code;
                }

// ID/Assignment for a declaration
assign_decl     :  decl_id '=' rhs  {
                    if (!is_assignable(gen_type($1.curr_id_list->id, curr_type), &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.curr_id_list = $1.curr_id_list;

                    $$.code = format_string("%s = %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  decl_id '=' '{' initializerList '}'  {
                    if (!is_initializer_list_matched(curr_table, &$1.type, $4.type_list, $4.count)){
                        yyerror("Invalid assignment");
                    }
                    $$.curr_id_list = $1.curr_id_list;

                    $$.code = format_string("%s = {%s}", $1.code, $4.code);
                    free($1.code);
                    free($4.code);
                }

// Assignment
assign          :  lhs '=' rhs  {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.type = $3.type;

                    $$.code = format_string("%s = %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  lhs '=' '{' initializerList '}'  {
                    if (!is_initializer_list_matched(curr_table, &$1.type, $4.type_list, $4.count)){
                        yyerror("Invalid assignment");
                    }

                    $$.code = format_string("%s = {%s}", $1.code, $4.code);
                    free($1.code);
                    free($4.code);
                }

// Augmented Assignment
augAssign       :  lhs AUG_ASSIGN rhs   {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }

                    $$.code = format_string("%s %s %s", $1.code, $2.text, $3.code);
                    free($1.code);
                    free($3.code);
                }

// Initializer List like in C/Cpp, i.e., {1,2,3}
initializerList :  initializerList ',' rhs  {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count = $1.count + 1;

                    $$.code = format_string("%s, %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  rhs  {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;

                    $$.code = $1.code;
                }

// Assign a rhs to multiple variables;
multi_assign    :  lhs '=' multi_assign {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.type = $3.type;

                    $$.code = format_string("%s = %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  assign   {
                    $$.type = $1.type;

                    $$.code = $1.code;
                }

// list of identifiers
idlist          :  IDENTIFIER   {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;
                    $$.count = 1;

                    $$.code = format_string("\"%s\"", $1.text);
                }
                |  IDENTIFIER ',' idlist    {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;
                    $$.curr_id_list->next = $3.curr_id_list;
                    $$.count = 1 + $3.count;

                    $$.code = format_string("\"%s\", %s", $1.text, $3.code);
                    free($3.code);
                }

// LHS of an assignment
lhs             :  name {
                    $$ = $1;
                }

// Logical Operators
rhs             :  rhs OR and  {
                    $$.type = *get_compatible_type_logical(&$1.type, &$3.type);

                    $$.code = format_string("%s %s %s", $1.code, $2.text, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  and  {
                    $$ = $1;
                }

and             :  and AND comparison  {
                    $$.type = *get_compatible_type_logical(&$1.type, &$3.type);

                    $$.code = format_string("%s %s %s", $1.code, $2.text, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  comparison  {
                    $$ = $1;
                }

// Comparison Operators
comparison     :  comparison compare_op plus  {
                    $$.type = *get_compatible_type_comparison(&$1.type, &$3.type);

                    $$.code = format_string("%s %s %s", $1.code, $2.code, $3.code);
                    free($1.code);
                    free($2.code);
                    free($3.code);
                }
                |  plus   {
                    $$ = $1;
                }

compare_op      :  '<'  {
                    $$.code = format_string("<");
                }
                |  '>'  {
                    $$.code = format_string(">");
                }
                |  COMPARE  {
                    $$.code = format_string("%s", $1.text);
                }

// Arithmetic Operators
plus            :  plus '+' product  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);

                    $$.code = format_string("%s + %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  plus '-' product  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);

                    $$.code = format_string("%s - %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  product  {
                    $$ = $1;
                }

product         :  product '*' mod  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);

                    $$.code = format_string("%s * %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  mod           {
                    $$ = $1;
                }

mod             :  mod '%' division  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);

                    $$.code = format_string("%s %% %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  division   {
                    $$ = $1;
                }

division        :  division '/' bit_or  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);

                    $$.code = format_string("%s / %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  bit_or   {
                    $$ = $1;
                }

// Bitwise Operators
bit_or          :  bit_or '|' bit_and   {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);

                    $$.code = format_string("%s | %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  bit_and  {
                    $$ = $1;
                }

bit_and         :  bit_and '&' shift    {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);

                    $$.code = format_string("%s & %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  shift    {
                    $$ = $1;
                }

shift           :  shift SHIFT power    {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);

                    $$.code = format_string("%s %s %s", $1.code, $2.text, $3.code);
                    free($1.code);
                    free($2.code);
                }
                |  power    {
                    $$ = $1;
                }

// Power Operator
power           :  power '^' unary_op   {
                    if (!is_number(&$3.type)){
                        yyerror("Power must have int or real type");
                    }
                    if (!is_number(&$1.type) && $1.type.type != CURVE_T){
                        yyerror("base must have int, real or curve type");
                    }
                    $$ = $1;

                    $$.code = format_string("%s ^ %s", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  unary_op   {
                    $$ = $1;
                }

unary_op        :  unary_op_only    {
                    $$ = $1;
                }
                |  final    {
                    $$ = $1;
                }

// Unary Operators
unary_op_only   :  '~' final    {
                    if (!is_int(&$2.type)){
                        yyerror("Bitwise not must have int type");
                    }
                    $$ = $2;

                    $$.code = format_string("~%s", $2.code);
                    free($2.code);
                }
                |  '&' name  {
                    if ($2.type.type == NOT_DEFINED){
                        $$.type = $2.type;
                    } else {
                        $$.type.type = POINTER;
                        $$.type.subtype = malloc(sizeof(var_type));
                        *$$.type.subtype = $2.type;
                    }

                    $$.code = format_string("&%s", $2.code);
                    free($2.code);
                }
                |  '-' final    {
                    if (!is_number(&$2.type) && $2.type.type != CURVE_T){
                        yyerror("Unary minus must have int or real or curve type");
                    }
                    $$ = $2;

                    $$.code = format_string("-%s", $2.code);
                    free($2.code);
                }
                // TODO: Figure out starred expressions
                /* |  '*' '(' rhs ')' */
                |  '!' final    {
                    if (!is_number(&$2.type) && ($2.type.type == PRIMITIVE && strcmp($2.type.name, "bool")) != 0){
                        yyerror("Not must have int or real type");
                    }
                    $$ = $2;

                    $$.code = format_string("!%s", $2.code);
                    free($2.code);
                }
                |  final '!'    {
                    if (!is_int(&$1.type)){
                        yyerror("Factorial must have int type");
                    }
                    $$ = $1;

                    $$.code = format_string("factorial(%s)", $1.code);
                    free($1.code);
                }
                |  INCREMENT name   {
                    if (!is_number(&$2.type)){
                        yyerror("Increment must have int or real type");
                    }
                    $$ = $2;

                    $$.code = format_string("%s%s", $1.text, $2.code);
                    free($2.code);
                }
                |  name INCREMENT   {
                    if (!is_number(&$1.type)){
                        yyerror("Increment must have int or real type");
                    }
                    $$ = $1;

                    $$.code = format_string("%s%s", $1.code, $2.text);
                    free($1.code);
                }
                |  DECREMENT name   {
                    if (!is_number(&$2.type)){
                        yyerror("Decrement must have int or real type");
                    }
                    $$ = $2;

                    $$.code = format_string("%s%s", $1.text, $2.code);
                    free($2.code);
                }
                |  name DECREMENT   {
                    if (!is_number(&$1.type)){
                        yyerror("Decrement must have int or real type");
                    }
                    $$ = $1;

                    $$.code = format_string("%s%s", $1.code, $2.text);
                    free($1.code);
                }

final           :  value    {
                    $$ = $1;
                }
                |  '(' rhs ')'  {
                    $$ = $2;
                    $$.code = format_string("(%s)", $2.code);
                    free($2.code);
                }

// Values: Numbers, Strings, Booleans, Identifiers, Calls, Object Calls, Differentiate
// i.e. everything without an operator
value           :  number   {
                    $$ = $1;
                }
                |  STRING    {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "string";

                    $$.code = format_string("%s", $1.text);
                }
                |  CHAR     {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "char";

                    $$.code = format_string("%s", $1.text);
                }
                |  TRUE     {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "bool";

                    $$.code = format_string("%s", $1.text);
                }
                |  FALSE    {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "bool";

                    $$.code = format_string("%s", $1.text);
                }
                |  name {
                    $$ = $1;
                }
                |  call {
                    $$ = $1;
                }
                |  obj_call {
                    $$ = $1;
                }
                |  differentiate    {
                    $$ = $1;
                }
                |  DOLLAR_ID    {
                    init_var_type(&$$.type);
                    $$.type.type = CURVE_T;

                    $$.code = format_string("Expression(\"%s\")", $1.text+1);
                }

// Numbers: Real and Integer
number          :  REAL    {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "double";

                    $$.code = format_string("%s", $1.text);
                }
                |  INTEGER  {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "int";

                    $$.code = format_string("%s", $1.text);
                }
                |  IMAG {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "complex";
                    $1.text[strlen($1.text)-1] = '\0';
                    $$.code = format_string("Complex(0, %s)", $1.text);
                }

print           :  PRINT '(' arglist ')' ';'   {
                    if ($3.has_assignargs){
                        yyerror("Print calls cannot contain argument assignments");
                    }
                    if ($3.count == 0){
                        yyerror("Print call must have at least one argument");
                    }
                    for (int i=0; i<$3.count; i++){
                        if (!is_printable(&$3.type_list[i])){
                            yyerror("Print call must have printable arguments");
                        }
                    }
                    $$.code = format_string("cout");
                    char *tmp;
                    for (int i=0; i<$3.code_count; i++){
                        tmp = $$.code;
                        $$.code = format_string("%s << (%s)", $$.code, $3.code_list[i]);
                        free(tmp);
                    }
                    tmp = $$.code;
                    $$.code = format_string("%s;", $$.code);
                    free(tmp);
                    free($3.code);
                }

// Return Statement
ret             :  RETURN rhs ';'   {
                    if (!check_ret_type(curr_table, &$2.type)){
                        yyerror("Return type does not match function definition");
                    }
                    $$ = $2;

                    $$.code = format_string("return %s;", $2.code);
                    free($2.code);
                }
                |  RETURN ';'   {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "void";

                    $$.code = format_string("return;");
                }

// Function Call
call            :  IDENTIFIER '(' arglist ')'   {
                    $$.type = *get_type_of_var(curr_table, $1.text);
                    if ($$.type.type == NOT_DEFINED){
                        yyerror("Function not defined");
                    }
                    st_entry *entry = find_in_table(curr_table, $1.text);
                    if (entry->type->type == FUNCTION){
                        if ($3.has_assignargs){
                            yyerror("normal function calls cannot contain argument assignments");
                        }
                        if (!is_function_matched(curr_table, $1.text, $3.type_list, $3.count))
                            yyerror("Function call does not match definition");
                    } else if (entry->type->type == CURVE_T){
                        if (!$3.has_assignargs) {
                            if ($3.code_count == 0){
                                yyerror("Curve call must have at least one argument");
                            } else {
                                if ($3.code_count > $$.type.num_vars){
                                    yyerror("Too many arguments for curve call");
                                } else {
                                    char *res = format_string("{\"%s\", %s}", $$.type.vars[0], $3.code_list[0]);
                                    char *tmp;
                                    for (int i=1; i<$3.code_count; i++){
                                        tmp = res;
                                        res = format_string("%s, {\"%s\", %s}", res, $$.type.vars[i], $3.code_list[i]);
                                        free(tmp);
                                    }
                                    tmp = res;
                                    res = format_string("{%s}", tmp);
                                    free(tmp);
                                    free($3.code);
                                    $3.code = res;
                                }
                            }
                        }
                    } else {
                        yyerror("Function call must be a function");
                    }

                    $$.code = format_string("%s(%s)", $1.text, $3.code);
                    free($3.code);
                }

// Function Call with object
obj_call        :  name membership IDENTIFIER '(' arglist ')'   {
                    if ($1.type.type == NOT_DEFINED){
                        $$.type.type = NOT_DEFINED;
                    } else {
                        if ($2.is_arrow && $1.type.type != POINTER){
                            $$.type.type = NOT_DEFINED;
                            yyerror("Arrow expression must be a pointer");
                        } else {
                            $$.type = *get_type_of_member(curr_table, ($2.is_arrow ? $1.type.subtype : &$1.type), $3.text);
                            if ($$.type.type == NOT_DEFINED){
                                yyerror(format_string("Member '%s' of type '%s' not defined", $3.text, ($2.is_arrow ? $1.type.subtype->name : $1.type.name)));
                            } else if ($$.type.type == FUNCTION){
                                if ($5.has_assignargs){
                                    yyerror("normal function calls cannot contain argument assignments");
                                }
                                $$.type = *get_obj_func_ret_type(curr_table, ($2.is_arrow ? $1.type.subtype : &$1.type), $3.text, $5.type_list, $5.count);
                            } else if ($$.type.type == CURVE) {
                                if (!$5.has_assignargs) {
                                    if ($5.code_count == 0){
                                        yyerror("Curve call must have at least one argument");
                                    } else {
                                        if ($5.code_count > $$.type.num_vars){
                                            yyerror("Too many arguments for curve call");
                                        } else {
                                            char *res = format_string("{\"%s\", %s}", $$.type.vars[0], $5.code_list[0]);
                                            char *tmp;
                                            for (int i=1; i<$5.code_count; i++){
                                                tmp = res;
                                                res = format_string("%s, {\"%s\", %s}", res, $$.type.vars[i], $5.code_list[i]);
                                                free(tmp);
                                            }
                                            tmp = res;
                                            res = format_string("{%s}", tmp);
                                            free(tmp);
                                            free($5.code);
                                            $5.code = res;
                                        }
                                    }
                                }
                            } else {
                                yyerror(format_string("Member '%s' of type '%s' is not a function", $3.text, $1.type.subtype->name));
                            }
                            // is_object_function_matched(curr_table, $1.type.subtype, $3.text, $5.type_list, $5.count);
                        }
                    }

                    $$.code = format_string("%s%s%s(%s)", $1.code, $2.code, $3.text, $5.code);
                    free($1.code);
                    free($2.code);
                    free($5.code);
                }

membership      :  ARROW    {
                    $$.is_arrow = true;
                    $$.code = format_string("->");
                }
                |  DOT    {
                    $$.is_arrow = false;
                    $$.code = format_string(".");
                }

// List of arguments for a function call
arglist         :  argOnlyList  {
                    // printf("(%d, %d): %s\n", pos_info.row, pos_info.col, $1.code);
                    // for (int i=0; i<$1.code_count; i++){
                    //     printf("%s\n", $1.code_list[i]);
                    // }
                    $$.type_list = $1.type_list;
                    $$.count = $1.count;

                    $$.code_list = $1.code_list;
                    $$.code_count = $1.code_count;

                    $$.code = $1.code;
                }
                |  assign_arg_list  {
                    $$.count = 0;
                    $$.code_count = 0;
                    $$.has_assignargs = true;

                    $$.code = format_string("{%s}", $1.code);
                    free($1.code);
                }
                |   {
                    $$.count = 0;
                    $$.code_count = 0;

                    $$.code = format_string("");
                }

argOnlyList     :  rhs  {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;

                    $$.code_list = (char **)malloc(sizeof(char *));
                    $$.code_list[0] = $1.code;
                    $$.code_count = 1;

                    $$.code = $1.code;
                }
                |  argOnlyList ',' rhs  {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count = $1.count + 1;

                    $$.code_list = realloc($1.code_list, ($1.code_count + 1) * sizeof(char *));
                    $$.code_list[$1.code_count] = $3.code;
                    $$.code_count = $1.code_count + 1;

                    $$.code = format_string("%s, %s", $1.code, $3.code);
                }

assign_arg_list :  IDENTIFIER '=' rhs   {
                    if (!(is_number(&$3.type) || $3.type.type == CURVE_T)){
                        yyerror("argument values must be int, real or curve");
                    }

                    $$.code = format_string("{\"%s\", %s}", $1.text, $3.code);
                    free($3.code);
                }
                |  assign_arg_list ',' IDENTIFIER '=' rhs   {
                    if (!(is_number(&$5.type) || $5.type.type == CURVE_T)){
                        yyerror("argument values must be int, real or curve");
                    }

                    $$.code = format_string("%s, {\"%s\", %s}", $1.code, $3.text, $5.code);
                    free($1.code);
                    free($5.code);
                }

// Object reference
name            :  name membership IDENTIFIER    {
                    if ($1.type.type == NOT_DEFINED){
                        $$.type.type = NOT_DEFINED;
                    } else {
                        if ($2.is_arrow && $1.type.type != POINTER){
                            $$.type.type = NOT_DEFINED;
                            yyerror("Arrow expression must be a pointer");
                        } else {
                            $$.type = *get_type_of_member(curr_table, ($2.is_arrow ? $1.type.subtype : &$1.type), $3.text);
                            if ($$.type.type == NOT_DEFINED){
                                yyerror(format_string("Member '%s' of type '%s' not defined", $3.text, ($2.is_arrow ? $1.type.subtype->name : $1.type.name)));
                            }
                        }
                    }

                    $$.code = format_string("%s%s%s", $1.code, $2.text, $3.text);
                    free($1.code);
                }
                /* |  name ARROW IDENTIFIER    {
                    if ($1.type.type != POINTER){
                        yyerror("Arrow expression must be a pointer");
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type = *get_type_of_member(curr_table, $1.type.subtype, $3.text);
                        if ($$.type.type == NOT_DEFINED){
                            yyerror(format_string("Member '%s' of type '%s' not defined", $3.text, $1.type.subtype->name));
                        }
                    }

                    $$.code = format_string("%s%s%s", $1.code, $2.text, $3.text);
                    free($1.code);
                }
                |  name DOT IDENTIFIER  {
                    if ($1.type.type == NOT_DEFINED){
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type = *get_type_of_member(curr_table, &$1.type, $3.text);
                        if ($$.type.type == NOT_DEFINED){
                            yyerror(format_string("Member '%s' of type '%s' not defined", $3.text, $1.type.name));
                        }
                    }

                    $$.code = format_string("%s%s%s", $1.code, $2.text, $3.text);
                    free($1.code);
                } */
                |  name '[' rhs ']' {
                    if ($1.type.type == ARRAY || $1.type.type == POINTER){
                        $$.type = *$1.type.subtype;
                    } else if ($1.type.type == PRIMITIVE && strcmp($1.type.name, "vector") == 0) {
                        init_var_type(&$$.type);
                        $$.type = $1.type.args[0];
                    } else if ($1.type.type == PRIMITIVE && strcmp($1.type.name, "string") == 0) {
                        init_var_type(&$$.type);
                        $$.type.type = PRIMITIVE;
                        $$.type.name = "char";
                    } else {
                        yyerror("Array expression must be an array, pointer, vector or string");
                    }
                    if (strcmp($3.type.name, "int") != 0){
                        yyerror("Array index must be an integer");
                    }

                    $$.code = format_string("%s[%s]", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  IDENTIFIER   {
                    $$.type = *get_type_of_var(curr_table, $1.text);
                    if ($$.type.type == NOT_DEFINED){
                        yyerror(format_string("Variable '%s' not defined", $1.text));
                    }
                    $$.code = format_string("%s", $1.text);
                }
                |  starred_name {
                    $$ = $1;
                }

// Starred object reference
starred_name    :  '*' '(' name ')' {
                    if ($3.type.type != POINTER){
                        yyerror("Starred expression must be a pointer");
                    }
                    $$.type = *$3.type.subtype;

                    $$.code = format_string("*(%s)", $3.code);
                    free($3.code);
                }
                |  '*' starred_name {
                    if ($2.type.type != POINTER){
                        yyerror("Starred expression must be a pointer");
                    } else {
                        $$.type = *$2.type.subtype;
                    }

                    $$.code = format_string("*%s", $2.code);
                    free($2.code);
                }
                |  '*' IDENTIFIER   {
                    var_type *type = get_type_of_var(curr_table, $2.text);
                    if (type->type != POINTER){
                        yyerror("Starred expression must be a pointer");
                        init_var_type(&$$.type);
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type = *type->subtype;
                    }

                    $$.code = format_string("*%s", $2.text);
                }

differentiate   :  DIFF '[' rhs ',' rhs ']' {
                    if ($3.type.type != CURVE_T){
                        yyerror("Differentiation must be a curve");
                    }
                    if (is_number(&$3.type) || ($3.type.type == PRIMITIVE && strcmp($5.type.name, "complex") == 0)){
                        $3.code = format_string("Expression(\"%s\")", $3.code);
                    }
                    if ($5.type.type != CURVE_T && $5.type.type == PRIMITIVE && (strcmp($5.type.name, "string") != 0)){
                        yyerror("Type must be a curve or string");
                    }
                    $$.type.type = CURVE_T;

                    $$.code = format_string("(%s).differentiate(%s)", $3.code, $5.code);
                    free($3.code);
                    free($5.code);
                }
                |  DIFF '[' rhs ',' rhs ',' INTEGER ']' {
                    if ($3.type.type != CURVE_T){
                        yyerror("Differentiation must be a curve");
                    }
                    if (is_number(&$3.type) || ($3.type.type == PRIMITIVE && strcmp($5.type.name, "complex") == 0)){
                        $3.code = format_string("Expression(\"%s\")", $3.code);
                    }
                    if ($5.type.type != CURVE_T && $5.type.type != PRIMITIVE && strcmp($5.type.name, "string") != 0){
                        yyerror("Type must be a curve or string");
                    }
                    $$.type.type = CURVE_T;

                    $$.code = format_string("(%s).differentiate(%s, %s)", $3.code, $5.code, $7.text);
                    free($3.code);
                    free($5.code);
                }

// Conditional Statement
conditional     :  ifBlock  {
                    $$.code = $1.code;
                }
                |  ifBlock ELSE {label("Else statement");} statement    {
                    $$.code = format_string("%s else %s", $1.code, $4.code);
                    free($1.code);
                    free($4.code);
                }

// If Statement
ifBlock         :  IF '(' rhs ')' {
                    label("If statement");
                    if (!(is_number(&$3.type) || ($3.type.type == PRIMITIVE && strcmp($3.type.name, "bool") == 0))){
                        yyerror("If statement must have number or bool type");
                    }
                } block {
                    $$.code = format_string("if (%s) %s", $3.code, $6.code);
                    free($3.code);
                    free($6.code);
                }

// Loop Statements
loop            :  UNTIL '(' rhs ')' REPEAT {label("Loop");} statement  {
                    $$.code = format_string("while (%s)\n%s", $3.code, $7.code);
                    free($3.code);
                    free($7.code);
                }
                |  REPEAT {label("Loop");} statement UNTIL '(' rhs ')'  {
                    $$.code = format_string("do %s while (%s);", $3.code, $6.code);
                    free($3.code);
                    free($6.code);
                }

// For Loop
forLoop         :  FOR IDENTIFIER IN forLoopTail    {
                    st_entry entry;
                    entry.name = $2.text;
                    entry.type = malloc(sizeof(var_type));
                    *entry.type = $4.type;
                    entry.subtable = NULL;
                    st_insert(curr_table, entry);
                }   statement   {
                    $$.code = format_string("for %s %s", format_string($4.code, $2.text, $2.text, $2.text), $6.code);
                }

forLoopTail     :  loopVals DOTS loopVals {label("For loop");}    {
                    if ($1.type.type != PRIMITIVE || strcmp($1.type.name, "int") != 0 || $3.type.type != PRIMITIVE || strcmp($3.type.name, "int") != 0){
                        yyerror("For loop must have int types");
                    }
                    $$.type = $1.type;

                    $$.code = format_string("(auto %%s=%s; %%s<%s; %%s++)", $1.code, $3.code);
                    free($1.code);
                    free($3.code);
                }
                |  loopVals DOTS loopVals DOTS loopVals {label("For loop");}  {
                    if ($1.type.type != PRIMITIVE || strcmp($1.type.name, "int") != 0 || $3.type.type != PRIMITIVE || strcmp($3.type.name, "int") != 0 || $5.type.type != PRIMITIVE || strcmp($5.type.name, "int") != 0){
                        yyerror("For loop must have int types");
                    }
                    $$.type = $1.type;

                    $$.code = format_string("(auto %%s=%s; %%s<%s; %%s+=%s)", $1.code, $3.code, $5.code);
                    free($1.code);
                    free($3.code);
                    free($5.code);
                }
                |  '(' rhs ')' {label("For loop");}   {
                    if (!is_iterable(&$2.type)){
                        yyerror("For loop must have iterable type");
                    }
                    $$.type = *get_item_type(&$2.type);

                    $$.code = format_string("(auto %%s: %s)", $2.code);
                    free($2.code);
                }
                |  value {label("For loop");}   {
                    if (!is_iterable(&$1.type)){
                        yyerror("For loop must have iterable type");
                    }
                    $$.type = *get_item_type(&$1.type);

                    $$.code = format_string("(auto %%s: %s)", $1.code);
                    free($1.code);
                }

loopVals        :  value    {
                    $$.type = $1.type;

                    $$.code = $1.code;
                }
                |  '(' rhs ')'  {
                    $$.type = $2.type;

                    $$.code = $2.code;
                }
                |  unary_op_only    {
                    $$.type = $1.type;

                    $$.code = $1.code;
                }

%%

void yyerror(char * msg){
    errors *e = (errors *)malloc(sizeof(errors));
    e->msg = msg;
    e->pos = pos_info;

    if (prev_err == NULL){
        prev_err = e;
        err = e;
        err->next = NULL;
    } else {
        prev_err->next = e;
        prev_err = e;
    }

    /* printf("%s:%d.%d\n", input_file, pos_info.last_row+1, pos_info.last_col+1);
    printf("%s\n",msg); */
    /* exit(1); */
}

void print_errs(){
    errors *e = err;
    while (e != NULL){
        printf("%s:%d.%d\n", input_file, e->pos.last_row+1, e->pos.last_col+1);
        printf("%s\n\n",e->msg);
        e = e->next;
    }
}

void parse_args(int argc, char *argv[]){
    yyin = yyout = parsed_file = cpp_file = NULL;
    /* if (argc == 2 && strcmp(argv[1], "-h") == 0){
        printf("Usage: %s [input_file] [token_file] [parsed_file]\n", argv[0]);
        exit(0);
    }
    if (argc >= 4){
        parsed_file = fopen(argv[3],"w");
    } else {
        parsed_file = fopen("/dev/null", "w");
    }

    if (argc >= 3){
        yyout = fopen(argv[2],"w");
    } else {
        yyout = fopen("/dev/null", "w");
    }

    if (argc >= 2){
        yyin = fopen(argv[1], "r");
        input_file = strdup(argv[1]);
    } else {
        yyin = stdin;
        input_file = strdup("stdin");
    } */

    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "-c") == 0){
            cpp_file = fopen(argv[++i], "w");
        }
        else if (strcmp(argv[i], "-l") == 0){
            yyout = fopen(argv[++i],"w");
        }
        else if (strcmp(argv[i], "-p") == 0){
            parsed_file = fopen(argv[++i],"w");
        }
        else if (strcmp(argv[i], "-h") == 0){
            printf("Usage: %s [input_file] [token_file] [parsed_file]\n", argv[0]);
            exit(0);
        }
        else if (strcmp(argv[i], "-v") == 0){
            printf("Version: 0.1\n");
            exit(0);
        } else if (argv[i][0] == '-'){
            printf("Invalid option: %s\n", argv[i]);
            exit(1);
        }
        else {
            if (yyin != NULL){
                printf("Multiple input files not allowed\n");
                exit(1);
            }
            yyin = fopen(argv[i], "r");
            input_file = strdup(argv[i]);
        }
    }

    if (yyin == NULL){
        yyin = stdin;
    }
    if (yyout == NULL){
        yyout = fopen("/dev/null", "w");
    }
    if (parsed_file == NULL){
        parsed_file = fopen("/dev/null", "w");
    }
    if (cpp_file == NULL){
        cpp_file = fopen("a.cpp", "w");
    }
}

void clean_files(){
    if (yyin != stdin)
        fclose(yyin);
    fclose(yyout);
    fclose(parsed_file);
    fclose(cpp_file);
}

int main(int argc, char *argv[]){
    parse_args(argc, argv);

    global_table = st_create(8, 0, false);
    curr_table = global_table;

    insert_default_funcs(global_table);
    insert_vector_type(global_table);

    yyparse();

    if (err != NULL){
        print_errs();
        clean_files();
        exit(1);
    }

    clean_files();

    return 0;
}
