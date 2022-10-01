#include"dupla_encad.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct _double_node{
    int val;
    struct _double_node *next;
    struct _double_node *prev;
}DoubleNode, Node;

typedef struct _double_list{
    Node *inicio;
    Node *fim;
    size_t size; // usado para tratar a possivel existencia de um tamanho muito grande
}Lista_dupla, List;

Node *Node_create(int val){
    Node *node = (Node*)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

List *List_create(){
    List *list = (List*)calloc(1, sizeof(List));

    list->inicio = NULL;
    list->fim = NULL;
    list->size = 0;

    return list;
}

bool _isNull(const Lista_dupla *list){
    return list->size == 0;
}

void destroy(Lista_dupla **ref_list){
    List *aux_list = ref_list; //inicia a desalocacao de 
    
    Node *p = aux_list->inicio; //usado para desalocar a casa atual
    Node *aux = NULL; //usado pata não perder a referencia

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(aux_list);
}