#include "list_out.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_simples
{
    char *nome, *rua;
    struct node_simples *next;
}Node;

typedef struct linkedlist
{
    Node *begin;
    Node *end;
    int cont;
} List;

//veriricando se esta vazia
bool _isNull(List *lista){
    return lista->cont == 0;
}

//criando nó
Node *create_node(char nome[], char rua[]){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->nome = nome;
    node->rua = rua;
    node->next = NULL;
    return node;
}

List *create_lista(){
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;
    lista->cont = 0;
    return lista;
}

//nm = nome, road/rd = rua
void insert_dados(List *list, char *n, char *r){
    Node *dados = create_node(n, r);
    if(_isNull(list))list->begin = dados;
    else{
        Node *aux = list->begin;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = dados;
    }
    list->cont++;
}

void print_list(List *lista){
    Node *p = lista->begin;
    if(_isNull(lista))
        printf("lista vazia!\n");
    else{
        while(p != NULL){
            printf("nome: %s\trua: %s", p->nome, p->rua);
        }
    }
}