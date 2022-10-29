#include "ex8.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct cad_inf {
    char *usuario_cad;
    char *nome_cad;
    char *placa;
    int *id;
    int vaga;
} Info;

typedef struct node_simples {
    Info *cadastro_cliente;
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

bool isFull(List *lista){
    return lista->end == NULL;
}

Info *cadastro (char *usuario, char *nome, int *id, int vaga, char *placa){
    Info *aux = (Node*)calloc(1, sizeof(Node));
    aux->usuario_cad = usuario;
    aux->nome_cad = nome;
    aux->id = id;
    aux->vaga = vaga;
    aux->placa = placa;
    return aux;
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

void print_list(const List *lista){
    Node *aux = lista->begin;
    
    while( aux != NULL){
        prinf("Usuario: %s\tNome: %s\tId: %d\tVaga: %d\tPlaca: %s",
        aux->cadastro_cliente->usuario_cad, aux->cadastro_cliente->nome_cad, aux->cadastro_cliente->id, aux->cadastro_cliente->vaga, aux->cadastro_cliente->placa);
        aux = aux->next;
    }
}
 