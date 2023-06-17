#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/ex001.h"

typedef struct alunos{
    int matricula;
    char *nome;
    float media;
} Aluno;
typedef struct noABB {
    Aluno *info;
    struct noABB *left;
    struct noABB *right;
}Node;

typedef struct _tree{
    Node *root;
    Node maiorMedia;
    int aprovados;
}Tree;

Tree *create_tree()
{
    Tree *T = (Tree*)malloc(sizeof(Tree));
    T->root = NULL;
    T->aprovados = 0;
    return T;
}

Aluno *create_aluno(char *nome, int matricula, float media){   // cria os dados de aluno
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->nome = nome;
    aluno->matricula = matricula;
    aluno->media = media;
    return aluno;
}

Node *create_node(char *nome, int matricula, float media){   // cria os dados de aluno
    Node *node = (Node*) malloc(sizeof(Node));
    node->info = create_aluno(nome, matricula, media);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void add(Tree *T, Node *node, int matricula, char *nome, float media)
{
    Node *n = create_node(nome, matricula, media);
    if(media > T->root->info->media){       // verifica se a media eh maior que a media do aluno com maior media
        T->maiorMedia = *n;
    }
    if(node->info->matricula > matricula){
        if(node->left == NULL){
            node->left = n;
            return;
        }
        add(T, node->left, matricula, nome, media);
    
    }else if(node->info->matricula < matricula){
        if(node->right == NULL){
            node->right = n;
            return;
        }
        add(T, node->right, matricula, nome, media);
    }else{
        fprintf(stderr, "Erro em ADD()\n");
        fprintf(stderr, "Nao eh Possivel Inserir (%d) Numeros Repetidos!\n", matricula);
    }
}
void insert(Tree *T, char *nome, int matricula, float media)
{
    if(T->root == NULL){
        T->root = create_node(nome, matricula, media);
        T->maiorMedia = *T->root;
        if(media >= 5.0)T->aprovados++;  // conta aprovados
        return;
    }else{
        if(media >= 5.0)T->aprovados++; // conta aprovados
        add(T, T->root, matricula, nome, media);
    }
}

void abb_alunoComMaiorMedia(Tree *T){ // retorna aluno com maior media
    printf("Nome: %s\t", T->maiorMedia.info->nome);
    printf("Matricula: %d\t", T->maiorMedia.info->matricula);
    printf("Media: %.2f\n\n", T->maiorMedia.info->media);
}

int abb_contaAprovados(Tree *T){ // retorna quantidade de alunos aprovados
    return T->aprovados;
}