#include<stdbool.h>
typedef struct _tree Tree;
typedef struct _node Node;

//criando arvore
Tree *create_tree();

//criando nó
Node *create_node(int val);

//verifica se está vazia
bool tree_is_empty (Tree *tree);

//destroi o no
void destroy_node(Node *node);

//destroi a arvore
void destroy_tree (Tree *T);

//inserir dados
void insert(Tree *T, int val);

//buscar elem
void buscar (Tree *T, int elem);

//funcao recursiva
void pre_order(Tree *T);
