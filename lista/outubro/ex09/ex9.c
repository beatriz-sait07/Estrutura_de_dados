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
    long int capacity, cont, cont1;
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
    list->capacity = 20;
    list->cont = 0;
    list->cont1 = 0;
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

void insert_dados(List *lista, Info *p){
    Node *dados = create_node(p);

    if(isNull(lista))lista->begin = lista->end = dados;
    else{
        lista->end->next = dados;
        dados->prev = lista->end;
        lista->end = dados;
    }
}

void estacionamento(List *lista, Info *p){
    Node *aux = lista->begin;

    if(isNull(lista))insert_dados(lista, p);
    else{
    while(aux != NULL){
        //contando os dados
        printf("while\n\n\n\n\n");
        if(p->usuario_cad == "F"){
            lista->cont1++;
        }
        if(p->usuario_cad == "E" && lista->cont < (91 * lista->capacity)/100){
            lista->cont++;
            /*if(lista->cont > (90 * lista->capacity)/100){
                fprintf(stderr, "ERRO: estacionamento!\nMOTIVO: vagas para alunos estao indisponiveis.\n");
                exit(EXIT_FAILURE);
            }*/
        }
        else{
            printf("usuario invalido!\n");
        }
        aux = aux->next;
    }
    }

}


/*void estacionamento(List *lista, Info *p){
    Node *aux = lista->begin;
    if(isNull(lista))lista->begin = lista->end = create_node(p);
    else{
        if((lista->cont + lista->cont1) < lista->capacity){
            if(aux->cadastro_if->usuario_cad == "FUNCIONARIO"){
                insert_dados(p, lista);
                lista->cont1++;
            }
            if(aux->cadastro_if->usuario_cad == "ESTUDANTE"){
                if(aux->cadastro_if->usuario_cad == "E" || (lista->cont <= (90 * (lista->capacity)/100))){
                    insert_dados(p, lista);
                    lista->cont++;
                }
                else{
                    printf("nao ha vagas disponiveis para alunos\n");
                }
            }
        }
    }
}*/

void print_list(List *lista){
    Node *aux = lista->begin;
    if(isNull(lista))printf("Lista vazia\n");

    printf("vagas com alunos: %ld\n", lista->cont);
    printf("vagas com servidores: %ld\n", lista->cont1);
    printf("vagas livres no estacionamento: %ld\n", (lista->capacity - (lista->cont + lista->cont1)));
}