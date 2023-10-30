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
                |  NEWLINE {printf(" : invalid program"); exit(0);}

program         :  global_decl program
                |

global_decl     :  decl_only ';'
                |  function
                |  struct
                |  import

struct          :  STRUCT IDENTIFIER '{' declarations '}'

function        :  FUNC funcDef block

funcDef         :  type IDENTIFIER '(' parameters ')'
                |  type IDENTIFIER '(' ')'
                |  CURVE IDENTIFIER '(' parameters ')'
                |  CURVE IDENTIFIER '(' ')'

parameters      :  type_defs
                |  parameters ',' type_defs

type_defs       :  type IDENTIFIER
                |  type '*' IDENTIFIER
                |  CURVE curve_decl
                |  CURVE '*' curve_decl

type            :  DATA_TYPE parameter
                |  IDENTIFIER
                |  VOID

parameter       :  '<' typelist '>'
                |

typelist        :  type
                |  typelist ',' type

block           : '{' statements '}'

statements      :  statement statements
                |

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

import          :  IMPORT STRING ';'

declarations    :  decl_only ';' declarations
                |

decl_only       :  type decl_id_list
                |  CURVE curve_decl_list

curve_decl      :  IDENTIFIER '(' idlist ')'
                |  IDENTIFIER

curve_decl_list :  curve_decl_list ',' curve_decl
                |  curve_decl

decl_id_list    :  decl_id_list ',' decl_id
                |  decl_id

decl_id         :  decl_id '[' INTEGER ']'
                |  decl_id2

decl_id2        :  '*' decl_id2
                |  IDENTIFIER

// Assignment with declaration
decl_assgn      :  type assignList
                |  CURVE curveAssignList

curveAssignList :  curveAssignList ',' curve_assign
                |  curve_assign

curve_assign    :  curve_decl '=' rhs
                |  curve_decl

assignList      :  assignList ',' assign_decl
                |  assign_decl
                |  assignList ',' decl_id
                |  decl_id
                |  assignList ',' IDENTIFIER '(' arglist ')'
                |  IDENTIFIER '(' arglist ')'

assign_decl     :  decl_id '=' rhs
                |  decl_id '=' '{' initializerList '}'

assign          :  lhs '=' rhs
                |  lhs '=' '{' initializerList '}'

augAssign       :  lhs AUG_ASSIGN rhs

initializerList :  initializerList ',' rhs
                |  rhs

multi_assign    :  lhs '=' multi_assign
                |  assign

idlist          :  IDENTIFIER
                |  idlist ',' IDENTIFIER

lhs             :  name

// Logical Operators
rhs             :  rhs OR and
                |  and

and             :  and AND comparision
                |  comparision

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

value           :  number
                |  STRING
                |  CHAR
                |  TRUE
                |  FALSE
                |  name
                |  call
                |  obj_call
                |  differentiate

number          :  REAL
                |  INTEGER

ret             :  RETURN rhs ';'
                |  RETURN ';'

call            :  IDENTIFIER '(' arglist ')'

obj_call        :  name ARROW IDENTIFIER '(' arglist ')'

/* non_star_name   :  non_star_name ARROW IDENTIFIER
                |  non_star_name '[' rhs ']'
                |  IDENTIFIER */

name            :  name ARROW IDENTIFIER
                |  name '[' rhs ']'
                |  IDENTIFIER
                |  starred_name

starred_name    :  '*' '(' name ')'
                |  '*' starred_name
                |  '*' IDENTIFIER

arglist         :  rhs
                |  arglist ',' rhs
                |

differentiate   :  DIFF '[' rhs ',' rhs ']'
                |  DIFF '[' rhs ',' rhs ',' INTEGER ']'

// TODO: add suport for one line without block
conditional     :  ifBlock
                |  ifBlock ELSE statement

ifBlock         :  IF '(' rhs ')' block

loop            :  UNTIL '(' rhs ')' REPEAT block
                |  REPEAT block UNTIL '(' rhs ')'

forLoop         :  FOR IDENTIFIER IN loopVals DOTS loopVals block
                |  FOR IDENTIFIER IN loopVals DOTS loopVals DOTS loopVals block
                |  FOR IDENTIFIER IN IDENTIFIER statement

loopVals        :  INTEGER
                |  IDENTIFIER

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