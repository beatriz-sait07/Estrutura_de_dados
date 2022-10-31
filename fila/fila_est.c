#ifndef FILA_EST_H
#define FILA_EST_H
#include <stdbool.h>

typedef struct fila_estatica Fila;

Fila *fila_estatica(long capacity); //necessaria
void destroy(Fila **ref_fila);


#endif