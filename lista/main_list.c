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
    insert_ordem(lista, 6);
    insert_ordem(lista, 8);
    insert_ordem(lista, 16);
    insert_ordem(lista, 0);
    print(lista);
    printf("excluindo o primeiro elemento\n");
    remover_elemento(lista, 0);
    print(lista);
    printf("removendo elementos iguais\n");
    remover_elemento(lista, 6);
    print(lista);
    printf("removendo elemento do meio da lista\n");
    remover_elemento(lista, 12);
    print(lista);
}