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

void consult_tree(Node *node, int elem){
    //encontra o elemento
    if(node != NULL){
        if(node->val == elem)printf("\nElemento encontrado: %d", node->val);
        
        //percorre ate encontrar o elemento
        else if(node->val < elem){
            consult_tree(node->right, elem);
        }
        else{
            consult_tree(node->left, elem);
        }
    }
    else{
        printf("\nElemento nao encontrado: %d", elem);
    }
}


void buscar (Tree *T, int elem){
    if(T->root == NULL)fprintf(stderr, "ERRO: buscar!\nAto: arvore vazia\n");
    else{
        consult_tree(T->root, elem);
    }
}

Node *remover(Node *root, int elem){
    if(root == NULL){ // esta vazia ou o elemento nao exites na arvore
        printf("valor nao encontrado: %d", elem);
        return NULL;
    } else {
        if(root->val == elem){ // verificaçao para remover o no
            if(root->left == NULL && root->right == NULL){ //encontramos um no folha
                free(root); // retira o valor e o encadeamento está correto!
                return NULL;
            }
            else{// nos filhos
                if(root->left != NULL && root->right != NULL){ //dois filhos
                //escolha qual sub-arvore voce vai percorrer
                    Node *aux = root->left; // ao escolher o lado esquerdo
                    while(aux->right != NULL){ // percorremos mais a fundo os nos a direita
                        aux = aux->right;
                        root->val = aux->val;
                        aux->val = elem;
                        root->left = remover(root->left, elem);
                    }
                }
                else{//um filho
                Node *aux;
                //verifica em qual lado esta
                    if(root->left != NULL){
                        aux = root->left;
                    }
                    else{
                        aux = root->right; // arux aponta para o prox elem
                        free(root); // desaloca o elem
                        return aux; //retorna para o pai do elemento que removemos
                    }
                }

            }
        }
        else{ //caminhando na arvore
            if(elem < root->val){
                root->left = remover(root->left, elem);
            }
            else{
                root->right = remover(root->right, elem);
            }
            return root;
        }
    }
}


void remover_arvore(Tree *T, int elem){
    if(T->root == NULL)fprintf(stderr, "ERRO: deletar_item!\nAto: arvore vazia\n");
    else{
        remover(T->root, elem);
    }
}


//funcoes recursivas
void pre(Node *node){
    if(node != NULL){
        printf("%d ", node->val);
        pre(node->left); // chamada recursiva a esquerda
        pre(node->right); //chama recursiva a direita
    }
}

void pre_order(Tree *T){

    printf("\nPRE ORDER: ");
    if(T->root == NULL){
        puts("tree is empty!\n");
        return;
    }
    pre(T->root);
}

void in(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        printf("%d ", node->val);
        in(node->right); //chama recursiva a direita
    }
}

void in_order(Tree *T){
    printf("\nIN ORDER: ");
    if(T->root == NULL){
        puts("tree is empty!\n");
        return;
    }
    in(T->root);
}

void pos(Node *node){
    if(node != NULL){
        in(node->left); // chamada recursiva a esquerda
        in(node->right); //chama recursiva a direita
        printf("%d ", node->val);
    }
}

void pos_order(Tree *T){
    printf("\nPOS ORDER: ");
    if(T->root == NULL){
        puts("tree is empty!\n");
        return;
    }
    pos(T->root);
}
