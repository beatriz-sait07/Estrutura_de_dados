#include "ex11.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    Estatica *s1 = create_estatica(50);
    Estatica *s2 = create_estatica(50);

    printf("entrando exatamente 80 elementos...\n");
    int val=0;
    while(val < 80){
        validando_entradas(s1, s2, val);
        val++;
    }
    estatica_print(s1);
    estatica_print(s2);
    //----------------------------------------------------
    printf("entrando 100 elementos...\n");
    val=0;
        while(val < 101){
        validando_entradas(s1, s2, val);
        val++;
    }

    return 0;
}