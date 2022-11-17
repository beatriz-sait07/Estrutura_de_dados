#include "ex001.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Node_simples *begin = NULL;

    begin = add_final(begin, 3);
    begin = add_final(begin, 5);
    begin = add_final(begin, 9);
    begin = add_final(begin, 17);
    begin = add_final(begin, 23);
    begin = add_final(begin, 31);
    print(begin);
    printf(" NULL\n");
    remover(begin, 9);
    print(begin);
    printf(" NULL\n\n");
    
    return 0;
}