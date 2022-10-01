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
}
