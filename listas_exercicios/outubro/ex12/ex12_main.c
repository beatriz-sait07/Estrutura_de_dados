#include "ex12.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Estatica *s = create_estatica(5);
    int val;
    int aux;
    estatica_push(s, 20);
    estatica_push(s, 30);
    estatica_push(s, 40);
    estatica_push(s, 50);
    estatica_push(s, 60);
    estatica_print(s);
    printf("escolha um valor entre os elementos acima para ser retirado da pilha: ");
    scanf("%d", &val);
    aux = estatica_pop(s, val);
    estatica_print(s);



    return 0;
}