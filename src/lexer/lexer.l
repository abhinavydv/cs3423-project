%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <assert.h>
    #include "y.tab.h"

    FILE *yyin, *yyout, *parsed_file;
    int line_count;

    #define ECHO fprintf(parsed_file, "%s", yytext)
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

/*Datatype*/
string          (string)
char            (char)
int             (int|int8|int16|int32|int64)
uint            (uint|uint8|uint16|uint32|uint64)
bool            (bool)
real            (real|real32|real64)
complex         (complex)
curve           (curve)
void            (void)
vector          (vector)
matrix          (matrix)
rational        (rational)
data_type       {string}|{char}|{int}|{uint}|{bool}|{real}|{complex}|{void}|{vector}|{matrix}|{rational}

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
dollar          "$"

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


[\"]{strings}*[\"]      {ECHO; fprintf(yyout, "String Constant: %s\n",yytext);      return STRING;}
[\']{character}*[\']    {ECHO; fprintf(yyout, "Character Constant: %s\n",yytext);   return CHAR;}
{number}+               {ECHO; fprintf(yyout, "Number Constant: %s\n",yytext);      return INTEGER;}
{number}+(\.{number}+)? {ECHO; fprintf(yyout, "Number Constant: %s\n",yytext);      return REAL;}

{data_type}             {ECHO; fprintf(yyout, "Data Type: %s\n",yytext);           return DATA_TYPE;}
{curve}                 {ECHO; fprintf(yyout, "Curve: %s\n",yytext);               return CURVE;}
{struct}                {ECHO; fprintf(yyout, "Struct: %s\n",yytext);              return STRUCT;}

{if}                    {ECHO; fprintf(yyout, "Conditional: %s\n",yytext);      return IF;}
{else}                  {ECHO; fprintf(yyout, "Conditional: %s\n",yytext);      return ELSE;}
{repeat}                {ECHO; fprintf(yyout, "Loop: %s\n",yytext);             return REPEAT;}
{until}                 {ECHO; fprintf(yyout, "Loop Conditional: %s\n",yytext); return UNTIL;}
{for}                   {ECHO; fprintf(yyout, "Loop: %s\n",yytext);             return FOR;}
{in}                    {ECHO; fprintf(yyout, "Loop IN: %s\n",yytext);          return IN;}
{dots}                  {ECHO; fprintf(yyout, "Dots: %s\n",yytext);             return DOTS;}
\.                      {ECHO; fprintf(yyout, "Dots: %s\n",yytext);             return DOT;}
{break}                 {ECHO; fprintf(yyout, "Break: %s\n",yytext);            return BREAK;}
{continue}              {ECHO; fprintf(yyout, "Continue: %s\n",yytext);         return CONTINUE;}
{return}                {ECHO; fprintf(yyout, "Return: %s\n",yytext);           return RETURN;}
{import}                {ECHO; fprintf(yyout, "Import: %s\n",yytext);           return IMPORT;}
{true}                  {ECHO; fprintf(yyout, "Bool True: %s\n",yytext);        return TRUE;}
{false}                 {ECHO; fprintf(yyout, "Bool False: %s\n",yytext);       return FALSE;}
{func}                  {ECHO; fprintf(yyout, "func: %s\n",yytext);             return FUNC;}
{diff}                  {ECHO; fprintf(yyout, "diff: %s\n",yytext);             return DIFF;}

{arithmetic_binaryOp}   {ECHO; fprintf(yyout, "Arithmetic Bin Op: %s\n",yytext);       return yytext[0];}
{increment}             {ECHO; fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);       return INCREMENT;}
{decrement}             {ECHO; fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);       return DECREMENT;}
{arrow}                 {ECHO; fprintf(yyout, "Arrow: %s\n",yytext);                return ARROW;}
{rel_Op}                {ECHO; fprintf(yyout, "Relational Op: %s\n",yytext);        return COMPARE;}
{bit_Op}                {ECHO; fprintf(yyout, "Boolean Op: %s\n",yytext);           return yytext[0];}
{shift}                 {ECHO; fprintf(yyout, "Shift Op: %s\n",yytext);             return SHIFT;}
"&&"                    {ECHO; fprintf(yyout, "Logical Op: %s\n",yytext);           return AND;}
"||"                    {ECHO; fprintf(yyout, "Logical Op: %s\n",yytext);           return OR;}
{fact_n_not}            {ECHO; fprintf(yyout, "Log/Rel Uni Op: %s\n",yytext);       return yytext[0];}
{gt}                    {ECHO; fprintf(yyout, "Relational Op: %s\n",yytext);        return yytext[0];}
{lt}                    {ECHO; fprintf(yyout, "Relational Op: %s\n",yytext);        return yytext[0];}
{augAssign}             {ECHO; fprintf(yyout, "Augmented Assignment: %s\n",yytext); return AUG_ASSIGN;}


{identifier}            {ECHO; fprintf(yyout, "Identifier: %s\n",yytext);     return IDENTIFIER;}
{dollar}{identifier}    {ECHO; fprintf(yyout, "Dollar: %s\n",yytext);         return DOLLAR_ID;}


{curly}                 {ECHO; fprintf(yyout, "Curly: %s\n",yytext);            return yytext[0];}
{parenthesis}           {ECHO; fprintf(yyout, "Parenthesis: %s\n",yytext);      return yytext[0];}
{square}                {ECHO; fprintf(yyout, "Square Bracket: %s\n",yytext);   return yytext[0];}
{semi_col}              {ECHO; fprintf(yyout, "Semi Colon: %s\n",yytext);       return yytext[0];}
{comma}                 {ECHO; fprintf(yyout, "Comma: %s\n",yytext);            return yytext[0];}

{blank}                 {ECHO;}
{newline}               {ECHO; line_count++; }
{comment}               {fprintf(parsed_file, " ");}    // print a space instead of comment
.                       {printf("Lexer Error at Line Number %d\n",line_count); fflush(yyout); exit(0);}

%%

int yywrap(void){

    return 1;
}
