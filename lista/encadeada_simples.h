#ifndef ENCADEADA_SIMPLES_H
#define ENCADEADA_SIMPLES_H

typedef struct _n_simples Node_s;  //  aponta o proximo elemento -- existe a possibilidade de armazenamentos variados(tads, )
typedef struct _lista_simples Lista; // inicia a lista

Node_s *Node_create(int val);
Lista *Lista_create();
void add_inicio(Lista *list, int elem);
void print(const Lista *list);

#endif