#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
} node;

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

node *insert(node *root, int key) {
  if (root == NULL) {
    root = (node*)malloc(sizeof(node));
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    root->height = 0;
  } else if (key < root->key) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }

  root->height = 1 + max(height(root->left), height(root->right));

  return balance(root);
}

void pre_order(node *root) {
  if (root != NULL) {
    printf("%d\n", root->key);
    pre_order(root->left);
    pre_order(root->right);
  }
}

int main (){
    node *root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }
    pre_order(root);
    return 0;
}