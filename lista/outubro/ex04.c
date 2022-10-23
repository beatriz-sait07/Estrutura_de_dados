#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>

//criando estrutura do cadastro.
typedef struct cadastro_struc {
    char nome_cad[50];
    char rua_cad[50];
    int cell_cad[15];
} Dados;

// criando nó para armazernar os cada cadastro.
typedef struct node_simples {
    Dados *cad_node;
    struct node_simples *next;
} Node;

//criando lista para armazenar um conjunto de cadastros.
typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size;
} List;

//verifica se a lista está vazia.
bool isNull(List *lista){
    return lista->size == 0;
}

void cadastro (Dados *p, char nome[], char rua[], int cell[]) {
    p->nome_cad[50] = nome;
    p->rua_cad[50] = rua;
    p->cell_cad[15] = cell;
}

Node *create_node(Dados *p){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cad_node = p;
    node->next = NULL;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;

}

void print_list(List *lista){
    if(isNull(lista))
        printf("lista vazia!\n");
    else{
        while(lista != NULL){
            printf("nome: %s\trua: %s\tcelular: %d\n");
        }
        printf("fim do armazenamento!\n");
    }
}