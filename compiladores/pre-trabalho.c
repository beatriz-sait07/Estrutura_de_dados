#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char tipo_char[50];
    int tipo_int;
    float tipo_float;
} Dados;

int main() {
    FILE *arquivo;
    Dados dados;
    int i;

    arquivo = fopen("arquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    printf("escreva 3 registros: \n");
    for (i = 0; i < 3; i++) {
        printf("escreva uma palavra: ");
        scanf("%s", dados.tipo_char);
        printf("escreva um numero inteiro: ");
        scanf("%d", &dados.tipo_int);
        printf("escreva um numero 'float/com virgula': ");
        scanf("%f", &dados.tipo_float);

        printf("\n");
        fprintf(arquivo, "%s %d %f \n", dados.tipo_char, dados.tipo_int, dados.tipo_float);
    }

    fclose(arquivo);

    arquivo = fopen("arquivo.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    printf("--------------------------------\n");
    for (i = 0; i < 3; i++) {
        fscanf(arquivo, "%s %d %f ", dados.tipo_char, &dados.tipo_int, &dados.tipo_float);
        printf("palavra: %s\ninteiro: %d\nfloat: %.2f", dados.tipo_char, dados.tipo_int, dados.tipo_float);
        printf("\n--------------------------------\n");
    }

    fclose(arquivo);

    return 0;
}