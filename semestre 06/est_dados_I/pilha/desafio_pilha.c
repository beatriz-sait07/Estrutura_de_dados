#include"desafio_pilha.h"
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
}List, List;

Node *create_node(int val){
    Node *node = (Node*)calloc(1, sizeof(Node));

    node->next = NULL;
    node->prev = NULL;
    node->val = val;

    return node;
}

List *create_list(){
    List *list = (List*)calloc(1, sizeof(List));

    list->inicio = NULL;
    list->fim = NULL;
    list->size = 0;

    return list;
}

bool _isNull_pilha(const List *pilha){
    return pilha->size == 0;
}

void destroy_pilha(List **ref_pilha){
    List *aux_list = *ref_pilha;
    
    Node *p = aux_list->inicio;
    while(p != NULL){
        Node *aux = p;
        aux = p;
        p = p->next;
        free(aux);
    }
    free(aux_list);
    *ref_pilha = NULL;
    printf("lista totalmente desalocada!\n");
}

void add_final_pilha(List *pilha, int val){
    Node *aux = create_node(val);

    if(_isNull_pilha(pilha))pilha->inicio = pilha->fim = aux;
    else{

        pilha->fim->next = aux; 
        aux->prev = pilha->fim; 
        pilha->fim = aux;
    }

    pilha->size++;
}



void imprimir_pilha(const List *list){
    Node *aux = list->inicio;

    while(aux != NULL){
        printf("%d -> ", aux->val);
        aux = aux->next;
    }
    printf("NULL");

    printf("\ntamanho = %ld", list->size);
}

void merge_pilha(List *pilha, List *pilha1){
    pilha1->inicio->prev = pilha->fim;
    pilha->fim->next = pilha1->inicio;
    pilha->fim = pilha1->fim;
    pilha->size = pilha->size + pilha1->size;
    
}
