#include "ex010.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List *lista_princ = create_lista();
    List *lista_sec = create_lista();
    insert_dados(lista_princ, "n");
    insert_dados(lista_princ, "i");
    insert_dados(lista_princ, "n");
    insert_dados(lista_princ, "a");
    insert_dados(lista_princ, "r");
    imprimir_lista(lista_princ);
    cop_first_list(lista_princ, lista_sec);
    validar(lista_sec);
    imprimir_lista(lista_sec);

    return 0;
}
