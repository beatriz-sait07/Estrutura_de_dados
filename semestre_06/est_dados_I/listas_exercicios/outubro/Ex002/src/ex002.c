/*Escreva um programa que remova todos os elementos com chaves pares de uma lista encadeada*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"ex002.h"

typedef struct _node{
    int val;
    struct _node *next;
} Node;

typedef struct _linkedList{
    Node *begin;
    Node *end;
    int size;
} LinkedList;

bool is_null(const LinkedList *L){
    return L->size == 0;
}

Node *node_create(int val){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

LinkedList *list_create(){
   LinkedList *L = (LinkedList*)calloc(1, sizeof(LinkedList));
   L->begin = NULL;
   L->end = NULL;
   L->size = 0;

   return L; 
}   

int add_last(LinkedList *L, int val){

    Node *new = node_create(val);

    if(is_null(L)){
        L->begin = L->end = new;
    }else{
        L->end->next = new;
        L->end = L->end->next;
    }
    L->size++;
}

void print_list(const LinkedList *L){
    Node *aux = L->begin;
    printf("Lista -> ");
    while(aux != NULL){
        printf("|%d| -> ", aux->val);
        aux = aux->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", L->size);
    printf("Begin: %d\n", L->begin->val);
    printf("End: %d\n", L->end->val);
}

void remove_pair(LinkedList *L){
    Node *p = L->begin;
    Node *aux = p->next;
    Node *ant = NULL;

    while(aux != NULL){
        if(p == L->begin){
            if(p->val%2 == 0){      // Se o Begin for par
                L->begin = aux;    
                free(p);
                p = L->begin;      
                aux = aux->next;
                L->size--;   
            }else{  // Se for impar, todos os ponteiros pulam pra frente:
                ant = p;
                p = p->next;
                aux = aux->next;
            }
        }else{
            if(p->val%2 == 0){      // Se valor par estiver no meio
                ant->next = aux;
                free(p);
                p = aux;
                aux = aux->next;
                L->size--;
            }else{      // Se for impar, todos os ponteiros pulam pra frente:
                ant = p;
                p = p->next;
                aux = aux->next;
            }
        }
    }
}
