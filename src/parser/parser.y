%{
    #include <stdio.h>
    #include <assert.h>
    #define YYSTYPE double /* double type for yacc stack */
    
    extern FILE  * yyin, *yyout;
    
%}

%token STRING_CONST CHAR_CONST NUM_CONST INT STRING CHAR BOOL REAL COMPLEX CURVE VOID VECTOR STRUCT
%token IF ELSE REPEAT UNTIL FOR BREAK CONTINUE RETURN IMPORT _TRUE _FALSE DEF_CONST DEF_FUNC
%token LOG_BIN_OP LOG_UNI_OP REL_OP BOOL_OP FACT_N_NOT_OP 
%token IDENTIFIER CURLY PARENTHESIS SQUARE SEMICOLON COMMA ERROR

%start Program

%%
%%

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