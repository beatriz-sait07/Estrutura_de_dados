#include <stdio.h> // 1

int main(){ // 1
    int vet[8] = {32, 21, 12, 25 , 31, 8, 62, 3}; // 2 
    printf("vetor nao ordenado: "); //1

    for (int i=0; i<8; i++){ // 3 + 8*i + 8*i
        printf("|%d|", vet[i]); //imbutido na multiplicacao
    }

    for (int i = 0; i < 8; i++) { // 3 + 8*i
        for (int j = 0; j < i; j++) {  // 3*i + (j*i-1)*i + (8*j)*i
            if (vet[i] > vet[j]) { // i*i (considerei n vezes possiveis, pois apenas 1/2 seria pouco)
                int aux = vet[i]; //2
                vet[i] = vet[j]; // 1
                vet[j] = aux; // 1
            }
        }
    }

    printf("\nvetor ordenado: "); // 1
    for (int i=0; i<8; i++){ // 3 + 8*i + 8*i
        printf("|%d|", vet[i]); //imbutido na multiplicacao
    }

    return 0; //1
}