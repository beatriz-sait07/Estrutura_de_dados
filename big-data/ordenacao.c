#include <stdio.h>
#include <stdlib.h>

void ordena(int *vetor, int tamanho){ //usando o metodo quick sort
    int i, j, pivo, aux;
    i = 0;
    j = tamanho - 1;
    pivo = vetor[(i + j) / 2];
    while(i <= j){
        while(vetor[i] < pivo && i < tamanho){
            i++;
        }
        while(vetor[j] > pivo && j > 0){
            j--;
        }
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > 0){
        ordena(vetor, j + 1);
    }
    if(i < tamanho){
        ordena(vetor + i, tamanho - i);
    }
}

float media(int *vetor, float tamanho) {
    float soma = 0;
    int i;
    for (i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma / tamanho;
}

int comparar_floats(const void *a, const void *b) {
    float fa = *(const float*) a;
    float fb = *(const float*) b;
    return (fa > fb) - (fa < fb);
}

float mediana_podada(int *vetor, int tamanho, float porcentagem) {
    int n_remover = (int) ((tamanho * porcentagem / 100.0) / 2.0);
    int tamanho_poda = tamanho - 2 * n_remover;
    float *vetor_poda = (float*) malloc(tamanho_poda * sizeof(float));
    float mediana;
    int i, indice_1, indice_2, indice;
    
    // Ordena o vetor
    qsort(vetor, tamanho, sizeof(float), comparar_floats);
    
    // Remove os elementos das extremidades
    for (i = n_remover; i < tamanho - n_remover; i++) {
        vetor_poda[i - n_remover] = vetor[i];
    }
    
    // Calcula a mediana do vetor podado
    if (tamanho_poda % 2 == 0) {
        // Se o número de elementos for par, calcula a média dos dois elementos centrais
        indice_1 = tamanho_poda / 2 - 1;
        indice_2 = tamanho_poda / 2;
        mediana = (vetor_poda[indice_1] + vetor_poda[indice_2]) / 2.0;
    } else {
        // Se o número de elementos for ímpar, retorna o elemento central
        indice = tamanho_poda / 2;
        mediana = vetor_poda[indice];
    }
    
    free(vetor_poda);
    return mediana;
}

//funcao para calcular a mediana de um vetor
float mediana(int *vetor, int tamanho){
    float mediana;
    if(tamanho % 2 == 0){
        mediana = (vetor[tamanho/2] + vetor[(tamanho/2) - 1]) / 2.0;
    }else{
        mediana = vetor[tamanho/2];
    }
    return mediana;
}

int main(){
    //leia um arquivo com numeros inteiros e armazene em um vetor
    FILE *arq;
    arq = fopen("num.txt", "r");
    int i = 0;
    int *vetor;
    vetor = (int *) malloc(15000 * sizeof(int));

    if (arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        exit(1);
    }
    while(!feof(arq) && i < 15000){
        fscanf(arq, "%d", &vetor[i]);
        i++;
    }

    fclose(arq);

    
    for(int j = 0; j < i; j++){
        printf("%d ", vetor[j]);
    }

    printf("\nmedia: %.2f ",media(vetor, i));
    printf("\nmediana: %.2f \n",mediana(vetor, i));
    ordena(vetor, i);
    for(int j = 0; j < i; j++){
        printf("%d ", vetor[j]);
    }
    printf("\nmediana podada: %.2f ",mediana_podada(vetor, i, 10));
    

    free(vetor);

    return 0;
}
