#ifndef ENCADEADA_SIMPLES_H
#define ENCADEADA_SIMPLES_H
#include <stdbool.h>

typedef struct _node_simples Node_simples;  //  aponta o proximo elemento -- existe a possibilidade de armazenamentos variados(tads, )
typedef struct _lista_simples Lista; // inicia a lista

Node_simples *Node_create(int val);
Lista *Lista_create();
bool _isNull(const Lista *list);
void add_inicio(Lista *list, int elem);
void add_final(Lista *listt, int elem);
void insert_ordem (Lista *list, int elem);
void print(const Lista *list);

#endif