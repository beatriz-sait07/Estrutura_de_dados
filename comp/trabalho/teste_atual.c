//a partir daqui irei colocar os tokens fazendo validacao e separando as palavras.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "lista_enc.h"

void token(Lista **l) { // cria a lista de tokens
    FILE *arq;
    arq = fopen("tokens.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    char palavra[10];
    int i = 0;

    // while (1) {
    //     char aux = fgetc(arq);

    //     if (aux == EOF) {
    //         break;
    //     } else if (aux == ' ') {
    //         fgets(palavra, sizeof(palavra), arq);
    //         int tamanho_palavra = strlen(palavra);
    //         l[i]->token_list = (char *) calloc(tamanho_palavra + 1, sizeof(char));
    //         strncpy(l[i]->token_list, palavra, tamanho_palavra);
    //         i++;
    //         l[i] = Lista_create();
    //     } else if (aux == '\n') {
    //         i++;
    //         l[i] = Lista_create();
    //     } else {
    //         add_Last(l[i], aux);
    //     }
    // }

    l[i] = Lista_create();
    char aux = fgetc(arq);

    while(aux  != EOF){
        if(aux == ' '){
            fgets(palavra, sizeof(palavra), arq);
            int tamanho_palavra = strlen(palavra);
            l[i]->token_list = (char *) calloc(tamanho_palavra + 1, sizeof(char));
            strncpy(l[i]->token_list, palavra, tamanho_palavra);
        }
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

void buffer(Lista **l){ // cria o buffer
    FILE *arq;
    arq = fopen("arq.c", "r");
    char atual = fgetc(arq);
    char next = atual;

    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }

    char buffer[50];
    int i = 0;
    
    while (next != EOF){
        if (next != ' ' && next != '\t' && next != '\n') {
            buffer[i] = atual;
            i++;
            atual = fgetc(arq);
            next = atual;
            if(next >= 'a' && next <= 'z' || next >= 'A' && next <= 'Z' || next >= '0' && next <= '9' || next == '_'){ // se for letra ou numero ou _ continua
                continue;
            }
            else if (next == '"'){
                buffer[i] = atual;
                i++;
                atual = fgetc(arq);
                next = atual;
                while(next != '"'){
                    buffer[i] = atual;
                    i++;
                    atual = fgetc(arq);
                    next = atual;
                }
                buffer[i] = atual;
                i++;
                atual = fgetc(arq);
                next = atual;
            }
            else{ // se for outro caractere, imprime o buffer e zera ele
                buffer[i] = '\0';
                printf("%s\n", buffer);
                i = 0;
            }
        }
        else {
            if (i > 0) {
                buffer[i] = '\0';
                printf("%s\n", buffer);
                i = 0;
            }
            atual = fgetc(arq);
            next = atual;
        }
    }

    fclose(arq);
}


//passar no ddd e ver o que esta acontecendo aqui
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
    int n = 77;
    Lista **list = (Lista **) malloc(n * sizeof(Lista *));

    if (list == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    token(list);


    /*for(int i=0; i<n; i++){
        if(list[i] == NULL){
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }
        valida_token(list[i]->inicio , "auto");
    }*/
    

    

    printf("lista: \n");
    for(int i=0; i<n; i++){
        print_List(list[i]);
        printf("\n");
    }

    /*printf("buffer: \n");
    buffer(list);*/

    free(list); 
    return 0;
}
