#include <stdio.h>
#include <stdlib.h>
#include "binaria.h"

//funcao a qual ninguem pode usar, pois é uma função recursiva.
void add(Node *node, int val);
void pre(Node *node);
void in(Node *node);
void pos(Node *node);

typedef struct _tree {
    Node *root; //raiz
    int depth; //profundidade da arvore
}Tree;
typedef struct _node {
    int val;
    Node *left, *rigth; //filhos arvore
}Node;

Tree *create_tree(){
    Tree *t = (Tree*)malloc(sizeof(Tree));
    return t;
}

Node *create_node(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->rigth = NULL;
}

//verifica se está vazia
bool tree_is_empty (Tree *T){
    return T->root = NULL;
}

//destroi a arvore
void destroy_tree (Tree *T){

} 

void add(Node *node, int val){
    Node *n = create_node(val);

    //se isso aconter, ele será inserido no lado esquerdo
    if(node->val > val){
        if(node->left == NULL){
            node->left = n;
            return;
        }
        add(node->left, val);
    }else{ //se não, ele será inserido no lado esquerdo.
        if(node->rigth == NULL){
            node->rigth = n;
            return;
        }
        add(node->rigth, val);
    }
}


//inserir dados
void insert(Tree *T, int val){
    if(tree_is_empty(T)){
        T->root = create_node(val);
        puts("creting tree...");
    }

    add(T->root, val);
    
}

void pre(Node *node){
    if(node != NULL){
        printf("%d ", node->val);
        pre(node->left); // chamada recursiva a esquerda
        pre(node->rigth); //chama recursiva a direita
    }
}

void in(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        printf("%d ", node->val);
        in(node->rigth); //chama recursiva a direita
    }
}

void pos(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        in(node->rigth); //chama recursiva a direita
         printf("%d ", node->val);
    }
}


//funcoes recursivas
void pre_order(Tree *T){

    printf("PRE ORDER\n");
    if(tree_is_empty(T)){
        puts("tree is empty!\n");
        return;
    }
    pre(T->root);
}

void in_order(Tree *T){
    printf("IN ORDER\n");
    if(tree_is_empty(T)){
        puts("tree is empty!\n");
        return;
    }
    in(T->root);
}
