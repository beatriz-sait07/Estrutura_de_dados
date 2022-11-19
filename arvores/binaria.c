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
    Node *left;
    Node *right; //filhos arvore
}Node;

Tree *create_tree(){
    Tree *t = (Tree*)malloc(sizeof(Tree));
    return t;
}

Node *create_node(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
}

//verifica se está vazia
bool tree_is_empty (Tree *T){
    return T->root = NULL;
}

//destroi o no
void destroy_node(Node *node){
    if(node == NULL)return;
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
    node = NULL;
}

//destroi a arvore
void destroy_tree (Tree *T){
    if(tree_is_empty(T)){
        return;
    }
    destroy_node(T->root);
    free(T);
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
        if(node->right == NULL){
            node->right = n;
            return;
        }
        add(node->right, val);
    }
}


//inserir dados
void insert(Tree *T, int val){
    if(T->root == NULL){
        T->root = create_node(val);
        puts("creting tree...");
    }

    add(T->root, val);
    
}

void pre(Node *node){
    if(node != NULL){
        printf("%d ", node->val);
        pre(node->left); // chamada recursiva a esquerda
        pre(node->right); //chama recursiva a direita
    }
}

void in(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        printf("%d ", node->val);
        in(node->right); //chama recursiva a direita
    }
}

void pos(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        in(node->right); //chama recursiva a direita
        printf("%d ", node->val);
    }
}

void consult_tree(Node *node, int elem){
    //encontra o elemento
    if(node != NULL){
        if(node->val == elem)printf("%d encontrado!\n", node->val);
        
        //percorre ate encontrar o elemento
        else if(node->val < elem){
            consult_tree(node->right, elem);
        }
        else{
            consult_tree(node->left, elem);
        }
    }
    else{
        printf("nao existe\n");
    }
}




void buscar (Tree *T, int elem){
    if(T->root == NULL)fprintf(stderr, "ERRO: buscar!\nAto: arvore vazia\n");
    else{
        consult_tree(T->root, elem);
    }
}

/*forma correta
void consult_tree(Node *node, int elem){
    //encontra o elemento
    if(node->val == elem)printf("%d encontrado!\n", node->val);
    
    //percorre ate encontrar o elemento
    else if(node->val < elem){
        consult_tree(node->right, elem);
    }
    else{
        consult_tree(node->left, elem);
    }
}



void buscar (Tree *T, int elem){
    if(T->root == NULL)fprintf(stderr, "ERRO: buscar!\nAto: arvore vazia\n");
    else{
        consult_tree(T->root, elem);
    }
}
*/

//funcoes recursivas
void pre_order(Tree *T){

    printf("PRE ORDER\n");
    if(T->root == NULL){
        puts("tree is empty!\n");
        return;
    }
    pre(T->root);
}

void in_order(Tree *T){
    printf("IN ORDER\n");
    if(T->root == NULL){
        puts("tree is empty!\n");
        return;
    }
    in(T->root);
}
