#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista_enc.h"

#define AUTO

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


char buffer(Lista **l){
    FILE *arq;
    arq = fopen("arq.c", "r");

    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }
    char buffer[50];
    int i=0;
    char atual;
    char proximo;
    

    /*while(1){
        int aux = fgetc(arq);
        if (aux == EOF){
            break;
        }
        if (aux != ' ' && aux != '\n' && aux != '\t' && aux != '\r'){
            in_word = 1;
            if(!(aux >= 'a' && aux <= 'z' || aux >= 'A' && aux <= 'Z')){

            }
                
            buffer[i] = aux;
            i++;
        }
        else if (in_word){ 
            in_word = 0;
            for(int j=0; j<i; j++){
                printf("%c", buffer[j]);
            }
            printf("\n");
            for(int j=0; j<50; j++){
                buffer[j] = 0;
            }
            i=0;
        }
    }*/

    while(1){
        atual = fgetc(arq);
        proximo = atual;
        if (proximo == EOF){
            break;
        }
        if (proximo != ' ' && proximo != '\n' && proximo != '\t' && proximo != '\r'){
            if(!(proximo >= 'a' && proximo <= 'z' || proximo >= 'A' && proximo <= 'Z')){
                if(!(proximo < '0' || proximo > '9')){
                    if(proximo == '"'){
                        while(proximo != '"'){
                            buffer[i] = proximo;
                            i++;
                            atual = fgetc(arq);
                            proximo = atual;
                        }
                    } else {
                        buffer[i] = proximo;
                        i++;
                        atual = fgetc(arq);
                        proximo = atual;
                    }
                } else {
                    //vetor recebe numero
                    buffer[i] = proximo;
                    i++;
                    atual = fgetc(arq);
                    proximo = atual;
                }
            } else {
                buffer[i] = proximo;
                i++;
                atual = fgetc(arq);
                proximo = atual;
            }
        }
        else if (atual){ 
            for(int j=0; j<i; j++){
                printf("%c", buffer[j]);
            }
            printf("\n");
            for(int j=0; j<50; j++){
                buffer[j] = 0;
            }
            i=0;
        }

    }

    fclose(arq);
}

/*void valida_token(Node *node, char *buffer){
    if(node == NULL){
        printf("Token invalido!\n");
        exit(1);
    }
    else{
        if(strcmp(node->letra, buffer) == 0){
            printf("Token valido!\n");
        }
        else{
            valida_token(node->next, buffer);
        }
    }
}*/

void valida_token(Node *node, char *buffer){
    ;
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

    //valida_token(list[0]->inicio, "auto");
    free(list); 
    return 0;
}
