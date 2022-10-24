#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>


//criando estrutura do cadastro.
typedef struct cadastro_struc {
    int n1, n2, media;
    //char nome[50];
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

/*void cadastro (Dados *p, char nome[], char rua[], char cell[]) {
    p->nome_cad[50] = nome[50];
    p->rua_cad[50] = rua[50];
    p->cell_cad[15] = cell[50];
}
*/
Dados *cadastro (char nome[],int num1, int num2){
    Dados *p = (Dados*)calloc(1, sizeof(Dados));
    //p.nome[50] = nome[50];
    p->n1 = num1;
    p->n2 = num2;
    int md = num1 + num2 / 2;
    p->media = md;
    return p;
}

Node *create_node(Dados *p){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cad_node = p;
    node->next = NULL;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;

}

void insert_dados(List *lista, Dados *p){
    Node *dados = create_node(p);

    if(isNull(lista))
        lista->begin = dados;
    else{
        Node *aux = lista->begin;

        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = dados;
    }
    lista->size++;
}

void print_list(List *lista){
    Node *aux = lista->begin;

    if(isNull(lista))
        printf("lista vazia!\n");

    else{
        /*while(lista != NULL){
            printf("nome: %s\trua: %s\tcelular: %s\n", aux->cad_node->nome_cad, aux->cad_node->rua_cad, aux->cad_node->cell_cad);
        */
        while(lista != NULL){
            printf("n1: %d\nn2: %d\nmedia: %d", aux->cad_node->n1, aux->cad_node->n2, aux->cad_node->media);
        }
        printf("fim do armazenamento!\n");
    }
}