#include "binaria.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Tree *t = create_tree();
    insert(t, 10);
    insert(t, 6);
    insert(t, 3);
    insert(t, 1);
    insert(t, 2);
    insert(t, 15);
    pre_order(t);
    printf("\nbuscando elemento 15\n");
    buscar(t, 3);
    printf("\nbuscando elemento 26\n");
    buscar(t, 26);

    return 0;
}