#ifndef EX001_H
#define EX001_H

#include "stdbool.h"
typedef struct _node_simples Node_simples; 
typedef struct _lista_simples Lista;

Node_simples *Node_create(int val);
Lista *Lista_create();
void add_final(Lista *listt, int elem);
void remover_elemento(Lista *list, int elem);
void print(const Lista *list);

#endif