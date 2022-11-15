#include "ex010.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_simples {
    char *string;
    struct node_simples *next;
    struct node_simples *prev;
    
} Node;

typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size_list;
} List;

bool isNull(List *lista){
    return lista->begin == NULL;
}

Node *create_node(char *s){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->string = s;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->size_list = 0;
    return list;

}

void destroy (List **ref_list){
    List *l = *ref_list;
    Node *p = l->begin;
    Node *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    *ref_list = NULL;
    printf("LISTA TOTALMENTE DESALOCADA!\n\n");

}

void insert_dados(List *lista, char *s){
    Node *aux = create_node(s);

    if(isNull(lista))lista->begin = lista->end = aux;
    else{

        lista->end->next = aux;
        aux->prev = lista->end; 
        lista->end = aux;

    }

    lista->size_list++;
}