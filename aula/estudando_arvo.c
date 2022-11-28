#include <stdio.h>
#include <stdlib.h>

/*exemplo de ar:
        inserir
        50 (raiz) --contagen inicia a 0, logo a raiz eh zero
    25      100
  15  30  75   105(folha)  --altura = 2 (a maior distancia entre o no raiz e o no folha)

*/

//declaracao das funcoes
typedef struct node Node;
Node *insert_tree(Node *root, int val);
void insert_tree_best(Node **root, int val); //recursiva menos custosa
Node *insert_tree_iterativo(Node **root, int val); //melhor solucao
Node *buscar_tree(Node *root, int val);
Node *buscar_tree_interativo(Node *root, int val); 
int altura(Node *root);
int quant_node(Node *root);
int quant_folhas(Node *root);
Node *remover(Node *root, int val);
void pre_order(const Node *root);
void in_order(const Node *root);
void pos_order(const Node *root);


int main (){
    Node *raiz = NULL, *busca;
    /* teste recursiva
    raiz = insert_tree(raiz, 50);
    raiz = insert_tree(raiz, 25);
    raiz = insert_tree(raiz, 100);

    teste recursiva melhorada
    insert_tree_best (&raiz, 50);
    insert_tree_best (&raiz, 25);
    insert_tree_best (&raiz, 100);*/

    insert_tree_iterativo(&raiz, 50);
    insert_tree_iterativo(&raiz, 25);
    insert_tree_iterativo(&raiz, 100);
    insert_tree_iterativo(&raiz, 75);
    insert_tree_iterativo(&raiz, 105);

    /*busca = buscar_tree(raiz, 105);
    if(busca) printf("\nvalor encontrado: %d", 105);
    else printf("\nvalor nao encontrado!");*/

    printf("\naltura: %d", altura(raiz));
    printf("\nquantidade de nos: %d", quant_node(raiz));
    printf("\nquantidade de folha: %d", quant_folhas(raiz));
    printf("\npre order: ");
    pre_order(raiz);
    printf("\npos order: ");
    pos_order(raiz);
    printf("\n in order: ");
    in_order(raiz);
    printf("\nremovendo elemento -> ");
    raiz = remover(raiz, 100);

    busca = buscar_tree_interativo(raiz, 25);
    if(busca) printf("\nvalor encontrado: %d", 25);
    else printf("\nvalor nao encontrado!");

    return 0;
}

typedef struct node {
    int val;
    struct node *dir_menor, *esq_maior;
} Node;

Node *insert_tree(Node *root, int val){
    if(root == NULL){
        Node *aux = (Node*)calloc(1, sizeof(Node));
        aux->val = val;
        aux->dir_menor = NULL;
        aux->esq_maior = NULL;
        return aux;
    } else {
        if(val < root->val) root->esq_maior = insert_tree(root->esq_maior, val); //verifica se o valor a ser inserido e menor que o valor da raiz, para assim saber para qul lado deve ir
        else root->dir_menor = insert_tree(root->dir_menor, val);
        return root;
    }
}

void insert_tree_best(Node **root, int val){
    if(*root == NULL){
        *root = (Node*)calloc(1, sizeof(Node));
        (*root)->val = val; //(*root) diz que voce deseja pegar o conteudo
        (*root)->dir_menor = NULL;
        (*root)->esq_maior = NULL;
    } else {
        if(val < (*root)->val)insert_tree_best(&((*root)->dir_menor), val);
        else insert_tree_best (&((*root)->dir_menor), val);
    }
}

Node *insert_tree_iterativo(Node **root, int val){
    Node *aux = *root;
    
    while(aux){ //quando nao esta nula
        if(val < aux->val)root = &aux->esq_maior;
        else root = &aux->dir_menor;

        aux = *root;
    }
    aux = (Node*)calloc(1, sizeof(Node));
    aux->val = val;
    aux->dir_menor = NULL;
    aux->esq_maior = NULL;
    *root = aux; //valor recebido diretamente da main
}

/*pre :: raiz -> sub_ar_esq -> sub_ar_dir

in ordem :: sub_ar_esq -> raiz -> sub_ar_dir

pos :: sub_ar_esq -> sub_ar_dir -> raiz*/

Node *buscar_tree(Node *root, int val){
    if(root){
        if(val == root->val) return root;
        else if (val < root->val) return buscar_tree(root->esq_maior, val);
        else return buscar_tree(root->dir_menor, val);

    } else {
        return NULL;
    }
}

Node *buscar_tree_interativo(Node *root, int val){
    while(root){
        if(val < root->val) root = root->esq_maior;
        else if(val > root->val) root = root->dir_menor;
        else return root;
    }
    return NULL;
}

int altura(Node *root){
    if(root == NULL){
        return -1;
    } else {
        int esq = altura(root->esq_maior);
        int dir = altura(root->dir_menor);
        if(esq > dir) return esq +1;
        else return dir + 1;
    }
}

int quant_node(Node *root){
    if (root == NULL) return 0;
    else return 1 + quant_node(root->esq_maior) + quant_node(root->dir_menor);
}

int quant_folhas(Node *root){
    if(root == NULL) return 0;
    else if(root->dir_menor == NULL && root->esq_maior == NULL) return 1;
    else return quant_folhas(root->esq_maior) + quant_folhas(root->dir_menor);
}

Node *remover(Node *root, int val){
    if(root == NULL){
        printf("\nvalor nao encontrado!");
        return NULL;
    } else {
        if(root->val == val){
            if(root->esq_maior == NULL && root->dir_menor == NULL){//remove um no sem filhos
                free(root);
                printf("\nelemento removido: %d", val);
                return NULL;
            } else { //remove um no que tenha filhos
                if(root->esq_maior != NULL && root->dir_menor != NULL){//verificacao se tem dois filhos
                    //aqui tem a SUBSTITUICAO de elementos
                    Node *aux = root->esq_maior;
                    while(aux->dir_menor != NULL) aux = aux->dir_menor;
                    root->val = aux->val;
                    aux->val = val;
                    printf("\nelemento trocado: %d", val);
                    root->esq_maior = remover(root->esq_maior, val);
                    return root;
                } else { // tem apenas um filho
                    Node *aux;
                    if(root->esq_maior != NULL) aux = root->esq_maior;
                    else aux = root->dir_menor;
                    free(root);
                    
                    return aux;
                }
            }
        } else {
            if(val < root->val) root->esq_maior = remover(root->esq_maior, val);
            else root->dir_menor = remover(root->dir_menor, val);
            return root;
        }
    }
}

void pre_order(const Node *root){
    if(root != NULL){
        printf("|%d|", root->val);
        pre_order(root->esq_maior);
        pre_order(root->dir_menor);
    }
}

void in_order(const Node *root){
    if(root != NULL){
        in_order(root->esq_maior);
        printf("|%d|", root->val);
        in_order(root->dir_menor);
    }
}

void pos_order(const Node *root){
    if(root != NULL){
        pos_order(root->esq_maior);
        pos_order(root->dir_menor);
        printf("|%d|", root->val);
    }
}