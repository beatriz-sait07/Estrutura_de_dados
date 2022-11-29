#include "fila_est.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct fila_estatica {
    int *data, size;
    long capacity, begin, end;
    //size: quantos elementos tem na fila, capacity: quantos elementos cabe na fila
} Fila;

Fila *fila_estatica(long capacity){
    Fila *q = (Fila*)calloc(1, sizeof(Fila));
}
