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
void insert_ordem (Lista *list, int elem); //insere em ordem crescente na lista
void remover_elemento(Lista *list, int elem); //remove o 1º nó que está alocando o valor desejado
void remover_todos_elementos(Lista **ref_list); //remove todos os elementos da lista
int busca_elemento(Lista *list, int elem); //procura um elemento na lista
int tam_lista(const Lista *list);
void print(const Lista *list);

#endif