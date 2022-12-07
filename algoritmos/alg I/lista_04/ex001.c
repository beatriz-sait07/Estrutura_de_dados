// ler dois numeros inteiros e calcular os valores do intervalo entre eles

#include <stdio.h>

int main() {
    int inicio, fim, i, result=0;

    printf("Entre com dois numeros inteiros: ");
    scanf("%d %d", &inicio, &fim);

    if (inicio < fim) {
        for (i = inicio + 1; i < fim; i++)
            result = inicio + fim+ i;
        printf("a soma entre os elementos %d e %d eh de: %d", inicio, fim, result);
    } else {
        result=0;
        for (i = fim + 1; i < inicio; i++) {
            printf("%d ", i);
            result = inicio + fim + i;
        }
        printf("a soma entre os elementos %d e %d eh de: %d", inicio, fim, result);
    }

    return 0;
}  