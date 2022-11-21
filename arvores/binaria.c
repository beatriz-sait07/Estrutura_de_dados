#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binaria.h"
#define espaco 5

//funcao a qual ninguem pode usar, pois é uma função recursiva.
void add(Node *node, int val);
void pre(Node *node);
void in(Node *node);
void pos(Node *node);

//estruturas
typedef struct _tree {
    Node *root; //raiz
    int profundidade; //profundidade da arvore
}Tree;
typedef struct _node {
    int val;
    Node *left;
    Node *right; //filhos arvore
}Node;

//criando nos e arvore.
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

//verifica se está vazia.
bool tree_is_empty (Tree *T){
    return T->root = NULL;
}

//destroi o no e a arvore.
void destroy_node(Node *node){
    if(node == NULL)return;
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
    node = NULL;
}

void destroy_tree (Tree *T){
    if(T->root == NULL){
        return;
    }
    destroy_node(T->root);
    printf("\narvore totalmente desalocada\n");
    free(T);
} 

// insere dados na arvore.
void add(Node *node, int val){
    Node *n = create_node(val);

    //se isso aconter, ele será inserido no lado esquerdo
    if(node->val > val){
        if(node->left == NULL){
            node->left = n;

            return;
        }
        add(node->left, val);
    } else if(node->val < val){ //se não, ele será inserido no lado esquerdo.
        if(node->right == NULL){
            node->right = n;
            return;
        }
        add(node->right, val);
    } else {
        fprintf(stderr, "Erro: add\nAto: valores repetidos nao podem ser inseridos (%d)\n", val);
    }
}

void insert(Tree *T, int val){
    if(T->root == NULL){
        T->root = create_node(val);
        puts("creting tree...");
    }
    add(T->root, val);
}

//buscando elemento na arvore.
void consult_tree(Node *node, int elem){
    //encontra o elemento
    if(node != NULL){
        if(node->val == elem)printf("\nElemento encontrado: %d\n", node->val);
        
        //percorre ate encontrar o elemento
        else if(node->val < elem){
            consult_tree(node->right, elem);
        }
        else{
            consult_tree(node->left, elem);
        }
    }
    else{
        printf("\nElemento nao encontrado: %d\n", elem);
    }
}

void buscar (Tree *T, int elem){
    if(T->root == NULL)fprintf(stderr, "ERRO: buscar!\nAto: arvore vazia\n");
    else{
        consult_tree(T->root, elem);
    }
}

//removendo elemento da arvore.
Node *remover(Node *root, int elem){
    if(root == NULL){ // esta vazia ou o elemento nao exites na arvore
        printf("\nvalor nao encontrado: %d", elem);
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
                        printf("\nRemovido: %d\n", elem);
                        root->left = remover(root->left, elem);
                        return root;
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
                        printf("\nRemovido: %d\n", elem);
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

//altura da arvore é a distancia entre a raiz e a ultima folha.
int altura(Node *raiz){
    if(raiz == NULL)return -1; //para que nao haja erro, se houver apenas um no na arvore
    else{
        int esq = altura(raiz->left); //percorre toda a sub arvore esquerda
        int dir = altura(raiz->right); //percorre toda a sub arvore direita
        if(esq > dir)return esq + 1;
        else return dir + 1;
    }
}

void profundidade_ar(Tree *T){
        if(T->root == NULL){
        puts("tree is empty");
        return;
    }
    printf("\nAltura da arvore: %d \n\n", altura(T->root));
}

//quantidades de nos na arvore
int qtd_node(Node *root){
    if(root == NULL) return 0;
    else return 1 + qtd_node(root->left) + qtd_node(root->right); // usando a recursividade verificamos a existencia de nos, se houver, somamos.
    /*operador ternario:
        ruturn (root == NULL) ? 0:  1 + qtd_node(root->left) + qtd_node(root->right);
    */
}

//conferindo simetria
void simetria(Tree *T){
    int alt = altura(T->root), qtdN = qtd_node(T->root), x = qtdN + 1;
    double menor_alt = log(x)-1; //formular para verificar a menor
    //verificando a menor altura da arvore
    if(menor_alt == alt)printf("\nSIMETRICA\n\n");
    else printf("NAO EH SIMETRICA\n");
}

//funcoes recursivas para validar as ordens da arvore, sendo: pre-prder, in-order, pos-order.
void pre(Node *node){
    if(node != NULL){
        printf("|%d|", node->val);
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
        printf("|%d|", node->val);
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

// imprime a arvore bonitinha.
void desenha_arvore_horiz(Node *node, int profundidade, char *caminho, int direita)
{
    // profundidade da condicao de parada
    if (node == NULL)
        return;

    // aumentando espaco
    profundidade++;

    // o no comeca na direita
    desenha_arvore_horiz(node->right, profundidade, caminho, 1);

    // definindo - desenhando
    caminho[profundidade-2] = 0;

    if(direita)
        caminho[profundidade-2] = 1;

    if(node->left)
        caminho[profundidade-1] = 1;

    // impressao da raiz apos o espacamento
    printf("\n");

    for(int i=0; i<profundidade-1; i++)
    {
      if(i == profundidade-2)
          printf("+");
      else if(caminho[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < profundidade-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", node->val);

    // vertical espacors below
    for(int i=0; i<profundidade; i++)
    {
      if(caminho[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(node->left, profundidade, caminho, 0);
}

void desenha_arvore(Node *T)
{
    char path[255] = {};

    //inicia a profundidade com 0
    desenha_arvore_horiz(T, 0, path, 0);
}

void draw_tree(Tree *T)
{
    if(T->root == NULL){
    //if(!tree_is_empty(T)){
        puts("tree is empty");
        return;
    }
    desenha_arvore(T->root);
}
