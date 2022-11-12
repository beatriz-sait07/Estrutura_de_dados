#include "estatica.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct _static_stack {
    int *data;
    long capacity;
    long topo;
} Estatica;


// alocar o espaço da pilha e iniciar o parametros
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
    ref_pilha = NULL; //retira o valor do ponteiro da main
}

//valida se está vazio/cheio
bool estatica_vazia(Estatica *s){return s->topo == -1;}
bool estatica_cheia(Estatica *s){return s->topo == (s->capacity-1);}

//verificando o tamanho
long estatica_tamanho(Estatica *s){
    return s->topo+1;
}

//colocar dados
void estatica_push(Estatica *s, long val){
    if(estatica_cheia(s)){
        fprintf(stderr, "lista cheia!\n");
        exit(EXIT_FAILURE);
    }

    s->topo++;
    s->data[s->topo] = val;
}

//buscar o topo
void estatica_peek(Estatica *s){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_PEEK\n");
        fprintf(stderr, "erro: lista vazia\n");
        exit(EXIT_FAILURE);
    }
}

//tira o topo
void estatica_pop(Estatica *s){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }

    int aux = s->data[s->topo];
    s->topo--;
}

void estatica_print(Estatica *s){
    printf("capacidade: %ld", s->capacity);
    printf("topo: %ld", s->topo);

    for(long int i=0; i<s->capacity; i++){
        printf("%d", s->data[i]);
    }
}
