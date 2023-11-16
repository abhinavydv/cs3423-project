%{
    #include "symbol_table.h"
    #define YYSTYPE state

    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #include <string.h>


    // variables
    extern FILE  *yyin, *yyout, *parsed_file;
    FILE *cpp_file = NULL;
    char *input_file;
    position pos_info = {0};   // used for error reporting
    symbol_table *global_table;
    symbol_table *curr_table;
    st_entry *func_def_entry;
    state yylval;
    var_type curr_type;

    errors *err = NULL;
    errors *prev_err = NULL;

    // functions
    int yylex();
    void yyerror(char * msg);

    void label(char * msg){
        fprintf(parsed_file," /* %s */ ",msg);
    }
%}

%token DATA_TYPE IDENTIFIER STRING IN DOTS
%token CHAR RETURN INTEGER CURVE DOLLAR_ID
%token FOR STRUCT AUG_ASSIGN DIFF
%token VOID ARROW COMPARE AND OR SHIFT DECREMENT INCREMENT
%token REAL IF ELSE DOT
%token REPEAT UNTIL BREAK CONTINUE IMPORT TRUE FALSE FUNC

%%
start           :  program         // Intialisation and deletion of Symbol Table
                |  error ';' {yyerror("Syntax error");}

// the program
program         :  global_decl program // Passing Symbol Table to Global_DECL
                |

// all global statements allowed
global_decl     :  decl_only ';'
                |  function {
                    func_def_entry = NULL;
                }
                |  FUNC funcDef ';' {
                    curr_table->is_incomplete = true;
                    curr_table = curr_table->parent;    // exit the parameter table
                    func_def_entry = NULL;
                }
                |  struct
                |  import
                |  ';'

// struct defs
struct          :  STRUCT IDENTIFIER {
                    label("Struct def");
                    symbol_table *new_table = st_create(8, curr_table->level+1, false);
                    st_insert_struct(curr_table, $2.text, new_table);
                    new_table->parent = curr_table;
                    curr_table = new_table;
                } '{' declarations '}' {
                    curr_table = curr_table->parent;
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
                        yyerror("Function Redefined!!");
                    }
                } statements '}'    {
                    curr_table = curr_table->parent->parent;
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
                }

starred_rettype :  starred_rettype '*' {
                    $$.type.type = POINTER;
                    $$.type.subtype = malloc(sizeof(var_type));
                    *$$.type.subtype = $1.type;
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
                }
                |  VOID     {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
                }

// function parameters
params          :  param_list   {
                    $$ = $1;
                }
                |   {
                    $$.type_list = NULL;
                    $$.count = 0;
                }
param_list      :  type_defs    {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;
                }
                |  param_list ',' type_defs {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count++;
                }

// type definitions for function parameters
type_defs       :  type decl_id {
                    $$.type = $1.type;
                    if (func_def_entry == NULL){
                        st_insert_var(curr_table, $2.curr_id_list->id, $1.type);
                    }
                }
                |  CURVE decl_id    {
                    init_var_type(&$$.type);
                    $$.type.type = CURVE_T;
                    if (func_def_entry == NULL){
                        st_insert_curve(curr_table, $2.curr_id_list->id, NULL, 0);
                    }
                }

type            :  DATA_TYPE temp_params {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
                    $$.type.num_args = $2.type.num_args;
                    $$.type.args = $2.type.args;
                }
                |  IDENTIFIER   {
                    init_var_type(&$$.type);
                    if (find_in_table(curr_table, $1.text) == NULL){
                        yyerror(format_string("Type '%s' not defined", $1.text));
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type.name = $1.text;
                    }
                }

// template paramaters
temp_params     :  '<' typelist '>' {
                    $$.type.num_args = $2.type.num_args;
                    $$.type.args = $2.type.args;
                }
                |   {
                    $$.type.num_args = 0;
                    $$.type.args = NULL;
                }

typelist        :  starred_rettype {
                    $$.type.num_args = 1;
                    $$.type.args = (var_type *)malloc(sizeof(var_type));
                    $$.type.args[0] = $1.type;
                }
                |  starred_rettype ',' typelist    {
                    $$.type.num_args = $3.type.num_args + 1;
                    $$.type.args = (var_type *)malloc($$.type.num_args * sizeof(var_type));
                    $$.type.args[0] = $1.type;
                    for (int i = 0; i < $3.type.num_args; i++){
                        $$.type.args[i+1] = $3.type.args[i];
                    }
                    free($3.type.args);
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
                }

statements      :  statement statements
                |

// Following are all the statements allowed
statement       :  decl_assgn ';'   {label("Declaration");}
                |  multi_assign ';' {label("Assignment");}
                |  augAssign ';'    {label("Augmented Assignment");}
                |  ret              {label("Return");}
                |  conditional
                |  loop
                |  forLoop
                |  call ';'         {label("Function Call");}
                |  obj_call ';'     {label("Object Function Call");}
                |  differentiate ';' {label("Differentiate");}
                |  block
                |  BREAK ';'        {label("Break");}
                |  CONTINUE ';'     {label("Continue");}
                |  ';'

// import statements
import          :  IMPORT STRING ';'

// list of declarations (for structs)
declarations    :  decl_only ';' {label("Declaration");} declarations
                |

// declarations only. No assignment (for global declration)
decl_only       :  type decl_id_list    {
                    st_insert_vars(curr_table, $2.curr_id_list, $1.type);
                }
                |  CURVE curve_decl_list

// list of curve identifiers
curve_decl_list :  curve_decl_list ',' curve_decl
                |  curve_decl

// identifier for a curve
curve_decl      :  IDENTIFIER '(' idlist ')'    {
                    id new_id = {$1.text, 0, 0, 0};
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    $$.curr_id_list->next = 0;
                    $$.curr_id_list->id = new_id;
                    $$.count = 1;
                    st_insert_curve(curr_table, new_id, $3.curr_id_list, $3.count);
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;
                    var_type type;
                    init_var_type(&type);
                    type.type = CURVE_T;
                    st_insert_vars(curr_table, $1.curr_id_list, type);
                }

// list of declaration identifiers.
decl_id_list    :  decl_id ',' decl_id_list {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;
                }

// declaration identifier with star
decl_id         :  '*' decl_id  {
                    $$ = $2;
                    $$.curr_id_list->id.num_stars++;
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
                }
                |  IDENTIFIER   {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    $$.curr_id_list->next = 0;
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;
                }

// Declaration with/without assignment
decl_assgn      :  type {curr_type = $1.type;} assignList  {
                    st_insert_vars(curr_table, $3.curr_id_list, $1.type);
                }
                |  CURVE curveAssignList

// list of IDs/assignments of curves for declarations
curveAssignList :  curveAssignList ',' curve_assign
                |  curve_assign

// ID/Assignment for a curve
curve_assign    :  curve_decl '=' rhs   {
                    var_type type;
                    init_var_type(&type);
                    type.type = CURVE_T;
                    var_type *new_type = gen_type($1.curr_id_list->id, type);
                    if (!is_assignable(new_type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                }
                |  curve_decl

// list of IDs/assignments for declarations
assignList      :  assign_decl ',' assignList   {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;
                }
                |  assign_decl  {
                    $$.curr_id_list = $1.curr_id_list;
                }
                |  decl_id ',' assignList   {
                    $$.curr_id_list = $1.curr_id_list;
                    $$.curr_id_list->next = $3.curr_id_list;
                }
                |  decl_id  {
                    $$.curr_id_list = $1.curr_id_list;
                }

// ID/Assignment for a declaration
assign_decl     :  decl_id '=' rhs  {
                    if (!is_assignable(gen_type($1.curr_id_list->id, curr_type), &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.curr_id_list = $1.curr_id_list;
                }
                |  decl_id '=' '{' initializerList '}'  {
                    if (!is_initializer_list_matched(curr_table, &$1.type, $4.type_list, $4.count)){
                        yyerror("Invalid assignment");
                    }
                    $$.curr_id_list = $1.curr_id_list;
                }

// Assignment
assign          :  lhs '=' rhs  {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.type = $3.type;
                }
                |  lhs '=' '{' initializerList '}'  {
                    if (!is_initializer_list_matched(curr_table, &$1.type, $4.type_list, $4.count)){
                        yyerror("Invalid assignment");
                    }
                }

// Augmented Assignment
augAssign       :  lhs AUG_ASSIGN rhs   {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                }

// Initializer List like in C/Cpp, i.e., {1,2,3}
initializerList :  initializerList ',' rhs  {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count = $1.count + 1;
                }
                |  rhs  {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;
                }

// Assign a rhs to multiple variables;
multi_assign    :  lhs '=' multi_assign {
                    if (!is_assignable(&$1.type, &$3.type)){
                        yyerror("Invalid assignment");
                    }
                    $$.type = $3.type;
                }
                |  assign   {
                    $$.type = $1.type;
                }

// list of identifiers
idlist          :  IDENTIFIER   {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;
                    $$.count = 1;
                }
                |  IDENTIFIER ',' idlist    {
                    $$.curr_id_list = (id_list *)malloc(sizeof(id_list));
                    init_id(&$$.curr_id_list->id);
                    $$.curr_id_list->id.id = $1.text;
                    $$.curr_id_list->next = $3.curr_id_list;
                    $$.count = 1 + $3.count;
                }

// LHS of an assignment
lhs             :  name {
                    $$ = $1;
                }

// TODO: Handle operator types
// Logical Operators
rhs             :  rhs OR and  {
                    $$.type = *get_compatible_type_logical(&$1.type, &$3.type);
                }
                |  and  {
                    $$ = $1;
                }

and             :  and AND comparison  {
                    $$.type = *get_compatible_type_logical(&$1.type, &$3.type);
                }
                |  comparison  {
                    $$ = $1;
                }

// Comparison Operators
comparison     :  comparison compare_op plus  {
                    $$.type = *get_compatible_type_comparison(&$1.type, &$3.type);
                }
                |  plus   {
                    $$ = $1;
                }

compare_op      :  '<'
                |  '>'
                |  COMPARE

// Arithmetic Operators
plus            :  plus '+' product  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);
                }
                |  plus '-' product  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);
                }
                |  product  {
                    $$ = $1;
                }

product         :  product '*' mod  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);
                }
                |  mod           {
                    $$ = $1;
                }

mod             :  mod '%' division  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);
                }
                |  division   {
                    $$ = $1;
                }

division        :  division '/' bit_or  {
                    $$.type = *get_compatible_type_arithmetic(&$1.type, &$3.type);
                }
                |  bit_or   {
                    $$ = $1;
                }

// Bitwise Operators
bit_or          :  bit_or '|' bit_and   {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);
                }
                |  bit_and  {
                    $$ = $1;
                }

bit_and         :  bit_and '&' shift    {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);
                }
                |  shift    {
                    $$ = $1;
                }

shift           :  shift SHIFT power    {
                    $$.type = *get_compatible_type_bitwise(&$1.type, &$2.type);
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
// TODO: add &
unary_op_only   :  '~' final    {
                    if (!is_int(&$2.type)){
                        yyerror("Bitwise not must have int type");
                    }
                    $$ = $2;
                }
                |  '&' name  {
                    if ($2.type.type == NOT_DEFINED){
                        $$.type = $2.type;
                    } else {
                        $$.type.type = POINTER;
                        $$.type.subtype = malloc(sizeof(var_type));
                        *$$.type.subtype = $2.type;
                    }
                }
                |  '-' final    {
                    if (!is_number(&$2.type) && $2.type.type != CURVE_T){
                        yyerror("Unary minus must have int or real or curve type");
                    }
                    $$ = $2;
                }
                // TODO: Figure out starred expressions
                /* |  '*' '(' rhs ')' */
                |  '!' final    {
                    if (!is_number(&$2.type) && ($2.type.type == PRIMITIVE && strcmp($2.type.name, "bool")) != 0){
                        yyerror("Not must have int or real type");
                    }
                    $$ = $2;
                }
                |  final '!'    {
                    if (!is_int(&$1.type)){
                        yyerror("Factorial must have int type");
                    }
                    $$ = $1;
                }
                |  INCREMENT name   {
                    if (!is_number(&$2.type)){
                        yyerror("Increment must have int or real type");
                    }
                    $$ = $2;
                }
                |  name INCREMENT   {
                    if (!is_number(&$1.type)){
                        yyerror("Increment must have int or real type");
                    }
                    $$ = $1;
                }
                |  DECREMENT name   {
                    if (!is_number(&$2.type)){
                        yyerror("Decrement must have int or real type");
                    }
                    $$ = $2;
                }
                |  name DECREMENT   {
                    if (!is_number(&$1.type)){
                        yyerror("Decrement must have int or real type");
                    }
                    $$ = $1;
                }

final           :  value    {
                    $$ = $1;
                }
                |  '(' rhs ')'  {
                    $$ = $2;
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
                }
                |  CHAR     {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "char";
                }
                |  TRUE     {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "bool";
                }
                |  FALSE    {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "bool";
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
                }

// Numbers: Real and Integer
number          :  REAL    {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "real";
                }
                |  INTEGER  {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "int";
                }

// Return Statement
ret             :  RETURN rhs ';'   {
                    if (!check_ret_type(curr_table, &$2.type)){
                        yyerror("Return type does not match function definition");
                    }
                    $$ = $2;
                }
                |  RETURN ';'   {
                    init_var_type(&$$.type);
                    $$.type.type = PRIMITIVE;
                    $$.type.name = "void";
                }

// Function Call
call            :  IDENTIFIER '(' arglist ')'   {
                    var_type *t = get_type_of_var(curr_table, $1.text);
                    if (t->type == NOT_DEFINED){
                        yyerror("Function not defined");
                    } else
                        $$.type = *t;
                    st_entry *entry = find_in_table(curr_table, $1.text);
                    if (entry->type->type == FUNCTION){
                        if (!is_function_matched(curr_table, $1.text, $3.type_list, $3.count))
                            yyerror("Function call does not match definition");
                    } else if (entry->type->type == CURVE_T){

                    } else {
                        yyerror("Function call must be a function");
                    }
                }

// Function Call with object
obj_call        :  name ARROW IDENTIFIER '(' arglist ')'    {
                    if ($1.type.type != POINTER){
                        yyerror("Arrow expression must be a pointer");
                    }
                    $$.type = *get_type_of_member(curr_table, $1.type.subtype, $3.text);
                    // is_object_function_matched(curr_table, $1.type.subtype, $3.text, $5.type_list, $5.count);
                }
                |  name DOT IDENTIFIER '(' arglist ')'  {
                    $$.type = *get_type_of_member(curr_table, &$1.type, $3.text);
                    // is_object_function_matched(curr_table, &$1.type, $3.text, $5.type_list, $5.count);
                }

// List of arguments for a function call
arglist         :  argOnlyList  {
                    $$.type_list = $1.type_list;
                    $$.count = $1.count;
                }
                |  assign_arg_list  {
                    $$.count = 0;
                }
                |   {
                    $$.count = 0;
                }

argOnlyList     :  rhs  {
                    $$.type_list = (var_type *)malloc(sizeof(var_type));
                    $$.type_list[0] = $1.type;
                    $$.count = 1;
                }
                |  argOnlyList ',' rhs  {
                    $$.type_list = (var_type *)realloc($1.type_list, ($1.count + 1) * sizeof(var_type));
                    $$.type_list[$1.count] = $3.type;
                    $$.count = $1.count + 1;
                }

assign_arg_list :  IDENTIFIER '=' rhs   {
                    if (!(is_number(&$3.type) || $3.type.type == CURVE_T)){
                        yyerror("argument values must be int, real or curve");
                    }
                }
                |  assign_arg_list ',' IDENTIFIER '=' rhs

// Object reference
name            :  name ARROW IDENTIFIER    {
                    if ($1.type.type != POINTER){
                        yyerror("Arrow expression must be a pointer");
                        $$.type.type = NOT_DEFINED;
                    } else {
                        $$.type = *get_type_of_member(curr_table, $1.type.subtype, $3.text);
                        if ($$.type.type == NOT_DEFINED){
                            yyerror(format_string("Member '%s' of type '%s' not defined", $3.text, $1.type.subtype->name));
                        }
                    }
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
                }
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
                }
                |  IDENTIFIER   {
                    $$.type = *get_type_of_var(curr_table, $1.text);
                    if ($$.type.type == NOT_DEFINED){
                        yyerror(format_string("Variable '%s' not defined", $1.text));
                    }
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
                }
                |  '*' starred_name {
                    if ($2.type.type != POINTER){
                        yyerror("Starred expression must be a pointer");
                    } else {
                        $$.type = *$2.type.subtype;
                    }
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
                }

differentiate   :  DIFF '[' rhs ',' rhs ']' {
                    if ($3.type.type != CURVE_T){
                        yyerror("Differentiation must be a curve");
                    }
                    if ($5.type.type != CURVE_T && (strcmp($5.type.name, "string") != 0)){
                        yyerror("Type must be a curve or string");
                    }
                    $$.type.type = CURVE_T;
                }
                |  DIFF '[' rhs ',' rhs ',' INTEGER ']' {
                    if ($3.type.type != CURVE_T){
                        yyerror("Differentiation must be a curve");
                    }
                    if ($5.type.type != CURVE_T && $5.type.type != PRIMITIVE && strcmp($5.type.name, "string") != 0){
                        yyerror("Type must be a curve or string");
                    }
                    $$.type.type = CURVE_T;
                }

// Conditional Statement
conditional     :  ifBlock
                |  ifBlock ELSE {label("Else statement");} statement

// If Statement
ifBlock         :  IF '(' rhs ')' {
                    label("If statement");
                    if (!(is_number(&$3.type) || ($3.type.type == PRIMITIVE && strcmp($3.type.name, "bool") == 0))){
                        yyerror("If statement must have number or bool type");
                    }
                } block    

// Loop Statements
loop            :  UNTIL '(' rhs ')' REPEAT {label("Loop");} statement
                |  REPEAT {label("Loop");} statement UNTIL '(' rhs ')'

// For Loop
forLoop         :  FOR IDENTIFIER IN forLoopTail    {
                    st_entry entry;
                    entry.name = $2.text;
                    entry.type = malloc(sizeof(var_type));
                    *entry.type = $4.type;
                    entry.subtable = NULL;
                    st_insert(curr_table, entry);
                }   statement

forLoopTail     :  loopVals DOTS loopVals {label("For loop");}    {
                    if ($1.type.type != PRIMITIVE || strcmp($1.type.name, "int") != 0 || $3.type.type != PRIMITIVE || strcmp($3.type.name, "int") != 0){
                        yyerror("For loop must have int types");
                    }
                    $$.type = $1.type;
                }
                |  loopVals DOTS loopVals DOTS loopVals {label("For loop");}  {
                    if ($1.type.type != PRIMITIVE || strcmp($1.type.name, "int") != 0 || $3.type.type != PRIMITIVE || strcmp($3.type.name, "int") != 0 || $5.type.type != PRIMITIVE || strcmp($5.type.name, "int") != 0){
                        yyerror("For loop must have int types");
                    }
                    $$.type = $1.type;
                }
                |  '(' rhs ')' {label("For loop");}   {
                    if (!is_iterable(&$2.type)){
                        yyerror("For loop must have iterable type");
                    }
                    $$.type = *get_item_type(&$2.type);
                }
                |  value {label("For loop");}   {
                    if (!is_iterable(&$1.type)){
                        yyerror("For loop must have iterable type");
                    }
                    $$.type = *get_item_type(&$1.type);
                }

loopVals        :  value    {
                    $$.type = $1.type;
                }
                |  '(' rhs ')'  {
                    $$.type = $2.type;
                }
                |  unary_op_only    {
                    $$.type = $1.type;
                }

%%

void yyerror(char * msg){
    errors *e = (errors *)malloc(sizeof(errors));
    e->msg = msg;
    e->pos = pos_info;

    if (prev_err == NULL){
        prev_err = e;
        err = e;
    } else {
        prev_err->next = e;
        prev_err = e;
    }

    printf("%s:%d.%d\n", input_file, pos_info.last_row+1, pos_info.last_col+1);
    printf("%s\n",msg);
    exit(1);
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

    yyparse();

    if (err != NULL){
        print_errs();
        clean_files();
        exit(1);
    }

    clean_files();

    return 0;
}
