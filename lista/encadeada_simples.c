#include "encadeada_simples.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no_simples{
    int valor;
    struct _no_simples *next;
}Node_s;

typedef struct _lista_simples{
    Node_s *inicio;
    int size;    //obrigatório já qque necessia-se saber o tamanho
}Lista;

Node_s *Node_create(int val){
    Node_s *node = (Node_s*)calloc(1, sizeof(Node_s));
    node->valor = val;
    node->next = NULL;
    return node;
}

Lista *Lista_create(){
    Lista *lista = (Lista *)calloc(1, sizeof(Lista));   //aloca apenas a "cabeca da lista", ou seja, o inicio da lista
    lista -> inicio = NULL;
    return lista;
}

void add_inicio(Lista *list, int elem)
{
    //lista está vazia
    if(list->inicio == NULL){
        Node_s *dados = Node_create(elem);
        list->inicio = dados;
    }
    //lista com dados, 
    else{
        Node_s *dados = Node_create(elem);
        dados->next = list->inicio; // o elemento criado aponta para o elemento que o 'inicio' está apotando p/ não perder a referancia
        list->inicio = dados; // agora ele se torna o primeiro elemento sem perder a referencia do antigo 1º elemento
    }
}

//tem que verificar se a lista não está vazia, pois caso ela esteja. ele será o elemento final e inicial
void add_final(Lista *list, int elem){
    Node_s *dados = Node_create(elem);
    if(list->inicio == NULL)list->inicio = dados;
    //sem o else ele inseriria como 1º e depois duplicaria como ultimo, ou seja, ele entraria duas vezes
    else{
        //enquando dados não foir igual a null (ultimo elemento), prox.
        Node_s *aux = list->inicio;
        while(aux->next != NULL){
            aux = aux->next;
        }//quando chegar aqui, aux aponta p/ o ultimo elemento
        aux->next = dados;
    }
    list->size++;
}

/*          modo simplificado de add_inicio

Nó *dados = Nó_create(elem);
dados->next = list->inicio;
list->inicio = dados;

    ****funciona para o caso de estar com dados ou vazia*****
    (testa o 'null' que você entenderá)
*/

void print(const Lista *list)
{
    Node_s *p = list->inicio;
    printf("INICIO -> ");
    while(p != NULL){
        printf("%d ->", p->valor);
        p = p->next;
    }
    printf("NULL\n");
}