#include "ex11.h"
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
void estatica_push(Estatica *s, int elem){
    if(estatica_cheia(s)){
        fprintf(stderr, "Erro:estatica_push\nAto:lista cheia!\n");
        exit(EXIT_FAILURE);
    }

    s->topo++;
    s->item[s->topo] = elem;
}

//tira o topo
void estatica_pop(Estatica *s, int elem){
    if(estatica_vazia(s)){
        fprintf(stderr, "erro: ESTATICA_POP\n");
        fprintf(stderr,"lista vazia!\n");
        exit(EXIT_FAILURE);
    }

    int aux = s->item[s->topo];
    s->topo--;
}

void validando_entradas(Estatica *s1, Estatica *s2, int elem){
    if(estatica_vazia(s1) && estatica_vazia(s2))estatica_push(s1, elem);
    else{
        if(estatica_tamanho(s1) + estatica_tamanho(s2) < 80){
            if(estatica_cheia(s1)){
                estatica_push(s2, elem);
            }
            else{
                estatica_push(s1, elem);
            }
            
        }
        else{
            fprintf(stderr,"Erro: validando_entradas\nAto: atingiu o limite maximo\n");
            exit(EXIT_FAILURE);
        }
    }
}

void estatica_print(const Estatica *s){
    for(long int i=0; i<=s->topo; i++){
        printf("|%d|", s->item[i]);
    }
    printf("\n");
    printf("topo: %ld\n", s->topo);
    printf("capacidade: %ld\n", s->capacity);
    printf("_______________________________________________________________________________________\n");
    
    
}
