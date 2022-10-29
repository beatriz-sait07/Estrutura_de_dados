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
