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
    
    return 0;
}