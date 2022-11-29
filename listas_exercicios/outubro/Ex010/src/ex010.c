#include "ex010.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_simples {
    char *string;
    struct node_simples *next;
    struct node_simples *prev;
    
} Node;

typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size_list;
} List;

bool isNull(List *lista){
    return lista->begin == NULL;
}

Node *create_node(char *s){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->string = s;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->size_list = 0;
    return list;

}

void destroy (List **ref_list){
    List *l = *ref_list;
    Node *p = l->begin;
    Node *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    *ref_list = NULL;
    printf("LISTA TOTALMENTE DESALOCADA!\n\n");

}

void insert_dados(List *lista, char *s){
    Node *aux = create_node(s);

    if(isNull(lista))lista->begin = lista->end = aux;
    else{

        lista->end->next = aux;
        aux->prev = lista->end; 
        lista->end = aux;
    }
    lista->size_list++;
}

void cop_first_list(List *first, List *sec){

    Node *aux_f = first->begin;
    while(aux_f != NULL){
        char *s = aux_f->string;
        if(isNull(sec)){
            sec->begin = sec->end = aux_f;
            sec->size_list++;
        }
        else{
            insert_dados(sec, s);
        }
        aux_f = aux_f->next;
    }
}

void validar(List *sec){
    /*Node *aux_s = sec->begin;
    while(aux_s != NULL){
        if(sec->begin->string == aux_s->next->string){
            if(sec->begin == sec->end){ 
                sec->begin = sec->end = NULL;
            }
            else{
                sec->begin = aux_s->next; 
                sec->begin->prev = NULL; 
            }
            free(aux_s); 
            sec->size_list--; 
        }
        else{
            Node *aux = sec->begin->next;

            if(aux->string == aux_s->string){
                if(sec->end == aux){ 
                   sec->end = aux->prev; 
                   sec->end->next = NULL;
                }
                else{ 
                    aux->prev->next = aux->next; 
                    aux->next = aux->prev;
                }
                free(aux);
                aux = NULL;
                sec->size_list--;
            }
            else{
                aux = aux->next;
            }
        }  
        aux_s = aux_s->next;
    }*/

    if(!isNull(sec)){ 
        Node *aux = sec->begin;
        char *s = aux->string;
        if(sec->begin->string == s){
            if(sec->begin == sec->end){
                sec->begin = sec->end = NULL;
            }
            else{
                sec->begin = aux->next;
                sec->begin->prev = NULL; 
                free(aux); 
                sec->size_list--; 
            }
        }
        else{
            Node *aux = sec->begin->next;
            Node *aux1 = sec->begin;

            while(aux != NULL){
                if(aux->string == s){
                    if(sec->end == aux){ 
                    sec->end = aux->prev; 
                    sec->end->next = NULL;
                    }
                        else{ 
                        aux->prev->next = aux->next; 
                    }
                    free(aux);
                    aux = NULL;
                    sec->size_list--;
                }
                else{
                    aux = aux->next;
                }
                aux1 = aux1->next;
            }
        }
    }
}

void imprimir_lista(const List *list){
    Node *aux = list->begin;

    while(aux != NULL){
        printf("%s", aux->string);
        aux = aux->next;
    }
    printf("\ntamanho = %ld\n", list->size_list);
}