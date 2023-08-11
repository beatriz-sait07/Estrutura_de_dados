#include "lista_enc.h"
#include <stdio.h>

int main(){
    struct list *lista = List_create();
    insert(lista, 'b');
    insert(lista, 'e');
    insert(lista, 'a');
    insert(lista, 't');
    insert(lista, 'r');
    insert(lista, 'i');
    insert(lista, 'z');
    print_list(lista);
    free_list(&lista);
    

    return 0;
}