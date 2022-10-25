#include "desafio_pilha.h"
#include <stdio.h>

int main (){
    List *prim_pilha = create_list();
    List *seg_pilha = create_list();

    // primeira pilha
    printf("primeira pilha:\n");
    add_final_pilha(prim_pilha, 0);
    add_final_pilha(prim_pilha, 2);
    add_final_pilha(prim_pilha, 1);
    add_final_pilha(prim_pilha, 9);
    add_final_pilha(prim_pilha, 3);
    imprimir_pilha(prim_pilha);

    printf("\n\nsegunda pilha:\n");
    // segunda pila
    add_final_pilha(seg_pilha, 10);
    add_final_pilha(seg_pilha, 16);
    add_final_pilha(seg_pilha, 12);
    add_final_pilha(seg_pilha, 19);
    imprimir_pilha(seg_pilha);

    merge_pilha(prim_pilha, seg_pilha);
    imprimir_pilha(prim_pilha);
    printf("\n\n");

    return 0;
}