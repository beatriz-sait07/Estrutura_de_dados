#ifndef EX001_H
#define EX001_H

#include "stdbool.h"
typedef struct _node_simples Node_simples; 
typedef struct _lista_simples Lista;

Node_simples *Node_create(int val);
Lista *Lista_create();
Node_simples *add_final(Node_simples *begin, int elem);
Node_simples *remover(Node_simples *node, int elem);
Node_simples *destroy(Node_simples *node);
void print(Node_simples *begin);

#endif