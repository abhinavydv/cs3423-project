%{
    #include "symbol_table.h"
    #define YYSTYPE state 

    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>


    // variables
    extern int line_count;
    extern FILE  * yyin, *yyout, *parsed_file;
    symbol_table *global_table;
    symbol_table *curr_table;
    state yylval;

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
%token REAL NEWLINE IF ELSE DOT
%token REPEAT UNTIL BREAK CONTINUE IMPORT TRUE FALSE FUNC

%%
start           :  program         // Intialisation and deletion of Symbol Table
                |  NEWLINE {printf(" : invalid program\n"); exit(0);}

// the program
program         :  global_decl program // Passing Symbol Table to Global_DECL
                |

// all global statements allowed
global_decl     :  decl_only ';'
                |  function
                |  FUNC funcDef ';'
                |  struct
                |  import
                |  ';'

// struct defs
struct          :  STRUCT IDENTIFIER {label("Struct def");} '{' declarations '}'  // Store the struct with the list of all of its identifier in the declaration

// function defs
function        :  FUNC funcDef block

// function header defs
funcDef         :  ret_type IDENTIFIER '(' parameters ')' {label("Function def");}
                |  ret_type IDENTIFIER '(' ')' {label("Function def");}

ret_type        :  type     {
                    $$ = $1;
                }
                |  CURVE    {
                    init_var_type(&$$.type);
                    $$.type.type = CURVE;
                }
                |  VOID     {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
                }

// function parameters
parameters      :  type_defs
                |  parameters ',' type_defs

// type definitions for function parameters
type_defs       :  type decl_id
                |  CURVE decl_id

type            :  DATA_TYPE temp_params {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
                    $$.type.num_args = $2.type.num_args;
                    $$.type.args = $2.type.args;
                }
                |  IDENTIFIER   {
                    init_var_type(&$$.type);
                    $$.type.name = $1.text;
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

typelist        :  type {
                    $$.type.num_args = 1;
                    $$.type.args = (var_type *)malloc(sizeof(var_type));
                    $$.type.args[0] = $1.type;
                }
                |  type ',' typelist    {
                    $$.type.num_args = $3.type.num_args + 1;
                    $$.type.args = (var_type *)malloc($$.type.num_args * sizeof(var_type));
                    $$.type.args[0] = $1.type;
                    for (int i = 0; i < $3.type.num_args; i++){
                        $$.type.args[i+1] = $3.type.args[i];
                    }
                    free($3.type.args);
                }

// block of statements
block           : '{' statements '}'

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
curve_decl      :  IDENTIFIER '(' idlist ')'
                |  decl_id

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
                    $$.curr_id_list->id.id = $1.text;
                    $$.curr_id_list->id.num_stars = 0;
                    $$.curr_id_list->id.num_braks = 0;
                    $$.curr_id_list->id.brak_vals = 0;
                }

// Declaration with/without assignment
decl_assgn      :  type assignList
                |  CURVE curveAssignList

// list of IDs/assignments of curves for declarations
curveAssignList :  curveAssignList ',' curve_assign
                |  curve_assign

// ID/Assignment for a curve
curve_assign    :  curve_decl '=' rhs
                |  curve_decl

// list of IDs/assignments for declarations
assignList      :  assignList ',' assign_decl
                |  assign_decl
                |  assignList ',' decl_id
                |  decl_id
                |  assignList ',' IDENTIFIER '(' arglist ')' {
                    
                }
                |  IDENTIFIER '(' arglist ')'

// ID/Assignment for a declaration
assign_decl     :  decl_id '=' rhs
                |  decl_id '=' '{' initializerList '}'

// Assignment
assign          :  lhs '=' rhs
                |  lhs '=' '{' initializerList '}'

// Augmented Assignment
augAssign       :  lhs AUG_ASSIGN rhs

// Initializer List like in C/Cpp, i.e., {1,2,3}
initializerList :  initializerList ',' rhs
                |  rhs

// Assign a rhs to multiple variables;
multi_assign    :  lhs '=' multi_assign
                |  assign

// list of identifiers
idlist          :  IDENTIFIER
                |  idlist ',' IDENTIFIER

// LHS of an assignment
lhs             :  name

// Logical Operators
rhs             :  rhs OR and
                |  and

and             :  and AND comparision
                |  comparision

// Comparison Operators
comparision     :  comparision compare_op plus
                |  plus

compare_op      :  '<'
                |  '>'
                |  COMPARE

// Arithmetic Operators
plus            :  plus '+' product
                |  plus '-' product
                |  product

product         :  product '*' mod
                |  mod

mod             :  mod '%' division
                |  division

division        :  division '/' bit_or
                |  bit_or

// Bitwise Operators
bit_or          :  bit_or '|' bit_and
                |  bit_and

bit_and         :  bit_and '&' shift
                |  shift

shift           :  shift SHIFT power
                |  power

// Power Operator
power           :  power '^' unary_op
                |  unary_op

unary_op        :  unary_op_only
                |  final

// Unary Operators
unary_op_only   :  '~' final
                |  '-' final
                // TODO: Figure out starred expressions
                /* |  '*' '(' rhs ')' */
                |  '!' final        // logical not
                |  final '!'        // factorial
                |  INCREMENT name   // only names are allowed
                |  name INCREMENT   // only names are allowed
                |  DECREMENT name   // only names are allowed
                |  name DECREMENT   // only names are allowed

final           :  value
                |  '(' rhs ')'

// Values: Numbers, Strings, Booleans, Identifiers, Calls, Object Calls, Differentiate
// i.e. everything without an operator
value           :  number
                |  STRING
                |  CHAR
                |  TRUE
                |  FALSE
                |  name
                |  call
                |  obj_call
                |  differentiate
                |  DOLLAR_ID

// Numbers: Real and Integer
number          :  REAL
                |  INTEGER

// Return Statement
ret             :  RETURN rhs ';'
                |  RETURN ';'

// Function Call
call            :  IDENTIFIER '(' arglist ')'

// Function Call with object
obj_call        :  name ARROW IDENTIFIER '(' arglist ')'
                |  name DOT IDENTIFIER '(' arglist ')'

// List of arguments for a function call
arglist         :  rhs
                |  rhs ',' arglist
                |  assign_arg_list
                |

assign_arg_list :  IDENTIFIER '=' rhs
                |  assign_arg_list ',' IDENTIFIER '=' rhs

// Object reference
name            :  name ARROW IDENTIFIER
                |  name DOT IDENTIFIER
                |  name '[' rhs ']'
                |  IDENTIFIER
                |  starred_name

// Starred object reference
starred_name    :  '*' '(' name ')'
                |  '*' starred_name
                |  '*' IDENTIFIER

differentiate   :  DIFF '[' rhs ',' rhs ']'
                |  DIFF '[' rhs ',' rhs ',' INTEGER ']'

// Conditional Statement
conditional     :  ifBlock
                |  ifBlock ELSE {label("Else statement");} statement

// If Statement
ifBlock         :  IF '(' rhs ')' {label("If statement");} block

// Loop Statements
loop            :  UNTIL '(' rhs ')' REPEAT {label("Loop");} statement
                |  REPEAT {label("Loop");} statement UNTIL '(' rhs ')'

// For Loop
forLoop         :  FOR IDENTIFIER IN loopVals DOTS loopVals {label("For loop");} statement
                |  FOR IDENTIFIER IN loopVals DOTS loopVals DOTS loopVals {label("For loop");} statement
                |  FOR IDENTIFIER IN '(' rhs ')' {label("For loop");} statement
                |  FOR IDENTIFIER IN value {label("For loop");} statement

loopVals        :  value
                |  '(' rhs ')'
                |  unary_op_only

%%

void yyerror(char * msg){
    printf("%s\n",msg);
    exit(1);
}

int main(int argc, char *argv[]){

    if (argc != 4){
        printf("Format not Used: [executable] [input file] [token file] [parsed file]\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");
    parsed_file = fopen(argv[3],"w");

    global_table = st_create(8, 0, false);
    curr_table = global_table;

    yyparse();

    st_print_table(global_table);

    fclose(yyin);
    fclose(yyout);
    fclose(parsed_file);
    return 0;
}
