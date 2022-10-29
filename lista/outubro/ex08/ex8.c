#include "ex8.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct cad_inf {
    char *usuario_cad;
    char *nome_cad;
    int *id;
    int vaga, placa;
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


