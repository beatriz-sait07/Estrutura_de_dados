#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"

bool isNull(const Lista *list){
    return list->size == 0;
}

Node *Node_create(int val){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->letra = val;
    node->next = NULL;
    return node;
}

Lista *Lista_create(){
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));   //aloca apenas a "cabeca da lista", ou seja, o inicio da lista
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->token_list = NULL;
    lista->size = 0;
    lista->operador = NULL;
    lista->identificador = NULL;
    lista->erro = NULL;
    return lista;
}

void add_Last(Lista *l, char val)
{
    Node *new = Node_create(val);

    //Se a lista estiver vazia
    if(isNull(l)){
        l->inicio = l->fim = new;
    }else{
        l->fim->next = new; 
        l->fim = l->fim->next;
    }
    l->size++;
}


//imprime a lista
void print_List(Lista *l){
    Node *aux = l->inicio;
    while(aux != NULL){
        printf("%c ", aux->letra);
        aux = aux->next;
    }
}