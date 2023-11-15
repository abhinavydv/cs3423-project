%{
    #include "symbol_table.h"
    #define YYSTYPE state

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <assert.h>
    #include "y.tab.h"

    FILE *yyin, *yyout, *parsed_file;
    extern state yylval;
    extern position pos_info;


    #define ECHO fprintf(parsed_file, "%s", yytext); fflush(parsed_file);\
            update_pos_info(&pos_info, pos_info.row, pos_info.col+strlen(yytext));
    #define DUP yylval.text = strdup(yytext);
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
data_type       {string}|{char}|{int}|{uint}|{bool}|{real}|{complex}|{void}|{vector}

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


%%


[\"]{strings}*[\"]      {
                            ECHO;
                            fprintf(yyout, "String Constant: %s\n",yytext);
                            DUP;
                            return STRING;
                        }
[\']{character}*[\']    {
                            ECHO;
                            fprintf(yyout, "Character Constant: %s\n",yytext);
                            DUP;
                            return CHAR;
                        }
{number}+               {
                            ECHO;
                            fprintf(yyout, "Number Constant: %s\n",yytext);
                            DUP;
                            return INTEGER;
                        }
{number}+(\.{number}+)? {
                            ECHO;
                            fprintf(yyout, "Number Constant: %s\n",yytext);
                            DUP;
                            return REAL;
                        }

{data_type}             {
                            ECHO;
                            fprintf(yyout, "Data Type: %s\n",yytext);
                            DUP;
                            DUP;
                            return DATA_TYPE;
                        }
{curve}                 {
                            ECHO;
                            fprintf(yyout, "Curve: %s\n",yytext);
                            DUP;
                            return CURVE;
                        }
{struct}                {
                            ECHO;
                            fprintf(yyout, "Struct: %s\n",yytext);
                            DUP;
                            return STRUCT;
                        }

{if}                    {
                            ECHO;
                            fprintf(yyout, "Conditional: %s\n",yytext);
                            DUP;
                            return IF;
                        }
{else}                  {
                            ECHO;
                            fprintf(yyout, "Conditional: %s\n",yytext);
                            DUP;
                            return ELSE;
                        }
{repeat}                {
                            ECHO;
                            fprintf(yyout, "Loop: %s\n",yytext);
                            DUP;
                            return REPEAT;
                        }
{until}                 {
                            ECHO;
                            fprintf(yyout, "Loop Conditional: %s\n",yytext);
                            DUP;
                            return UNTIL;
                        }
{for}                   {
                            ECHO;
                            fprintf(yyout, "Loop: %s\n",yytext);
                            DUP;
                            return FOR;
                        }
{in}                    {
                            ECHO;
                            fprintf(yyout, "Loop IN: %s\n",yytext);
                            DUP;
                            return IN;
                        }
{dots}                  {
                            ECHO;
                            fprintf(yyout, "Dots: %s\n",yytext);
                            DUP;
                            return DOTS;
                        }
\.                      {
                            ECHO;
                            fprintf(yyout, "Dots: %s\n",yytext);
                            DUP;
                            return DOT;
                        }
{break}                 {
                            ECHO;
                            fprintf(yyout, "Break: %s\n",yytext);
                            DUP;
                            return BREAK;
                        }
{continue}              {
                            ECHO;
                            fprintf(yyout, "Continue: %s\n",yytext);
                            DUP;
                            return CONTINUE;
                        }
{return}                {
                            ECHO;
                            fprintf(yyout, "Return: %s\n",yytext);
                            DUP;
                            return RETURN;
                        }
{import}                {
                            ECHO;
                            fprintf(yyout, "Import: %s\n",yytext);
                            DUP;
                            return IMPORT;
                        }
{true}                  {
                            ECHO;
                            fprintf(yyout, "Bool True: %s\n",yytext);
                            DUP;
                            return TRUE;
                        }
{false}                 {
                            ECHO;
                            fprintf(yyout, "Bool False: %s\n",yytext);
                            DUP;
                            return FALSE;
                        }
{func}                  {
                            ECHO;
                            fprintf(yyout, "func: %s\n",yytext);
                            DUP;
                            return FUNC;
                        }
{diff}                  {
                            ECHO;
                            fprintf(yyout, "diff: %s\n",yytext);
                            DUP;
                            return DIFF;
                        }

{arithmetic_binaryOp}   {
                            ECHO;
                            fprintf(yyout, "Arithmetic Bin Op: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{increment}             {
                            ECHO;
                            fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);
                            DUP;
                            return INCREMENT;
                        }
{decrement}             {
                            ECHO;
                            fprintf(yyout, "Arithmetic Uni Op: %s\n",yytext);
                            DUP;
                            return DECREMENT;
                        }
{arrow}                 {
                            ECHO;
                            fprintf(yyout, "Arrow: %s\n",yytext);
                            DUP;
                            return ARROW;
                        }
{rel_Op}                {
                            ECHO;
                            fprintf(yyout, "Relational Op: %s\n",yytext);
                            DUP;
                            return COMPARE;
                        }
{bit_Op}                {
                            ECHO;
                            fprintf(yyout, "Boolean Op: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{shift}                 {
                            ECHO;
                            fprintf(yyout, "Shift Op: %s\n",yytext);
                            DUP;
                            return SHIFT;
                        }
"&&"                    {
                            ECHO;
                            fprintf(yyout, "Logical Op: %s\n",yytext);
                            DUP;
                            return AND;
                        }
"||"                    {
                            ECHO;
                            fprintf(yyout, "Logical Op: %s\n",yytext);
                            DUP;
                            return OR;
                        }
{fact_n_not}            {
                            ECHO;
                            fprintf(yyout, "Log/Rel Uni Op: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{gt}                    {
                            ECHO;
                            fprintf(yyout, "Relational Op: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{lt}                    {
                            ECHO;
                            fprintf(yyout, "Relational Op: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{augAssign}             {
                            ECHO;
                            fprintf(yyout, "Augmented Assignment: %s\n",yytext);
                            DUP;
                            return AUG_ASSIGN;
                        }


{identifier}            {
                            ECHO;
                            fprintf(yyout, "Identifier: %s\n",yytext);
                            DUP;
                            DUP;
                            return IDENTIFIER;
                        }
{dollar}{identifier}    {
                            ECHO;
                            fprintf(yyout, "Dollar: %s\n",yytext);
                            DUP;
                            return DOLLAR_ID;
                        }


{curly}                 {
                            ECHO;
                            fprintf(yyout, "Curly: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{parenthesis}           {
                            ECHO;
                            fprintf(yyout, "Parenthesis: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{square}                {
                            ECHO;
                            fprintf(yyout, "Square Bracket: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{semi_col}              {
                            ECHO;
                            fprintf(yyout, "Semi Colon: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }
{comma}                 {
                            ECHO;
                            fprintf(yyout, "Comma: %s\n",yytext);
                            DUP;
                            return yytext[0];
                        }

{blank}                 {
                            ECHO;
                        }
{newline}               {
                            fprintf(parsed_file, "\n"); update_pos_info(&pos_info, pos_info.row+1, 0);
                        }
{comment}               {fprintf(parsed_file, " ");}    // print a space instead of comment
.                       {printf("Lexer Error at Line Number %d\n",pos_info.row); fflush(yyout); exit(0);}

%%

int yywrap(void){

DUP;
    return 1;
}
