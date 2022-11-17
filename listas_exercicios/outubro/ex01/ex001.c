#include "ex001.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_simples{
    int valor;
    struct _node_simples *next;
}Node_simples;

typedef struct _lista_simples{
    Node_simples *inicio;
    Node_simples *fim;
    int size;
}Lista;

bool _isNull(const Lista *list){
    return list->size == 0;
}

Node_simples *Node_create(int val){
    Node_simples *node = (Node_simples*)calloc(1, sizeof(Node_simples));
    node->valor = val;
    node->next = NULL;
    return node;
}

Lista *Lista_create(){
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->size = 0;
    return lista;
}