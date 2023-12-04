#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 50
//********************************************LISTA ENCADEADA********************************************
struct node {
    char *estado;
    int peso;
    struct node *prox;
};

struct lista {
    struct node *inicio, *fim;
    int tam;
};

struct node *cria_no(char *estado, int peso){
    struct node *no = (struct node*)calloc(1, sizeof(struct node));
    no->estado = estado;
    no->peso = peso;
    no->prox = NULL;
    return no;
}

struct lista *cria_lista(){
    struct lista *l = (struct lista*)calloc(1, sizeof(struct lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

bool vazia(const struct lista *l){
    return l->tam == 0 || l->inicio == NULL;
}

void inserir(struct lista *l, char *estado, int peso){
    struct node *novo = cria_no(estado, peso);

    if(vazia(l)){
        l->inicio = l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = l->fim->prox;
    }
    l->tam++;
}

void print(struct lista *l){
    struct node *aux = l->inicio;
    
    if(vazia(l)){
        printf("ERRO: lista vazia!!\n");
    } else {
        while(aux != NULL){
            printf("%s -> ", aux->estado);
            aux = aux->prox;
        }
    }
}

void liberar(struct lista **l){
    struct lista *ref= *l;
    struct node *aux = ref->inicio;
    struct node *aux_del = NULL;

    while (aux != NULL){
        aux_del = aux;
        aux = aux->prox;
        free(aux_del); 
    }
    free(ref);
}
//************************************************LEITURA ARQUIVO****************************************


int main () {

    struct lista **l_main = (struct lista**)malloc(10 * sizeof(struct lista*));

    //criar um laco para criacao da lista de adj
    for(int i=0; i<2; i++){
        l_main[i] = cria_lista();
    }
    

    inserir(l_main[0], "sp", 132);
    inserir(l_main[1], "mg", 632);

    for(int i=0; i<2; i++){
        print(l_main[i]);
    }

    for(int i=0; i<2; i++){
        liberar(&l_main[i]);
    }
    return 0;
}
