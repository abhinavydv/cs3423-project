#include "symbol_table.h"
#include <stdio.h>


int main(){
    printf("%s\n", format_string("abhinav %d hehe %d %s", "46", 5435, "sthr"));

    return 0;
}

void yyerror(char *s){
    printf("%s\n", s);
}
