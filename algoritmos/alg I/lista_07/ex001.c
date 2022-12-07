/*  Escreva um programa que construa uma matriz 𝑚 × 𝑛, onde 𝑚, 𝑛 > 0,
de tal forma que os valores da diagonal principal sejam 0, os valores
acima da diagonal principal sejam 1, e os valores abaixo da diagonal
principal sejam −1.
*/
#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Entre com o numero de linhas: ");
    scanf("%d", &m);
    printf("Entre com o numero de colunas: ");
    scanf("%d", &n);

    int matriz[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                matriz[i][j] = 0;
            } else if (i < j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = -1;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
