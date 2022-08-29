#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int conta_troca=0;
int particiona(int *vetor, int inicio, int final, int size)
{
    srand(time(NULL));
    int left, right, pivo, auxiliar;
    left = inicio;
    right = final;
    //int p = rand()%10000;
    //pivo=vetor[sizeof(vetor)/2];
    pivo = vetor[size/2]; // Pivo recebendo a posicao de inicio do vetor
    while(left < right){
        // Andando pra direita ate achar um elemento que seja maior q o pivo
        while(vetor[left] <= pivo){
            left++;
        }
        // Andando pra Esquerda ate achar um menor que o pivo
        while(vetor[right] > pivo){
            right--;
        }
        // No final dos whiles, se a esquerda for menor q a direita
        // Troca os dois de lugares
        if(left < right){
            conta_troca+=1;
            auxiliar = vetor[left];
            vetor[left] = vetor[right];
            vetor[right] = auxiliar;
        }
    }
    vetor[inicio] = vetor[right]; // Onde a Direita parar, colocamos o valor no inicio
    vetor[right] = pivo; // Posicao da direita se torna o valor do pivo
    return right; // Retorna o valor da direita, pois, aonde paramos na Direita
                 // Os valores da esquerda estaram menores e os da Direira maiores
}

void quickSort(int *vetor, int inicio, int fim,int size)
{
    int pivo;
    if(fim > inicio){
        //Separando os dados em duas particoes
        pivo = particiona(vetor, inicio, fim, size);
        //Chamando a funcao para as duas metades
        quickSort(vetor, inicio, pivo-1,size);
        quickSort(vetor, pivo+1, fim,size);
    }
}
int main(){

    double time_spent = 0.0;
    clock_t begin = clock();

    int size = 10000;
    int *vector;

    vector = (int*)malloc(size * sizeof(int));
    srand(time(NULL));
    for(int j=0; j<size; j++){
        vector[j] = rand()%size;
    }

    quickSort(vector, 0, size,size);
    printf("\nTroca: %d\n", conta_troca);

    free(vector);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime Spent: %.4f\n", time_spent);

return 0;
}