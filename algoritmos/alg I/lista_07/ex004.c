/* Uma linha nula ou coluna nula de uma matriz é composta apenas
por valores 0.
Escreva um programa que construa uma matriz 𝑚 × 𝑛, onde 𝑚, 𝑛 > 0,
preencha seus valores com a entrada do usuário, calcula e mostre,
nesta ordem, o número de linhas e o número de colunas nulas da
matriz*/
#include <stdio.h>
#define MAX 100

int main() {
    int m, n, i, j, k, l, linha_nula = 0, coluna_nula = 0;
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
            if (matriz[i][j] == 0) {
                linha_nula = 1;
            } else {
                linha_nula = 0;
                break;
            }
        }
        if (linha_nula == 1) {
            printf("linha nula: %d \n", i);
        }
    }
    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (matriz[i][j] == 0) {
                coluna_nula = 1;
            } else {
                coluna_nula = 0;
                break;
            }
        }
        if (coluna_nula == 1) {
            printf("coluna nula: %d \n", j);
        }
    }
    return 0;
}