#include<stdio.h>
#include<stdlib.h>
#define espaco 5

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
} node;

//create_node
node *create_node(int key) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->height = 0;
  return new_node;
}

int max(int a, int b) {
  return (a > b) ? a : b; 
}

int height(node *n) {
  if (n == NULL) {
    return -1;
  }
  return n->height;
}

int balance_factor(node *n) {
  if (n == NULL) {
    return 0;
  }
  return height(n->left) - height(n->right);
}

node *right_rotate(node *y) {
  node *x = y->left;
  node *z = x->right;

  x->right = y;
  y->left = z;

  y->height = 1 + max(height(y->left), height(y->right));
  x->height = 1 + max(height(x->left), height(x->right));

  return x;
}

node *left_rotate(node *x) {
  node *y = x->right;
  node *z = y->left;

  y->left = x;
  x->right = z;

  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));

  return y;
}

node *balance(node *n) {
  int bf = balance_factor(n);
  if (bf < -1) {
    if (balance_factor(n->right) > 0) {
      n->right = right_rotate(n->right);
    }
    n = left_rotate(n);
  } else if (bf > 1) {
    if (balance_factor(n->left) < 0) {
      n->left = left_rotate(n->left);
    }
    n = right_rotate(n);
  }
  return n;
}

//trocar
node *insert(node *x, node *z){
    if(x == NULL || (x != NULL && x->key == z->key)){
        return z;
    }else if(z->key < x->key){
        x->left = insert(x->left, z);
    }else{
        x->right = insert(x->right, z);
    }
    x->height = 1 + max(height(x->left), height(x->right));
    return balance(x);
}

void pre_order(node* root) {
    if (root != NULL) {
        printf("{%d", root->key);
        if (root->left != NULL || root->right != NULL) {
            printf(",");
            pre_order(root->left);
            if (root->right != NULL) {
                printf(",");
                pre_order(root->right);
            }
        }
        printf("}");
  }
}

// funcao de deletar um no
node *delete(node *x, int key){
    if(x == NULL){
        return NULL;
    }else if(key < x->key){
        x->left = delete(x->left, key);
    }else if(key > x->key){
        x->right = delete(x->right, key);
    }else{
        if(x->left == NULL && x->right == NULL){
            free(x);
            return NULL;
        }else if(x->left == NULL && x->right != NULL){
            node *aux = x->right;
            free(x);
            return aux;
        }else if(x->left != NULL && x->right == NULL){
            node *aux = x->left;
            free(x);
            return aux;
        }else{
            node *aux = x->left;
            while(aux->right != NULL){
                aux = aux->right;
            }
            x->key = aux->key;
            aux->key = key;
            x->left = delete(x->left, key);
        }
    }
    x->height = 1 + max(height(x->left), height(x->right));
    return balance(x);
}

//procure o no mais profundo da avl, caso haja um empate escolha o de maior valor
node *search_deepest(node *x){
    if(x == NULL){
        return NULL;
    }else if(x->left == NULL && x->right == NULL){
        return x;
    }else if(x->left != NULL && x->right == NULL){
        return search_deepest(x->left);
    }else if(x->left == NULL && x->right != NULL){
        return search_deepest(x->right);
    }else{
        node *aux = search_deepest(x->left);
        node *aux2 = search_deepest(x->right);
        if(aux->height > aux2->height){
            return aux;
        }else{
            return aux2;
        }
    }
}

void desenha_arvore_horiz(node *node, int depth, char *path, int direita)
{
    // stopping conditiondepth
    if (node == NULL)
        return;

    // increase spacing
    depth++;

    // start with direita no
    desenha_arvore_horiz(node->right, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(node->left)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", node->key);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    desenha_arvore_horiz(node->left, depth, path, 0);
}

void desenho(node *T)
{
    char path[255] = {};
    if(T == NULL){
        puts("tree is empty");
        return;
    }
    desenha_arvore_horiz(T, 0, path, 0);
}

int main (){
    node *T = NULL;
    int n;
    /*printf("quantas chaves voce ira usar: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int key;
        printf("Digite a chave: ");
        scanf("%d", &key);
        node *z = create_node(key);
        root = insert(root, z);
      }
    printf("Pre order:\n");
    pre_order(root);*/

    node *new = create_node(43);
    T = insert(T, new);
    new = create_node(18);
    T = insert(T, new);
    new = create_node(22);
    T = insert(T, new);
    new = create_node(9);
    T = insert(T, new);
    new = create_node(21);
    T = insert(T, new);
    new = create_node(6);
    T = insert(T, new);
    new = create_node(8);
    T = insert(T, new);
    new = create_node(20);
    T = insert(T, new);
    new = create_node(63);
    T = insert(T, new);
    new = create_node(50);
    T = insert(T, new);
    new = create_node(56);
    T = insert(T, new);
    new = create_node(51);
    T = insert(T, new);
    pre_order(T);
    printf("\n");
    desenho(T);
    printf("\n");
    return 0;
}

/*
-- esquerda 2x
++ direita 2x
+- esquerda direita
+
*/