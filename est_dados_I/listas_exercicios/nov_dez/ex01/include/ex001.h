#ifndef EX_H
#define EX_H
#include <stdbool.h>

typedef struct alunos Aluno;
typedef struct noABB Node;
typedef struct _tree Tree;

Tree *create_tree();
Aluno *create_aluno(char *nome, int matricula, float media);
Node *create_node(char *nome, int matricula, float media);

void add(Tree *T, Node *node, int matricula, char *nome, float media);
void insert(Tree *T, char *nome, int matricula, float media);

void abb_alunoComMaiorMedia(Tree *T);
int abb_contaAprovados(Tree *T);

#endif