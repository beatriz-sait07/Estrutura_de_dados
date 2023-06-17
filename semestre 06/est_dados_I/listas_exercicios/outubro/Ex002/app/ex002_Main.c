#include<stdio.h>
#include<stdlib.h>
#include "ex002.h"

int main(){

    LinkedList *Lista = list_create();

    add_last(Lista, 2);
    add_last(Lista, 5);
    add_last(Lista, 15);
    add_last(Lista, 20);
    add_last(Lista, 8);
    add_last(Lista, 15);
    add_last(Lista, 11);
    print_list(Lista);

    printf("Removendo Pares:\n");
    remove_pair(Lista);
    print_list(Lista);

return 0;
}