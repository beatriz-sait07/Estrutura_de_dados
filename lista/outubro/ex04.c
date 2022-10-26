#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>


//criando estrutura do cadastro.
typedef struct cadastro_struc {
    char *nome_cad;
    char *rua_cad;
    char *cell_cad;
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

Dados *cadastro (Dados *p, char *nome, char *rua, char *cell) {
    Dados *aux= (Dados*)calloc(1, sizeof(Dados));
    p->nome_cad = nome;
    p->rua_cad = rua;
    p->cell_cad = cell;
    return p;
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

void insert_dados(List *lista, Dados *p){
    Node *dados = create_node(p);

    if(isNull(lista))
        lista->begin = dados;
    else{
        Node *aux = lista->begin;

        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = dados;
    }
    lista->size++;
}

void print_list(List *lista){
    Node *aux = lista->begin;

    if(isNull(lista))
        printf("lista vazia!\n");

    else{
        while(aux != NULL){
            printf("nome: %s\trua: %s\tcell: %s\n", aux->cad_node->nome_cad, aux->cad_node->rua_cad, aux->cad_node->cell_cad);
            aux = aux->next;
        }
        printf("fim do armazenamento!\n");
    }
}