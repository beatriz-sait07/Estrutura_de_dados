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

Aluno *ler_aluno(char *nome, int matricula, float media){
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->nome = nome;
    aluno->matricula = matricula;
    aluno->media = media;
    return aluno;
}

void imprimir_Aluno(Aluno *aluno){
    printf("Nome: %s\t", aluno->nome);
    printf("Matricula: %d\t", aluno->matricula);
    printf("Media: %.2f\n", aluno->media);
}

Node *insert_(Node *root, Aluno *aluno){
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

//buscar elemento na arvore
Node *busca(Node *root, int media){
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

void pos(Node *node){
    if(node != NULL){
        pos(node->left); 
        pos(node->right); 
        printf("%.2f ", node->cad->media);
    }
}
