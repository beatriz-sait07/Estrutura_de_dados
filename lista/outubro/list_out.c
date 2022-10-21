#include "list_out.h"
#include <stdio.h>
#include <stdlib.h>

//dados recebidos;
typedef struct cadastro
{
    char nome[50], rua[50], bairro[20];
    int num_casa, cell;
} dados;

// cada nó recebe uma estrutura cadastral
typedef struct node_simples
{
    dados *cad;
    struct node_simples *next
}Node;

// lista completa
typedef struct linkedlist
{
    Node *begin;
    Node *end;
    int cont;
} List;

//criando nó
void create_node(char nome[50], char rua[50]){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cad->nome[50] = scanf("%c", &nome[50]);
    node->cad->rua[50] = scanf("%c", &rua[50]);
    node->next = NULL;
}

void create_lista(){
    List *lista = (List*)calloc(1, sizeof(List));
    lista->begin = NULL;
    lista->end = NULL;
    lista->cont = 0;
}

bool _isNull(List *lista){
    return lista->cont == 0;
}