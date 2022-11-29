#ifndef FILA_EST_H
#define FILA_EST_H
#include <stdbool.h>

typedef struct fila_estatica Fila;

Fila *fila_estatica(long capacity); //necessaria
void destroy(Fila **ref_fila);

bool _isNull(const Fila *fila);
bool _isFull(const Fila *fila);
long tam_fila(const Fila *fila);

void create_fila(long info, Fila *fila); // cria alista
int remove_begin(Fila *fila); //remove o primeiro elemento
int peek(Fila *fila); //buscar elmento

#endif