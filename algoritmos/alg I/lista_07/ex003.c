/* Escreva um programa que construa uma matriz 𝑚 × 𝑛, onde 𝑚, 𝑛 > 0,
preencha seus valores com a entrada do usuário, e informe 1 caso
existam elementos repetidos ou 0, caso contrário */
#include <stdio.h>
#define MAX 100

int main(void) {
    int m, n, i, j, k, l, repetido = 0;
    int matriz[MAX][MAX];

    printf("Digite o tamanho da matriz: (ex: 3 3)");
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                for (l = 0; l < n; l++) {
                    if (matriz[i][j] == matriz[k][l] && (i != k || j != l)) repetido = 1;
                }
            }
        }
    }
    printf("elementos repedidos: %d \n", repetido);
    return 0;
}