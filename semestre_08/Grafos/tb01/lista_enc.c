#include "lista_enc.h"
#include<stdio.h>
#include<stdlib.h>

struct node {
    char letra;
    struct node *next;
};

struct list {
    long int size;
    struct Node *begin, *end;
};

struct node *Node_create(char caracter){
    struct node *Node = (struct node*)calloc(1, sizeof(struct node));
    Node->letra = caracter;
    Node->next = NULL; // Corrigindo o erro na atribuição do ponteiro para próximo nó
    return Node; // Adicionando o retorno do nó criado
}

struct list *List_create(){
    struct list *l = (struct list*)calloc(1, sizeof(struct list));
    l->begin = NULL;
    l->end = NULL;
    l->size = 0;
    return l;
};

bool isNull (struct list *l) {
    return l->size == 0;
};

void insert(struct list *l, char caracter){
    struct node *n = Node_create(caracter);
    if(isNull(l)){
        l->begin = n;
        l->end = n;
    }
    else{
        struct node *aux = l->begin;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}

void print(const struct list *l){
    struct node *aux = l->begin;
    while(aux != NULL){
        printf("%c", aux->letra);
        aux = aux->next;
    }
    printf("\n");
}

void free_l(struct list **l){
    struct list *lista = *l;
    struct node *p = lista->begin;
    struct node *aux = NULL;
    while(p != NULL){
        aux = p->next;
        free(p);
        p = aux;
    }
    free(lista);
    *l = NULL;
    printf("Lista liberada com sucesso!\n");

}
