#ifndef ENCADEADA_SIMPLES_H
#define ENCADEADA_SIMPLES_H

typedef struct _nó_simples Node;  //  aponta o proximo elemento
typedef struct _lista_simples Lista; // inicia a lista

Node *Nó_create(int valor);
Lista *Lista_create();
void add_inicio(Lista *list, int elem);


#endif