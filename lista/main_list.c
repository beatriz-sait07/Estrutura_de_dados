#include<stdio.h>
#include<stdlib.h>
#include"encadeada_simples.h"
#include"dupla_encad.h"


int main (){
    printf("lista encadeada simples\n");
    Lista *lista_end = Lista_create();
    add_inicio(lista_end, 2);
    insert_ordem(lista_end, 6);
    insert_ordem(lista_end, 12);
    insert_ordem(lista_end, 9);
    insert_ordem(lista_end, 6);
    insert_ordem(lista_end, 8);
    insert_ordem(lista_end, 16);
    insert_ordem(lista_end, 25);
    insert_ordem(lista_end, 13);
    insert_ordem(lista_end, 32);
    insert_ordem(lista_end, 3);
    insert_ordem(lista_end, 7);
    insert_ordem(lista_end, 19);
    insert_ordem(lista_end, 11);
    insert_ordem(lista_end, 14);
    print(lista_end);
    printf("\nexcluindo o primeiro elemento\n");
    remover_elemento(lista_end, 2);
    print(lista_end);
    printf("removendo elementos iguais\n");
    remover_elemento(lista_end, 6);
    print(lista_end);
    printf("removendo elemento do meio da lista\n");
    remover_elemento(lista_end, 12);
    print(lista_end);
    printf("removendo elemento do final\n");
    remover_elemento(lista_end, 32);
    print(lista_end);
    printf("buscando elemento na lista\n");
    busca_elemento(lista_end, 6);
    printf("removendo todos os elementos\n");
    remover_todos_elementos(&lista_end);
    printf("---------------------------------------\n\n");
    printf("lista duplamente encadeada\n\n");
    Lista *lista_dupla_enc = Lista_create();
    
}