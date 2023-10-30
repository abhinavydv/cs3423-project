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
%token CHAR RETURN INTEGER CURVE UNARY_OP
%token FOR BIN_OP STRUCT AUG_ASSIGN POWER
%token VOID ARROW COMPARE AND OR SHIFT DECREMENT INCREMENT
%token TRUE_FALSE REAL NEWLINE IF ELSE
%token REPEAT UNTIL BREAK CONTINUE IMPORT TRUE FALSE FUNC

%%
start           :  program
                |  NEWLINE {printf(" : invalid program"); exit(0);}

program         :  global_decl program
                |

global_decl     :  decl_only ';'
                |  function
                |  struct

struct          :  STRUCT IDENTIFIER '{' declarations '}'

function        :  FUNC funcDef block

funcDef         :  type IDENTIFIER '(' parameters ')'
                |  type IDENTIFIER '(' ')'

parameters      :  type_defs
                |  parameters ',' type_defs

type_defs       :  type IDENTIFIER
                |  type '*' IDENTIFIER
                |  CURVE IDENTIFIER
                |  CURVE '*' IDENTIFIER

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
                |  import
                |  conditional
                |  loop
                |  forLoop
                |  rhs ';'
                |  block
                |  BREAK ';'
                |  CONTINUE ';'
                |  ';'

import          :  IMPORT STRING ';'

declarations    :  decl_only ';' declarations
                |

decl_only       :  type decl_id_list
                |  CURVE IDENTIFIER '(' idlist ')'
                |  CURVE IDENTIFIER

decl_id_list    :  decl_id_list ',' decl_id
                |  decl_id

decl_id         :  decl_id '[' INTEGER ']'
                |  decl_id2

decl_id2        :  '*' decl_id2
                |  IDENTIFIER

decl_assgn      :  type assignList
                |  CURVE IDENTIFIER '(' idlist ')' '=' rhs
                |  CURVE IDENTIFIER '=' rhs

assignList      :  assignList ',' assign
                |  assign
                |  assignList ',' IDENTIFIER
                |  IDENTIFIER

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

rhs             :  rhs OR and
                |  and

and             :  and AND comparision
                |  comparision

comparision     :  comparision COMPARE plus
                |  plus

plus            :  plus '+' term
                |  plus '-' term
                |  term

term            :  term '*' bit_or
                |  term '/' bit_or
                |  term '%' bit_or
                |  bit_or

bit_or          :  bit_or '|' bit_xor
                |  bit_xor

bit_xor         :  bit_xor '^' bit_and
                |  bit_and

bit_and         :  bit_and '&' shift
                |  shift

shift           :  shift SHIFT power
                |  power

power           :  power POWER unary_op
                |  unary_op

// TODO: Figure out starred expressions
unary_op        :  '~' final
                |  '-' final
                /* |  '*' final */
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
                |  TRUE_FALSE
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
                |  starred_name

starred_name    :  '*' '(' name ')'
                |  '*' starred_name
                |  '*' IDENTIFIER

arglist         :  rhs
                |  arglist ',' rhs
                |

differentiate   :  'D' '[' rhs ',' rhs ']'
                |  'D' '[' rhs ',' rhs ',' INTEGER ']'

// TODO: add suport for one line without block
conditional     :  ifBlock
                |  ifBlock ELSE statement

ifBlock         :  IF '(' rhs ')' block

loop            :  UNTIL '(' rhs ')' REPEAT block
                |  REPEAT block UNTIL '(' rhs ')'

forLoop         :  FOR IDENTIFIER IN loopVals DOTS loopVals statement
                |  FOR IDENTIFIER IN loopVals DOTS loopVals DOTS loopVals statement
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