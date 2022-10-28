#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>


//criando estrutura do cadastro.
typedef struct cadastro_struc {
    char *nome_cad;
    char *rua_cad;
    char *cell_cad;
} Dados;

// criando nó para armazernar os cada cadastro.
typedef struct node_simples {
    Dados *cad_node;
    long int size_node;
    struct node_simples *next;
} Node;

//criando lista para armazenar um conjunto de cadastros.
typedef struct linkedlist {
    Node *begin;
    Node *end;
    long int size_list;
} List;

//verifica se a lista está vazia.
bool isNull(List *lista){
    return lista->begin == NULL;
}

Dados *cadastro (char *nome, char *rua, char *cell){
    Dados *aux= (Dados*)calloc(1, sizeof(Dados));
    aux->nome_cad = nome;
    aux->rua_cad = rua;
    aux->cell_cad = cell;
    return aux;
}


Node *create_node(Dados *p){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->cad_node = p;
    node->next = NULL;
    node->size_node = 0;
    return node;
}

List *create_lista(){
    List *list = (List*)calloc(1, sizeof(List));
    list->begin = NULL;
    list->end = NULL;
    list->size_list = 0;
    return list;

}

void insert_dados(Dados *p, List *lista){
    Node *dados = create_node(p);
    Node *aux = lista->begin;

    if(isNull(lista))lista->begin = lista->end = dados;
    else{
        while(aux->next != NULL){
        aux = aux->next;
        }
        aux->next = dados;
        lista->end = dados;
        lista->end->next = NULL;
        aux->size_node++;
    }
}


Dados *busca_elemento(List *lista, char *nome){
    Node *aux = lista->begin;
    printf("entrou na busca!\n");

    while (aux != NULL){
        if(aux->cad_node->nome_cad != nome){
            printf("%s não eh valido!\n", aux->cad_node->nome_cad);
            aux = aux->next;
        }
        else if (aux->cad_node->nome_cad == nome) {
            printf("nome: %s valido!\n", aux->cad_node->nome_cad);
            aux = aux->next;
        }
        else{
            fprintf(stderr, "dados invalidos!\n\n");
        }
    }

}


void destroy(List **ref_lista){
    List *l = *ref_lista;
    Node *p = l->begin;
    Node *aux = NULL;
    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(l);
    *ref_lista = NULL;
    printf("lista totalmente desalocada!\n");
}

void print_list(List *lista){
    Node *aux = lista->begin;

    if(isNull(lista))
        printf("lista vazia!\n");
    else{
        while(aux != NULL){
            printf("nome: %s\trua: %s\tcell: %s\n", aux->cad_node->nome_cad, aux->cad_node->rua_cad, aux->cad_node->cell_cad);
            aux = aux->next;
        }
        printf("\n");
    }
    //destroy(&lista);
}