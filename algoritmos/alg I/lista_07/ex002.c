/* Escreva um programa que construa uma matriz 𝑚 × 𝑚, onde 𝑚 > 0,
preencha seus valores com a entrada do usuário, calcula e mostre
nesta ordem: e a soma dos elementos que estão acima da diagonal
principal, a soma dos elementos que estão abaixo da diagonal
principal, e a soma dos elementos que estão na diagonal principal */
#include <stdio.h>
#define MAX 100

int main(void) {
    int m, i, j, soma1 = 0, soma2 = 0, soma3 = 0;
    int matriz[MAX][MAX];

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (i < j) {
            soma1 += matriz[i][j];
            }
            if (i > j) {
            soma2 += matriz[i][j];
            }
            if (i == j) {
            soma3 += matriz[i][j];
            }
        }
    }
    printf("Soma dos elementos acima da diagonal principal: %d \n", soma1);
    printf("Soma dos elementos abaixo da diagonal principal: %d \n", soma2);
    printf("Soma dos elementos na diagonal principal: %d \n", soma3);
    return 0;
}