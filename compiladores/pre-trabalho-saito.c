#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tipo_char1[10] = "teste";
    char tipo_char2[10] = "elephant";
    char tipo_char3[10] = "mercury";
    int tipo_int1 = 42, tipo_int2 = 123, tipi_int3 = 456;
    float tipo_float1 = 3.14, tipo_float2 = 2.718, fipo_float3 = 1.618;
    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(arquivo, "Dados 1: %s %d %.2f\n", tipo_char1, tipo_int1, tipo_float1);
    fprintf(arquivo, "Dados 2: %s %d %.2f\n", tipo_char2, tipo_int2, tipo_float2);
    fprintf(arquivo, "Dados 3: %s %d %.2f\n", tipo_char3, tipi_int3, fipo_float3);

    fclose(arquivo);

    // leia dados do arquivo e imprima na tela
    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        printf("%s", linha);
    }
    
    fclose(arquivo);
    return 0;
}