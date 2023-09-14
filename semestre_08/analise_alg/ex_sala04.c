#include <stdio.h>

int potencia (int base, int exp){
    if (exp == 0) return 1;
    return base * potencia(base, exp-1);
}

int main (){
    printf("potencia de 2^4 = %d", potencia(2,4));
    return 0;
}
/*
base = 2
exp = 4

2 * potencia(3.2);
2 * potencia(2.2);
2 * potencia(1.2);
*/