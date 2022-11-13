#include "ex12.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Estatica *s = create_estatica(5);
    Estatica *s1 = create_estatica(5);
    char valor_top;

    valor_top = estatica_push(s, "a");
    estatica_pop(s, s1, "c");
    return 0;
}