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

bool _isNull_dupla(const List *list){
    return list->size == 0;
}

void destroy_dupla(List **ref_list){
    List *aux_list = *ref_list; //inicia a desalocacao de 
    
    Node *p = aux_list->inicio; //usado para desalocar a casa atual
    while(p != NULL){
        Node *aux = p; //usado para não perder a referencia
        aux = p;
        p = p->next;
        free(aux);
    }
    free(aux_list);
    *ref_list = NULL;
    printf("lista totalmente desalocada!\n");
}

void add_final_dupla(List *list, int val){
    Node *aux = create_node(val);

    if(_isNull_dupla(list))list->inicio = list->fim = aux;
    else{

        list->fim->next = aux; //final passara a receber o novo elemento
        aux->prev = list->fim; // guarda a posicao atual para ela tornar-se a posicao anterios
        list->fim = aux; // assume o novo valor

    }

    list->size++; //conta cada elemento que está sendo adicionado no final da
}

void remover_elemento_dupla(List *list, int val){
    if(!_isNull_dupla(list)){ //negacao de lista vazia, ou seja, lista com elementos
        Node *aux = list->inicio;
        if(list->inicio->val == val){
            if(list->inicio == list->fim){ //verificando se ha apenas um elemento na lista
                list->inicio = list->fim = NULL;
            }
            else{
                list->inicio = aux->next; // acessando a casa a pos a casa do inicio
                list->inicio->prev = NULL; //novo ponteiro aponta para o antecessor que no caso é nulo
            }
            free(aux); //desaloca o no atual
            list->size--; // decrementa o tamanho da lista
        }
        else{
            Node *aux = list->inicio->next;

            while(aux != NULL){
                if(aux->val == val){
                    if(list->fim == aux){ // caso o elemento esteja no fim da lista
                       list->fim = aux->prev; // aponta para o anterior antes de desalocar o o ultimo elemento
                       list->fim->next = NULL;
                    }
                    else{ //caso o elemento esteja no meio da lista
                        aux->prev->next = aux->next; //valor anterior ao atual passa a apontar para o proximo valor do autal
                        aux->next = aux->prev;
                    }
                    free(aux);
                    aux = NULL; //para o fim nao apontar para um lixo de memoria.
                    list->size--;
                }
                else{
                    aux = aux->next;
                }
            }
        }  
    }
}

void imprimir_lista(const List *list){
    Node *aux = list->inicio;

    printf("inicio -> ");
    while(aux != NULL){
        printf("%d -> ", aux->val);
        aux = aux->next; //passa para imprimir o elemento a frente
    }
    printf(" fim\n");
    printf("tamanho = %ld", list->size);
    
}

void imprimir_invert(const List *list){
    Node *aux = list->fim;

    printf("fim -> ");
    while(aux != NULL){
        printf("%d -> ", aux->val);
        aux = aux->prev; //passa a imprimir o elemento anterior
    }
    printf("inicio\n");
    printf("tamanho = %ld", list->size);
}

