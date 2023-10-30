%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <assert.h>
    #include "y.tab.h"

    FILE *yyin, *yyout;
    int line_count;
%}


/*Constant*/
number          [0-9]   
alpha           [a-zA-Z_]
alphaNumber     {number}|{alpha}
strings         [^\\\"]*(\\.)?
character       [^\\\']*(\\.)?

/*Spaces and Newline*/
blank           [ \t]
newline         (\n)

/* TODO: Add int8, 16, 32 etc */
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
rational        (rational)
data_type       {string}|{char}|{int}|{bool}|{real}|{complex}|{void}|{vector}|{rational}

/*Keywords*/
struct          (struct)
if              (if)
else            (else)
repeat          (repeat)
until           (until)
for             (for)
in              (in)
return          (return)
break           (break)
continue        (continue)
true            (true)
false           (false)
import          (import)
func            (func)
dots            ".."
diff            (D)

/*Arithmetic Operator*/
fact_n_not      (!)
arithmetic_binaryOp    [-+/*=%^]
arrow           "->"
decrement       "++"
increment       "--"


/*Relational Operator*/
rel_Op          ("==")|("!=")|(">=")|("<=")
gt              (">")
lt              ("<")

augAssign       ("+=")|("-=")|("*=")|("/=")|("%=")

/*Bitwise Operator*/
bit_Op         (~)|(&)|("|")
shift           (<<)|(>>)

/*Identifier*/
identifier      {alpha}{alphaNumber}*

/*Comments*/
mline_comment   \/\*([^*]|\*[^\/])*\*\/
sline_comment   \/\/[^\n]*
comment         {mline_comment}|{sline_comment}

/*Others*/
semi_col        (;)
comma           (,)
curly           [}{]
parenthesis     [)(]
square          [\[\]]


%{
int line_count = 1;
%}

%%


[\"]{strings}*[\"]      {fprintf(yyout, "String Constant: %s\n",yytext);      return STRING;}
[\']{character}*[\']    {fprintf(yyout, "Character Constant: %s\n",yytext);   return CHAR;}
{number}+               {fprintf(yyout, "Number Constant: %s\n",yytext);      return INTEGER;}
{number}+(\.{number}+)? {fprintf(yyout, "Number Constant: %s\n",yytext);      return REAL;}

{data_type}             {fprintf(yyout, "Data Type: %s\n",yytext);           return DATA_TYPE;}
{curve}                 {fprintf(yyout, "Curve: %s\n",yytext);               return CURVE;}
{struct}                {fprintf(yyout, "Struct: %s\n",yytext);              return STRUCT;}

{if}                    {fprintf(yyout, "Conditional: %s\n",yytext);      return IF;}
{else}                  {fprintf(yyout, "Conditional: %s\n",yytext);      return ELSE;}
{repeat}                {fprintf(yyout, "Loop: %s\n",yytext);             return REPEAT;}
{until}                 {fprintf(yyout, "Loop Conditional: %s\n",yytext); return UNTIL;}
{for}                   {fprintf(yyout, "Loop: %s\n",yytext);             return FOR;}
{in}                    {fprintf(yyout, "Loop IN: %s\n",yytext);          return IN;}
{dots}                  {fprintf(yyout, "Dots: %s\n",yytext);             return DOTS;}
{break}                 {fprintf(yyout, "Break: %s\n",yytext);            return BREAK;}
{continue}              {fprintf(yyout, "Continue: %s\n",yytext);         return CONTINUE;}
{return}                {fprintf(yyout, "Return: %s\n",yytext);           return RETURN;}
{import}                {fprintf(yyout, "Import: %s\n",yytext);           return IMPORT;}
{true}                  {fprintf(yyout, "Bool True: %s\n",yytext);        return TRUE;}
{false}                 {fprintf(yyout, "Bool False: %s\n",yytext);       return FALSE;}
{func}                  {fprintf(yyout, "func: %s\n",yytext);             return FUNC;}
{diff}                  {fprintf(yyout, "diff: %s\n",yytext);             return DIFF;}

{arithmetic_binaryOp}   {fprintf(yyout, "Arithmetic Bin Op: %s\n",yytext);       return yytext[0];}
{increment}             {fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);       return INCREMENT;}
{decrement}             {fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);       return DECREMENT;}
{arrow}                 {fprintf(yyout, "Arrow: %s\n",yytext);                return ARROW;}
{rel_Op}                {fprintf(yyout, "Relational Op: %s\n",yytext);        return COMPARE;}
{bit_Op}                {fprintf(yyout, "Boolean Op: %s\n",yytext);           return yytext[0];}
{shift}                 {fprintf(yyout, "Shift Op: %s\n",yytext);             return SHIFT;}
"&&"                    {fprintf(yyout, "Logical Op: %s\n",yytext);           return AND;}
"||"                    {fprintf(yyout, "Logical Op: %s\n",yytext);           return OR;}
{fact_n_not}            {fprintf(yyout, "Log/Rel Uni Op: %s\n",yytext);       return yytext[0];}
{gt}                    {fprintf(yyout, "Relational Op: %s\n",yytext);        return yytext[0];}
{lt}                    {fprintf(yyout, "Relational Op: %s\n",yytext);        return yytext[0];}
{augAssign}             {fprintf(yyout, "Augmented Assignment: %s\n",yytext); return AUG_ASSIGN;}

{identifier}            {fprintf(yyout, "Identifier: %s\n",yytext);     return IDENTIFIER;}


{curly}                 {fprintf(yyout, "Curly: %s\n",yytext);            return yytext[0];}
{parenthesis}           {fprintf(yyout, "Parenthesis: %s\n",yytext);      return yytext[0];}
{square}                {fprintf(yyout, "Square Bracket: %s\n",yytext);   return yytext[0];}
{semi_col}              {fprintf(yyout, "Semi Colon: %s\n",yytext);       return yytext[0];}
{comma}                 {fprintf(yyout, "Comma: %s\n",yytext);            return yytext[0];}

{blank}                 {/* Ignore spaces and tabs*/ }
{newline}               { line_count++; }
{comment}               {/* Ignore comments*/ }
.                       {printf("Lexer Error at Line Number %d\n",line_count); fflush(yyout); exit(0);}

%%

int yywrap(void){

    return 1;
}
