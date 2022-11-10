#include "ex9.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct cad_inf {
    char *usuario_cad;
    char *nome_cad;
    char *placa;
    char *id;
    int vaga;
} Info;

typedef struct node_simples {
    Info *cadastro_if;
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

Info *cadastro (char *usuario, char *nome, char *id, int vaga, char *placa){
    Info *aux = (Info*)calloc(1, sizeof(Info));
    aux->usuario_cad = usuario;
    aux->nome_cad = nome;
    aux->id = id;
    aux->vaga = vaga;
    aux->placa = placa;
    return aux;
}

Node *create_node(Info *p){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cadastro_if = p;
    node->next = NULL;
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

void insert_dados(Info *p, List *lista){
    Node *dados = create_node(p);

    if(isNull(lista))lista->begin = lista->end = dados;
    else{
        lista->end->next = dados;
        dados->prev = lista->end;
        lista->end = dados;
    }
    lista->size_list++;
}

void separa_dados(List *lista, List *lista_est, List *lista_func, Info *p){
    Node *aux = lista->begin;
    if(aux->cadastro_if->usuario_cad == "ESTUDANTE"){
        Node *aux_est = create_node(p);
        if(isNull(lista_est))lista_est->begin = lista_est->end = aux_est;
        else{
            while(aux != NULL){
                lista_est->end->next = aux_est;
                aux_est->prev = lista_est->end;
                lista_est->end = aux_est;
            }
        }
        lista_est++;
    }else{
        Node *aux_func = create_node(p);
        if(isNull(lista_func))lista_func->begin = lista_func->end = aux_func;
        else{
            while(aux != NULL){
                lista_func->end->next = aux_func;
                aux_func->prev = lista_func->end;
                lista_func->end = aux_func;
            }
        }
        lista_func++;
    }
}

/*void separa_dados(List *lista, List *lista_est, List *lista_func, Info *p){
    Node *aux_lista = lista->begin;
    while(aux_lista != NULL){
        if(aux_lista->cadastro_if->usuario_cad == "ESTUDANTE"){
            Node *aux_est = lista_est->begin;
            if(isNull(lista_est))lista_est->begin = lista_est->end = aux_lista;
            else{
                lista_est->end->next = aux_lista;
                aux_lista->prev = lista_est->end;
                lista_est->end = aux_lista;
            }
        }
        else{
            Node *aux_func = lista_func->begin;
            lista_func->end->next = aux_lista;
            aux_lista->prev = lista_func->end;
            lista_func->end = aux_lista;
        }
        aux_lista = aux_lista->next;
    }
}*/

void print_list(List *lista){
    Node *aux = lista->begin;
    if(isNull(lista))printf("Lista vazia\n");
    else{
        while( aux != NULL){
            printf("Usuario: %s\tNome: %s\tId: %s\tVaga: %d\tPlaca: %s\n",
            aux->cadastro_if->usuario_cad, aux->cadastro_if->nome_cad, aux->cadastro_if->id, aux->cadastro_if->vaga, aux->cadastro_if->placa);
            aux = aux->next;
        }
    }
    printf("ocupacao do estacionamento: %ld\n\n", lista->size_list);
}