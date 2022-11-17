#ifndef EX001_H
#define EX001_H

#include "stdbool.h"
typedef struct _node_simples Node_simples; 
typedef struct _lista_simples Lista;

Node_simples *Node_create(int val);
Lista *Lista_create();
Node_simples *add_final(Node_simples *begin, int elem);
void print(Node_simples *begin);

#endif