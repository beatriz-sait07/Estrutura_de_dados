#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista_enc.h"

void token(Lista **l) {
    FILE *arq;
    arq = fopen("tokens.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int i = 0;
    l[i] = Lista_create();
    char aux = fgetc(arq);

    while(aux  != EOF){
        if(aux == '\n'){
            aux = fgetc(arq);
            i++;
            l[i] = Lista_create();
        }
        add_Last(l[i], aux);
        aux = fgetc(arq);

    }
    fclose(arq);
}

void buffer(Lista **l){
    FILE *arq;
    arq = fopen("arq.c", "r");
    char atual = fgetc(arq);
    char next = atual;

    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }
    char buffer[50];

    int i=0;
    while(atual != EOF){
        if(next == ' ' || next == '\t' || next == '\r' || next == '\n'){ //se o proximo for um espaço, tab, retorno de linha ou nova linha
            for(int j=0; j<i; j++){
                atual = fgetc(arq);
                next = atual;
            }
        }
        else if (next >= 'a' && next <= 'z'){ //se o proximo for uma letra minuscula ele grava no vetor
            buffer[i] = atual;
            i++;
            atual = fgetc(arq);
            next = atual;
        }
        else if (!(next >= 'a' && next <= 'z') || (next < 0 && next > 9)){ //se o proximo for um caractere especial ele grava no vetor
            buffer[i] = atual;
            i++;
            atual = fgetc(arq);
            next = atual;
        }
        else if (next == '"'){ //se o proximo for uma aspas ele grava no vetor
            buffer[i] = atual;
            i++;
            atual = fgetc(arq);
            next = atual;
        }
        else if (next == EOF){ //se o proximo for o fim do arquivo ele grava no vetor
            buffer[i] = atual;
            i++;
            atual = fgetc(arq);
            next = atual;
            buffer[i] = '\0'; // adiciona um caractere nulo para indicar o final da string
            //printf("Conteúdo do buffer: %s\n", buffer); // imprime o conteúdo do buffer
        }
        
        for(int j=0; j<50; j++){
            printf("%c", buffer[j]);
        }
        printf("\n");
        for(int j=0; j<50; j++){ // reseta o buffer manualmente
            buffer[j] = 0;
        }
    }
    fclose(arq);
}


void valida_token(Node *node, char *buffer){
    if(node == NULL){
        printf("%s -> Token invalido!\n", buffer);
        exit(1);
    }
    else{
        int i = 0;
        while (node->letra != '\0' && buffer[i] != '\0') {
            if (node->letra != buffer[i]) {
                valida_token(node->next, buffer);
                return;
            }
            i++;
        }
        if (node->letra == '\0' && buffer[i] == '\0') {
            printf(" %s -> Token valido!\n", buffer);
        } else {
            valida_token(node->next, buffer);
        }
    }
}


int main(){
    int n = 75;
    Lista **list = (Lista **) malloc(n * sizeof(Lista *));

    if (list == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    token(list);

    /*for(int i=0; i<n; i++){
        print_List(list[i]);
        printf("\n");
    }*/
    
    buffer(list);

    free(list); 
    return 0;
}
