#include "estatica.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    Estatica *s = create_estatica(4);


    estatica_push(s, 1);
    estatica_push(s, 2);
    estatica_push(s, 3);
    estatica_push(s, 4);
    estatica_print(s);


    return 0;
}