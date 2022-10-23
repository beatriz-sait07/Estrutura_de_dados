#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>

//criando estrutura do cadastro.
typedef struct cadastro {
    char nome_cad[50];
    char rua_cad[50];
    int cell_cad[15];
} Dados;

// criando nó para armazernar os cada cadastro.
typedef struct node_simples {
    Dados *cad_node;
    struct node_simples *next;
} Node;

//criando lista para armazenar um conjunto de cadastros.
typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size;
} List;

//verifica se a lista está vazia.
bool isNull(List *lista){
    return lista->size == 0;
}