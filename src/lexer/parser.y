%{
    #include <stdio.h>
    #include <assert.h>
    #define YYSTYPE double /* double type for yacc stack */
    
    extern FILE  * yyin, *yyout;
    
%}

%token STRING_CONST CHAR_CONST NUM_CONST 
%token INT STRING CHAR BOOL REAL COMPLEX CURVE VOID VECTOR 
%token IF ELSE REPEAT UNTIL FOR BREAK CONTINUE RETURN IMPORT _TRUE _FALSE DEF_CONST DEF_FUNC STRUCT FUNC
%token LOG_BIN_OP LOG_UNI_OP REL_OP BOOL_OP 
%token IDENTIFIER ERROR

%start Program

%%
Program : Program Function
        | Program  GlobalStatement 
        | Function                 // Atleast One function should be there in the program

Function: FUNC FunctionDecl '{' FunctionBody '}'

FunctionDecl: DataType  IDENTIFIER '(' Parameters ')' 

DataType    : CPP_Type
            | CURVE

CPP_Type    : INT
            | STRING
            | CHAR
            | BOOL 
            | REAL
            | COMPLEX
            | VOID 
            | VECTOR '<' DataType '>'
            | IDENTIFIER
            | CPP_Type '[' ']'

Parameters  : MoreParameters   
            |                  

MoreParameters  : MoreParameters ',' CPP_Type IDENTIFIER
                | MoreParameters ',' CURVE IDENTIFIER variable
                | CURVE IDENTIFIER variable  // f(x)
                | CPP_Type IDENTIFIER

variable        : '(' Identifiers ')' 
                | 

FunctionBody: FunctionBody LocalStatement
            |

GlobalStatement: Decl
               | Struct

Struct  : StructDecl '{' StructBody '}' ';'

StructDecl: STRUCT IDENTIFIER

StructBody  : StructBody Decl
            | Decl

Decl    : CPP_Type  Identifiers ';' 
        | CURVE  Cur_identifiers ';'

Cur_identifiers : Cur_identifiers ',' IDENTIFIER variable
                | IDENTIFIER variable

Identifiers: Identifiers ',' IDENTIFIER
           | IDENTIFIER     

LocalStatement: 
              | 

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