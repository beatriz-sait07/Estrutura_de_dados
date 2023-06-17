#include<stdio.h>
#include<stdlib.h>
#include"Quick.h"

int cont_trocas = 0;
int cont_varredura = 0;
int cont_comp = 0;

int particiona(int *vetor, int inicio, int final)
{
    cont_trocas = 0, cont_comp = 0, cont_varredura = 0;
    int left, right, pivo, auxiliar;
    left = inicio;
    right = final;
    //int p = rand()%10000;
    //pivo=vetor[sizeof(vetor)/2];
    pivo = vetor[inicio]; // Pivo recebendo a posicao
    do{
        // Andando pra direita ate achar um elemento que seja maior q o pivo
        do{
            while(vetor[left] <= pivo){
                left++;
            }
            // Andando pra Esquerda ate achar um menor que o pivo
            while(vetor[right] > pivo){
                right--;
            }
            cont_comp += 1;
        }while(vetor[left] <= pivo && vetor[right] > pivo);
        // No final dos whiles, se a esquerda for menor q a direita
        // Troca os dois de lugares
        if(left < right){
            auxiliar = vetor[left];
            vetor[left] = vetor[right];
            vetor[right] = auxiliar;
            cont_trocas += 1;
        }
        cont_varredura += 1;
    }while(left < right);

    vetor[inicio] = vetor[right]; // Onde a Direita parar, colocamos o valor no inicio
    vetor[right] = pivo;// Posicao da direita se torna o valor do pivo
    cont_trocas += 1;
    return right; // Retorna o valor da direita, pois, aonde paramos na Direita
                 // Os valores da esquerda estaram menores e os da Direira maiores
}

void quickSort(int *vetor, int inicio, int fim)
{
    int pivo;
    if(fim > inicio){
        //Separando os dados em duas particoes
        pivo = particiona(vetor, inicio, fim);
        //Chamando a funcao para as duas metades
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int print_arq(int size, double tempo)
{
   FILE *file = fopen("Quick_sort.txt", "a");
   if(file == NULL)printf("\n\nnao foi possivel criar arquivo!\n\n");

   fprintf(file, "\n\nDADOS DO VETOR **%d**",size);
   fprintf(file, "\nnumero de trocas %d", cont_trocas);
   fprintf(file, "\nnumero de varedura do vetor: %d", (cont_varredura));
   fprintf(file, "\nnumero de comparacoes: %d", cont_comp);
   fprintf(file, "\no tempo de execucao foi de: %.4f", tempo);
   fprintf(file, "\n\n------------------------------\n");
   fclose(file);
}
