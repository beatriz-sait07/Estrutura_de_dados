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
    insert_ordem(lista, 25);
    insert_ordem(lista, 13);
    insert_ordem(lista, 32);
    insert_ordem(lista, 3);
    insert_ordem(lista, 7);
    insert_ordem(lista, 19);
    insert_ordem(lista, 11);
    insert_ordem(lista, 14);
    print(lista);
    printf("\nexcluindo o primeiro elemento\n");
    remover_elemento(lista, 2);
    print(lista);
    printf("removendo elementos iguais\n");
    remover_elemento(lista, 6);
    print(lista);
    printf("removendo elemento do meio da lista\n");
    remover_elemento(lista, 12);
    print(lista);
    printf("removendo elemento do final\n");
    remover_elemento(lista, 32);
    print(lista);
    printf("buscando elemento na lista\n");
    busca_elemento(lista, 6);
    printf("removendo todos os elementos\n");
    remover_todos_elementos(&lista);
}