#include <stdio.h>
#include <stdlib.h>
#include "ex001.h"

typedef struct alunos{
    int matricula;
    char *nome;
    float media;
} Aluno;
typedef struct node {
    Aluno *cad;
    struct node *left;
    struct node *right;
}Node;

Aluno *ler_aluno(char *nome, int matricula, float media){   // cria os dados de aluno
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->nome = nome;
    aluno->matricula = matricula;
    aluno->media = media;
    return aluno;
}

void imprimir_Aluno(Aluno *aluno){  // imprime o aluno
    printf("Nome: %s\t", aluno->nome);
    printf("Matricula: %d\t", aluno->matricula);
    printf("Media: %.2f\n", aluno->media);
}

Node *insert_(Node *root, Aluno *aluno){ // inserir elemento na arvore
    if(root == NULL){
        Node *aux = malloc(sizeof(Node));
        aux->cad = aluno;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else{
        if(aluno->media < root->cad->media){
            root->left = insert_(root->left, aluno);
        } else{
            root->right = insert_(root->right, aluno);
        }
        return root;
    }
}

Node *maior(Node *root){ // busca o maior elemento da arvore
    if(root == NULL) return NULL;
    if(root->right == NULL) return root;
    return maior(root->right);
}
void imprimir_no(Node *node){ // imprime o maior no quando achar.
    if(node != NULL){
        printf("Nome: %s\t", node->cad->nome);
        printf("Matricula: %d\t", node->cad->matricula);
        printf("Media: %.2f\n", node->cad->media);
    }
}

Node *busca(Node *root, int media){ // buscando elemento na arvore
    if(root){
        if(media == root->cad->media) return root;
    } else if (media< root->cad->media){
        return busca(root->left, media);
    } else {
        return busca(root->right, media);
    }
}

void destroy_node(Node *node){
    if(node == NULL)return;
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
    node = NULL;
}

//impressao da arvore
void in_order(Node *root){
    if(root != NULL){
        in_order(root->left);
        imprimir_Aluno(root->cad);
        in_order(root->right);
    }
}


