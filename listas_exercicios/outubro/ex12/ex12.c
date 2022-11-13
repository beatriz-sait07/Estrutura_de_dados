#include "ex12.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_stack {
    int *item;
    long capacity;
    long topo;
} Estatica;


// alocar o espaço da pilha e iniciar o parametros
Estatica *create_estatica(long capacity){
    Estatica *s = (Estatica*)calloc(1, sizeof(Estatica));

    s->capacity = capacity;
    s->topo = -1; //pilha vazia
    s->item = (int*)calloc(s->capacity, sizeof(int)); // alocando espaco para os dados a serem inseridos
    return s;
}

void destroy_estatica(Estatica **ref_pilha){
    Estatica *s = *ref_pilha;

    free(s->item);
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
    s->item[s->topo] = val;
}

void estatica_pop(Estatica *s, Estatica *s1, int elem){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }

    while(s){
        if(s->item != elem){
            estatica_push(s1, elem);
            int aux = s->item[s->topo];
            s->topo--;
        }
        else{
            int aux = s->item[s->topo];

            s->topo--;
            while(s1){
                estatica_push(s, s1->item);
            }
        }
    }
}

void estatica_print(const Estatica *s){
    printf("capacidade: %ld\n", s->capacity);
    printf("topo: %ld\n", s->topo);

    for(long int i=0; i<s->capacity; i++){
        printf("%d", s->item[i]);
    }
    printf("\n");
}







/*
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
    printf("finalizou um salvamento\n");
    return s->topo;
}

char estatica_pop(Estatica *s, Estatica *s1, char *elem){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }

    while(s){
        if(s->item != elem){
            estatica_push(s1, s->item);
            char aux = s->item[s->topo];
            char *aux1 = &aux;
            s->topo--;
        }
        else{
            char aux = s->item[s->topo];
            char *aux1 = &aux;
            s->topo--;
            while(s1){
                estatica_push(s, s1->item);
            }
        }
    }
    
    return s->topo;
}

void estatica_print(const Estatica *s){
    printf("capacidade: %ld\n", s->capacity);
    printf("topo: %c", s->topo);

    for(long int i=0; i<s->capacity; i++){
        printf("%s", s->item[i]);
    }
}
*/