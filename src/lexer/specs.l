%{
#include <stdio.h>
#include <string.h>
FILE *fp;
FILE *fp1;
%}

%x COMMENT
%x STRING
%x CHAR

%option noyywrap

%{
int line_count = 1;
%}

%%
"//"   { while (1) { int c = input(); if (c == EOF || c == '\n') break; } }
"/*"   { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>.   {  }

[ \t]+  ; // Ignore spaces and tabs
\n  { line_count++; }
for|repeat|if|else|return|const|step|char|string|vector|rational|matrix|uint8|uint16|uint32|uint64|int8|int16|int32|int64|real32|real64|fun|struct  { fprintf(fp1, "Keyword: %s\n", yytext); }
[0-9]+  { fprintf(fp1, "Number: %s\n", yytext); }
[[:alpha:]_][[:alnum:]_]* { fprintf(fp1, "Identifier: %s\n", yytext); }
; { fprintf(fp1, "Semicolon: %s\n",yytext); }
, { fprintf(fp1, "Comma: %s\n",yytext); }
[{] { fprintf(fp1, "Left Curly Brace: %s\n",yytext); }
[}] { fprintf(fp1, "Right Curly Brace: %s\n",yytext); }
\[ { fprintf(fp1, "Left Square Bracket: %s\n",yytext); }
\] { fprintf(fp1, "Right Square Bracket: %s\n",yytext); }
[(] { fprintf(fp1, "Left Parenthesis: %s\n",yytext); }
[)] { fprintf(fp1, "Right Parenthesis: %s\n",yytext); }
\"[^\"\n]*\" { fprintf(fp1, "String: %s\n", yytext); }
'[^'\n]*' { fprintf(fp1, "Character: %s\n", yytext); }
[+*/%]= { fprintf(fp1, "Compound Assignment: %s\n", yytext); }
[-+*/%] { fprintf(fp1, "Operator: %s\n", yytext); }
[&|^~] { fprintf(fp1, "Bitwise Operator: %s\n", yytext); }
\+\+   { fprintf(fp1, "Increment: %s\n",yytext); }
-- { fprintf(fp1, "Decrement: %s\n",yytext); }
==|!=|>=|<=|>|<  { fprintf(fp1, "Comparison Operator: %s\n", yytext); }
>>|<<  { fprintf(fp1, "Shift operator: %s\n", yytext); }
\+\- { fprintf(fp1, "Plus Minus: %s\n",yytext); }
\*\* { fprintf(fp1, "Exponent: %s\n",yytext); }
= { fprintf(fp1, "Assignment:%s\n",yytext); }
. { fprintf(fp1, "Unrecognized token: %c\n", yytext[0]); }

%%

int main() {
    fp = fopen("inputProgram.txt", "r");
    fp1 = fopen("tokenOutput.txt", "w");
    yyin = fp;
    yylex();
    fclose(fp);
    fclose(fp1);
    return 0;
}
