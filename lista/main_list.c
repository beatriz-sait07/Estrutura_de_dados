#include<stdio.h>
#include<stdlib.h>
#include"encadeada_simples.h"

int main (){
    Lista *lista = Lista_create();
    printf("lista encadeada simples\n");
    add_inicio(lista, 2);
    add_final(lista, 3);
    add_final(lista, 6);
    add_final(lista, 4);
    add_final(lista, 9);
    print(lista);
}