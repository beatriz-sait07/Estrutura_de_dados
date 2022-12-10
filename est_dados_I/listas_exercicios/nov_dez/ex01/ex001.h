#ifndef EX001_H
#define EX001_H
#include <stdbool.h>

typedef struct alunos Aluno;
typedef struct node Node;

Aluno *ler_aluno(char *nome, int matricula, float media);
Node *insert_(Node *root, Aluno *aluno);
Node *busca(Node *root, int media);
Node *maior(Node *root);
void imprimir_no(Node *node);
void destroy_node(Node *node);
void in_order(Node *root);
void pos(Node *node);


#endif