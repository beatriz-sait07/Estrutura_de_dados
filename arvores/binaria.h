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

//deletar elem
void remover_arvore(Tree *T, int elem);

//funcao recursiva
void pre_order(Tree *T);
void in_order(Tree *T);
void pos_order(Tree *T);

//imprimir a arvore organizada
void draw_tree(Tree *T);

// profundidade
void profundidade_ar(Tree *T);

//quantidade de no na arvore
void quantidade_node(Tree *T);

//validando simetria
void simetria(Tree *T);

