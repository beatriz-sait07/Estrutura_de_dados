#include "ex009.h"
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

void insert_dados(List *lista_est,  List *lista_serv, Info *p){
    Node *dados = create_node(p);
    //fiz com a capacidade total de 20, dando 10% (2) para servidores, ou seja, reservei as primeiras vagas para eles
    if(p->vaga == 1 || p->vaga == 2){
        if(isNull(lista_serv))lista_serv->begin = lista_serv->end = dados;
        else{
            lista_serv->end->next = dados;
            dados->prev = lista_serv->end;
            lista_serv->end = dados;
        }
        lista_serv->cont1++;
    }
    else{
        if(lista_est->cont == 0){
            if(isNull(lista_est))lista_est->begin = lista_est->end = dados;
            else{
                lista_est->end->next = dados;
                dados->prev = lista_est->end;
                lista_est->end = dados;
            }
        lista_est->cont++;
        }
        else if(lista_est->cont < (91 * ((lista_est->capacity + lista_serv->capacity)/2 ))/100){//mudar
            lista_est->end->next = dados;
            dados->prev = lista_est->end;
            lista_est->end = dados;
            lista_est->cont++;
        }
        else{
            fprintf(stderr, "Erro: insert_dados");
            fprintf(stderr, "Ato: %s nao pode estacionar, vagas para estudantes indisponiveis\n", dados->cadastro_if->nome_cad);
            
        }
    }
}

/*void estacionamento(List *lista, Info *p){
    if(isNull(lista)){
        printf("entrou\n");
        insert_dados(lista, p);
        Node *aux = lista->begin;
        if(p->usuario_cad == "f"){
            printf("entrou na validacao\n");
            lista->cont1++;
            printf("cont1++ 01\n");
        }
        else if(aux->cadastro_if->usuario_cad == "e"){
            lista->cont++;
            printf("cont++ 01\n");
        }
    }
    else{
        printf("entrou no else\n");
        Node *aux = lista->begin;
        while(aux != NULL){
            //contando os dados
            printf("while\n");
            if(p->usuario_cad == "F"){
                printf("cont1 ++ 02\n");
                lista->cont1++;
            }
            if(p->usuario_cad == "E" && lista->cont < (91 * lista->capacity)/100){
                printf("cont++\n");
                lista->cont++;
                if(lista->cont > (90 * lista->capacity)/100){
                    fprintf(stderr, "ERRO: estacionamento!\nMOTIVO: vagas para alunos estao indisponiveis.\n");
                    exit(EXIT_FAILURE);
                }
            }
            else{
                printf("usuario invalido!\n");
            }
            aux = aux->next;
        }
    }
}*/

void print_list(List *lista, List *lista1){
    Node *aux = lista->begin;
    Node *aux1 = lista1->begin;
    if(isNull(lista))printf("Lista vazia\n");
    printf("vagas com alunos: %ld\n", lista->cont);
    printf("vagas com servidores %ld\n", lista1->cont1);
    printf("vagas livres no estacionamento: %ld\n", (((lista->capacity + lista1->capacity)/2) - (lista->cont + lista1->cont1)));
}
