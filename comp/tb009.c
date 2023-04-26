//ate aqui esta tudo certo

// proximo passo e separar o token e a leitura do arquivo


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_enc.h"

void token(Lista **l){
    FILE *arq;
    char palavra[20];

    arq = fopen("tokens.txt", "r");

    if (arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }


    int i = 0, vet = 0;
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

// void token(Lista **l){
//     FILE *arq;
//     char palavra[20];

//     arq = fopen("tokens.txt", "r");

//     if (arq == NULL){
//         printf("Erro ao abrir o arquivo!\n");
//         exit(1);
//     }


//     int i = 0, vet = 0;
//     l[i] = Lista_create();
//     char aux = fgetc(arq);


//     while(aux  != EOF){
//         if(aux == '\n'){
//             aux = fgetc(arq);
//             i++;
//             l[i] = Lista_create();
//         } else if (aux == ' ') {
//             memset(palavra, 0, sizeof(palavra)); // Limpa a string
//             fgets(palavra, 20, arq); // le a palavra
//             l[i]->token_list = (char*) malloc((strlen(palavra) + 1) * sizeof(char)); // aloca a string
//             strcpy(l[i]->token_list, palavra);
//         }
//         add_Last(l[i], aux);
//         aux = fgetc(arq);

//     }
//     fclose(arq);
// }


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

    printf("tokens: \n");

    for(int i=0; i<n; i++){
        print_List(list[i]);
        printf("\n");
    }

    free(list); 
    return 0;
}