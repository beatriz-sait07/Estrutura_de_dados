// intersecao de dois vetores

#include <stdio.h>

int main() {
    int i, j, k, n, m, v1[100], v2[100], v3[100];

    scanf("%d", &n);

    //printf("Digite os elementos do vetor 1: ");
    for (i = 0; i < n; i++) scanf("%d", &v1[i]);

    //printf("Digite os elementos do vetor 2: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &v2[i]);

    k = 0; // tamanho do vetor de intersecao
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (v1[i] == v2[j]) { 
                v3[k] = v1[i];
                k++;
            }

    for (i = 0; i < k; i++) printf("%d ", v3[i]);
    return 0;
}