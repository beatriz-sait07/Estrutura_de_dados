#include "ex12.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_stack {
    char *item;
    long capacity;
    char topo;
} Estatica;

Estatica *create_estatica(long capacity){
    Estatica *s = (Estatica*)calloc(1, sizeof(Estatica));

    s->capacity = capacity;
    s->topo = -1; //pilha vazia
    s->item = (char*)calloc(s->capacity, sizeof(char)); // alocando espaco para os dados a serem inseridos
    return s;
}

void destroy_estatica(Estatica **ref_pilha){
    Estatica *s = *ref_pilha;
 
    free(s->item);
    free(s);
    ref_pilha = NULL;
}

bool estatica_vazia(Estatica *s){return s->topo == -1;}
bool estatica_cheia(Estatica *s){return s->topo == (s->capacity-1);}

long estatica_tamanho(Estatica *s){
    return s->topo+1;
}

//coloca algo na pilha
char estatica_push(Estatica *s, char *elem){
    if(estatica_cheia(s)){
        fprintf(stderr, "lista cheia!\n");
        exit(EXIT_FAILURE);
    }

    s->topo++;
    s->item[s->topo] = *elem;
    return s->topo;
}

char estatica_pop(Estatica *s, Estatica *s1, char *elem){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }
    while(s->item != elem){
        char aux = s->item[s->topo];
        char *rec = &aux;
        estatica_push(s1, rec); //coloca o valor em um vetor auxiliar
        s->topo--; //exclui o valor
    }
    return s->topo;
}
