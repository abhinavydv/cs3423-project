%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <assert.h>
    // #include "y.tab.h"

    FILE *yyin, *yyout;
    int line_count;
    
%}


/*Constant*/
number          [0-9]   
alpha           [a-zA-Z_]
alphaNumber     {number}|{alpha}
strings         [^\\\"]*(\\.)?
character       [^\\\']*(\\.)?

/*Defined Variables (Add more) */
defined_const   (e|pi)   
defined_func    (sum|product)

/*Spaces and Newline*/
blank           [ \t]
newline         (\n)

/*Datatype*/
string          (string)
char            (char)
int             (int)
bool            (bool)
real            (real)
complex         (complex)
curve           (curve)
void            (void)
vector          (vector)
struct          (struct)

/*Keywords*/
if              (if)
repeat          (repeat)
until           (until)
for             (for)
else            (else)
return          (return)
break           (break)
continue        (continue)
true            (true)
false           (false)

/*Logical Operator*/
fact_n_not      (!)

log_binaryOp    [-+/*=]|("->")
log_uniaryOp    ("++")|("--") 

/*Relational Operator*/
rel_Op          ("==")|("!=")|(">")|("<")|(">=")|("<=")|("&&")|("||")

/*Boolean Operator*/
bool_Op         (~)|(&)|("|")|(>>)|(<<)|(^^)

/*Identifier*/
identifier      {alpha}{alphaNumber}*

/*Comments*/
mline_comment   \/\*([^*]|\*(?!\/))*\*\/
sline_comment   \/\/[^(?<!\\)\\(?=n)]\\n
comment         {mline_comment}|{sline_comment}

/*Others*/
semi_col        (;)
comma           (,)
curly           [}{]
square          [\[\]]
parenthesis     [)(]


%{
int line_count = 1;
%}

%%


[\"]{strings}*[\"]      {fprintf(yyout, "String Constant: %s\n",yytext);      return STRING_CONST;}
[\']{character}*[\']    {fprintf(yyout, "Character Constant: %s\n",yytext);   return CHAR_CONST;}
{number}+(\.{number}*)? {fprintf(yyout, "Number Constant: %s\n",yytext);      return NUM_CONST;}


{int}                   {fprintf(yyout, "Integer Datatype: %s\n",yytext);     return INT;}
{string}                {fprintf(yyout, "String Datatype: %s\n",yytext);      return STRING;}
{char}                  {fprintf(yyout, "Char Dataype: %s\n",yytext);         return CHAR;}
{bool}                  {fprintf(yyout, "Bool Datatype: %s\n",yytext);        return BOOL;}
{real}                  {fprintf(yyout, "Real Datatype: %s\n",yytext);        return REAL;}
{complex}               {fprintf(yyout, "Complex Datatype: %s\n",yytext);     return COMPLEX;}
{curve}                 {fprintf(yyout, "Curve Datatype: %s\n",yytext);       return CURVE;}
{void}                  {fprintf(yyout, "Void Datatype: %s\n",yytext);        return VOID;}
{vector}                {fprintf(yyout, "Vector Datatype: %s\n",yytext);      return VECTOR;}
{struct}                {fprintf(yyout, "Struct Datatype: %s\n",yytext);      return STRUCT;}


{if}                    {fprintf(yyout, "Conditional: %s\n",yytext);      return IF;}
{else}                  {fprintf(yyout, "Conditional: %s\n",yytext);      return ELSE;}
{repeat}                {fprintf(yyout, "Loop: %s\n",yytext);             return REPEAT;}
{until}                 {fprintf(yyout, "Loop Conditional: %s\n",yytext); return UNTIL;}
{for}                   {fprintf(yyout, "Loop: %s\n",yytext);             return FOR;}
{break}                 {fprintf(yyout, "Break: %s\n",yytext);            return BREAK;}
{continue}              {fprintf(yyout, "Continue: %s\n",yytext);         return CONTINUE;}
{return}                {fprintf(yyout, "Return: %s\n",yytext);           return RETURN;}
{true}                  {fprintf(yyout, "Bool True: %s\n",yytext);        return _TRUE;}
{false}                 {fprintf(yyout, "Bool False: %s\n",yytext);       return _FALSE;}


{defined_const}         {fprintf(yyout, "Defined Constant: %s\n",yytext);   return DEF_CONST;}
{defined_func}          {fprintf(yyout, "Defined Function: %s\n",yytext);   return DEF_FUNC;}


{log_binaryOp}          {fprintf(yyout, "Logical Bin Op: %s\n",yytext);       return LOG_BIN_OP;}
{log_uniaryOp}          {fprintf(yyout, "Logical Uni Op: %s\n",yytext);       return LOG_UNI_OP;}
{rel_Op}                {fprintf(yyout, "Relational Op: %s\n",yytext);        return REL_OP;}
{bool_Op}               {fprintf(yyout, "Boolean Op: %s\n",yytext);           return BOOL_OP;}
{fact_n_not}            {fprintf(yyout, "Log/Rel Uni Op: %s\n",yytext);       return FACT_N_NOT_OP;}


{identifier}            {fprintf(yyout, "Identifier: %s\n",yytext);     return IDENTIFIER;}


{curly}                 {fprintf(yyout, "Curly: %s\n",yytext);            return CURLY;}
{parenthesis}           {fprintf(yyout, "Parenthesis: %s\n",yytext);      return PARENTHESIS;}
{square}                {fprintf(yyout, "Square Bracket: %s\n",yytext);   return SQUARE;}


{semi_col}              {fprintf(yyout, "Semi Colon: %s\n",yytext);       return SEMICOLON;}

{comma}                 {fprintf(yyout, "Comma: %s\n",yytext);        return COMMA;}

{blank}                 {/* Ignore spaces and tabs*/ }
{newline}               { line_count++; }
.                       {printf("Syntax Error at Line Number %d\n",line_count); fflush(yyout); return ERROR;}

%%

int yywrap(void){

    return 1;
}

int main(int argc, char *argv[]){


    if (argc != 3){
        printf("Format not Used: [executable] [input file] [c output file]\n");
        assert(0);
    }
 
 
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");

    yylex();

    
    return 0;
}