%{
    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #define YYSTYPE double /* double type for yacc stack */

    extern FILE  * yyin, *yyout;
    int yylex();
    void yyerror(char * msg);

%}

%token DATA_TYPE IDENTIFIER STRING IN DOTS
%token CHAR RETURN INTEGER CURVE
%token FOR STRUCT AUG_ASSIGN DIFF
%token VOID ARROW COMPARE AND OR SHIFT DECREMENT INCREMENT
%token REAL NEWLINE IF ELSE
%token REPEAT UNTIL BREAK CONTINUE IMPORT TRUE FALSE FUNC

%%
start           :  program
                |  NEWLINE {printf(" : invalid program\n"); exit(0);}

// the program
program         :  global_decl program
                |

// all global statements allowed
global_decl     :  decl_only ';'
                |  function
                |  FUNC funcDef ';'
                |  struct
                |  import

// struct defs
struct          :  STRUCT IDENTIFIER '{' declarations '}'

// function defs
function        :  FUNC funcDef block

// function header defs
funcDef         :  type IDENTIFIER '(' parameters ')'
                |  type IDENTIFIER '(' ')'
                |  CURVE IDENTIFIER '(' parameters ')'
                |  CURVE IDENTIFIER '(' ')'

// function parameters
parameters      :  type_defs
                |  parameters ',' type_defs

// type definitions for function parameters
type_defs       :  type decl_id
                |  CURVE decl_id

type            :  DATA_TYPE temp_params
                |  IDENTIFIER
                |  VOID

// template paramaters
temp_params       :  '<' typelist '>'
                |

typelist        :  type
                |  typelist ',' type

// block of statements
block           : '{' statements '}'

statements      :  statement statements
                |

// Following are all the statements allowed
statement       :  decl_assgn ';'
                |  multi_assign ';'
                |  augAssign ';'
                |  ret
                |  conditional
                |  loop
                |  forLoop
                |  call ';'
                |  obj_call ';'
                |  block
                |  BREAK ';'
                |  CONTINUE ';'
                |  ';'

// import statements
import          :  IMPORT STRING ';'

// list of declarations (for structs)
declarations    :  decl_only ';' declarations
                |

// declarations only. No assignment (for global declration)
decl_only       :  type decl_id_list
                |  CURVE curve_decl_list

// list of curve identifiers
curve_decl_list :  curve_decl_list ',' curve_decl
                |  curve_decl

// identifier for a curve
curve_decl      :  IDENTIFIER '(' idlist ')'
                |  decl_id

// list of declaration identifiers.
decl_id_list    :  decl_id_list ',' decl_id
                |  decl_id

// declaration identifier with star
decl_id         :  '*' decl_id
                |  decl_id2

// declaration identifier with square brackets
decl_id2        :  decl_id2 '[' INTEGER ']'
                |  IDENTIFIER

// Declaration with/without assignment
decl_assgn      :  type assignList
                |  CURVE curveAssignList

// list of IDs/assignments for curves for declarations
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
                |  assignList ',' IDENTIFIER '(' arglist ')'
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

// Unary Operators
unary_op        :  '~' final
                |  '-' final
                // TODO: Figure out starred expressions
                /* |  '*' '(' rhs ')' */
                |  '!' final
                |  final '!'
                |  INCREMENT final
                |  final INCREMENT
                |  DECREMENT final
                |  final DECREMENT
                |  final

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

// List of arguments for a function call
arglist         :  rhs
                |  arglist ',' rhs
                |

// Object reference
name            :  name ARROW IDENTIFIER
                |  name '[' rhs ']'
                |  IDENTIFIER
                |  starred_name

// Starred object reference
starred_name    :  '*' '(' name ')'
                |  '*' starred_name
                |  '*' IDENTIFIER

differentiate   :  DIFF '[' rhs ',' rhs ']'
                |  DIFF '[' rhs ',' rhs ',' INTEGER ']'

// Conditional Statements
// TODO: add suport for one line without block
conditional     :  ifBlock
                |  ifBlock ELSE statement

// If Statement
ifBlock         :  IF '(' rhs ')' block

// Loop Statements
loop            :  UNTIL '(' rhs ')' REPEAT block
                |  REPEAT block UNTIL '(' rhs ')'

// For Loop
forLoop         :  FOR IDENTIFIER IN loopVals DOTS loopVals block
                |  FOR IDENTIFIER IN loopVals DOTS loopVals DOTS loopVals block
                |  FOR IDENTIFIER IN '(' rhs ')' statement
                |  FOR IDENTIFIER IN value statement

loopVals        :  value
                |  '(' rhs ')'

%%

void yyerror(char * msg){
    printf("%s\n",msg);
}

int main(int argc, char *argv[]){


    if (argc != 3){
        printf("Format not Used: [executable] [input file] [c output file]\n");
        assert(0);
    }
 
 
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");

    yyparse();

    
    return 0;
}