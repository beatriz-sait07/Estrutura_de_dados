#include "ex001.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_simples{
    int valor;
    struct _node_simples *next;
}Node_simples;

typedef struct _lista_simples{
    Node_simples *inicio;
    Node_simples *fim;
    int size;
}Lista;

bool _isNull(const Lista *list){
    return list->size == 0;
}
