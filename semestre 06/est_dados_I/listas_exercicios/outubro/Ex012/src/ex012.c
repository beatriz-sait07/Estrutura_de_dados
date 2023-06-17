#include "ex012.h"
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

//colocar dados
void estatica_push(Estatica *s, int val){
    if(estatica_cheia(s)){
        fprintf(stderr, "Erro: push\nato: lista cheia!\n");
        exit(EXIT_FAILURE);
    }

    s->topo++;
    s->item[s->topo] = val;
}

void estatica_print(const Estatica *s){
    for(long int i=0; i<= s->topo; i++){
        printf("|%d| ", s->item[i]);
    }
    printf("\n");
    printf("topo: %ld\n", s->topo);
    printf("capacidade: %ld\n", s->capacity);
}

int estatica_pop(Estatica *s, int elem){
    int tam = s->capacity;
    Estatica *s1 = create_estatica(tam);
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }

    while(s->item[s->topo] != elem){
        int aux = s->item[s->topo];
        s1->topo++;
        s1->item[s1->topo] = aux;
        estatica_print(s1);
        s->topo--;
    }

    int aux = s1->item[s1->topo];
    s->topo--;

    while(!estatica_vazia(s1)){
        int aux1 = s1->item[s1->topo];
        s->topo++;
        s->item[s->topo] = aux1;
        s1->item[s1->topo] = aux1;
        s1->topo--;
    }
    s1->topo++;

    return aux;
}
