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
    in_order(t);
    pos_order(t);
    buscar(t, 3);
    buscar(t, 26);

    remover_arvore(t, 15);
    remover_arvore(t, 1);
    pre_order(t);
    in_order(t);
    pos_order(t);

    return 0;
}