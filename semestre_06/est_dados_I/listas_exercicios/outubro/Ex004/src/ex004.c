#include "ex004.h"
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
    }
    lista->size_list++;
}


Dados *busca_elemento(List *lista, char *nome){
    Node *aux = lista->begin;
    while (aux != NULL){
        if(aux->cad_node->nome_cad != nome){
            //printf("%s não eh valido!\n", aux->cad_node->nome_cad);
            aux = aux->next;

        }
        else if (aux->cad_node->nome_cad == nome) {
            printf("Nome: %s\tRua: %s\tContato: %s \n", aux->cad_node->nome_cad, aux->cad_node->rua_cad, aux->cad_node->cell_cad);
            aux = aux->next;
        }
        else{
            printf("%s nao cadastrado\n\n", nome);
        }
    }
    
    return 0;
}

void excluir_cliente(List *lista, char *nome){
    if(!isNull(lista)){
        // elemento encontra-se no comeco da lista
        if(lista->begin->cad_node->nome_cad == nome){
            Node *aux = lista->begin;
            lista->begin = aux->next;

            if(lista->begin == NULL)aux = NULL;
            free(aux);
            lista->size_list--;
            printf("CLIENTE DELETADO COM SUCESSO!\n");
        }

        //elemento encontra-se no meio
        else{
            Node *aux = lista->begin->next;
            Node *ant = lista->begin;

            while(aux != NULL && aux->cad_node->nome_cad != nome){
                ant = aux;
                aux = aux->next;
            }
            if(aux != NULL) {
                ant->next = aux->next;
                if(aux->next == NULL)lista->end;

                free(aux);
                printf("CLIENTE DELETADO COM SUCESSO!\n");
                lista->size_list--;
            }
        }
    }
}

int tam_lista(const List *lista){
    return lista->size_list;
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
    FILE *file = fopen("resp_ex04.txt", "a");

    if(isNull(lista))
        fprintf(file, "lista vazia!\n");
    else{
        while(aux != NULL){
            fprintf(file, "nome: %s\trua: %s\tcell: %s\n", aux->cad_node->nome_cad, aux->cad_node->rua_cad, aux->cad_node->cell_cad);
            aux = aux->next;
        }
    }
    fprintf(file, "tamanho lista: %ld\n", lista->size_list);
    fclose(file);
}
