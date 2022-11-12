#include "ex12.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_stack {
    int *data;
    long capacity;
    long topo;
} Estatica;

Estatica *create_estatica(long capacity){
    Estatica *s = (Estatica*)calloc(1, sizeof(Estatica));

    s->capacity = capacity;
    s->topo = -1; //pilha vazia
    s->data = (int*)calloc(s->capacity, sizeof(int)); // alocando espaco para os dados a serem inseridos
    return s;
}

void destroy_estatica(Estatica **ref_pilha){
    Estatica *s = ref_pilha;

    free(s->data);
    free(s);
    ref_pilha = NULL;
}

bool estatica_vazia(Estatica *s){return s->topo == -1;}
bool estatica_cheia(Estatica *s){return s->topo == (s->capacity-1);}

long estatica_tamanho(Estatica *s){
    return s->topo+1;
}

void estatica_push(Estatica *s, long val){
    if(estatica_cheia(s)){
        fprintf(stderr, "lista cheia!\n");
        exit(EXIT_FAILURE);
    }

    s->topo++;
    s->data[s->topo] = val;
}

void estatica_peek(Estatica *s){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_PEEK\n");
        fprintf(stderr, "erro: lista vazia\n");
        exit(EXIT_FAILURE);
    }
}
