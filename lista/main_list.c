#include<stdio.h>
#include<stdlib.h>
#include"encadeada_simples.h"

int main (){
    Lista *lista = Lista_create();
    printf("lista encadeada simples\n"); 
    add_inicio(lista, 2);
    insert_ordem(lista, 6);
    insert_ordem(lista, 12);
    insert_ordem(lista, 9);
    print(lista);
}