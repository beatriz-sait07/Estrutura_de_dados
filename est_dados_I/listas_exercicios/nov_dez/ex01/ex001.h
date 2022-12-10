#ifndef EX001_H
#define EX001_H
#include <stdbool.h>

typedef struct alunos Aluno;
typedef struct node Node;

Aluno *ler_aluno(char *nome, int matricula, float media);
void imprimir_Aluno(Aluno *aluno);
Node *insert_(Node *root, Aluno *aluno);
Node *busca(Node *root, int media);
void destroy_node(Node *node);
void in_order(Node *root);
void pos(Node *node);


#endif