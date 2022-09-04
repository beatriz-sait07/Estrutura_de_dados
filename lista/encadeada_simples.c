#include "encadeada_simples.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _nó_simples{
    int valor;
    struct _nó_simples *next;
}   Node ;

typedef struct _lista_simples{
    Node *inicio;
} Lista;

Node *Nó_create (int dados){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->valor = dados;
    node->next = NULL;
    return node;
}

Lista *Lista_create (){
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));   //aloca apenas a "cabeca da lista", ou seja, o inicio da lista
    lista -> inicio = NULL;
    return lista;
}

void add_inicio(Lista *list, int elem)
{
    //lista está vazia
    if(list->inicio == NULL){
        Node *dados = Nó_create(elem);
        list->inicio = dados;
    }
    //lista com dados, 
    else{
        Node *dados = Nó_create(elem);
        dados->next = list->inicio; // o elemento criado aponta para o elemento que o 'inicio' está apotando p/ não perder a referancia
        list->inicio = dados; // agora fele se torna o primeiro elemento sem perder a referencia do antigo 1º elemento
    }
}

/*          modo simplificado de add_inicio

Nó *dados = Nó_create(elem);
dados->next = list->inicio;
list->inicio = dados;

    ****funciona para o caso de estar com dados ou vazia*****
    (testa o 'null' que você entenderá)
*/
