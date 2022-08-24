#include<stdio.h>
#include<stdlib.h>
#include"Float_vector.h"
#include"Merge.h"

void merge(FloatVector *vector, int  inicio, int meio, int fim)
{
    printf("chamou o merge\n");
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int *sub_esquerda[n1], *sub_direita[n2], *vet_aux[inicio];

    //realizando a divisao dos subvetores
    for(int i =0; i < n1; i++)
    {
        sub_esquerda[n1 + i];
    }
    for(int i =0; i < n2; i++)
    {
        sub_esquerda[meio + i];
    }

    int posicao = 0, index = get(vector, posicao);
    
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)//anda os subvetores juntos, subvetor de A e B
    {
        if(sub_esquerda[i] <= sub_direita[j])
        {
            index = get(vector, k);
            index = sub_esquerda[i];//manda direto para o vetor principal ao inves da subdivisão
            i++;
        }
        else
        {
            index = get(vector, k);
            index = sub_direita[j];
            j++;
        }
        k++;
    }

    while(j < n2)
    {
        int index = get(vector, k);
        index = sub_direita[j];
        j++;
        k++;
    }

    //ordenar o que faltou caso as casa de um lado tenha sido menor e finalizada antes do outro lado
    while(j < n1)
    {
        index = get(vector, k);
        index = sub_esquerda[i];
        j++;
        k++;
    }


}

int mergesort(FloatVector *vector, int inicio, int fim)
{
    //dividindo para conquistar
    printf("entrou na função\n");
    if(inicio)
    {
        printf("entrou no if\n");
        int meio = inicio + (fim - inicio) / 2;
        mergesort(vector, inicio, meio); //faz as partes do subvetores (1,2)
        mergesort(vector, meio + 1, fim);
        merge(vector, inicio, meio, fim);

    }
}

/*
void merge(FloatVector *vector, int  inicio, int meio, int fim)
{
    int *aux, esq, dir, tam;
    int fim_esq=0, fim_dir=0, k=0;

    tam = fim - inicio + 1;
    esq = inicio;
    dir = meio + 1;
    aux = (int *)malloc(tam*sizeof(int));

    if(aux != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(!esq && !dir)
            {
                //ordenando
                if(at(vector,esq) < at(vector,dir))
                {
                    aux[i] = get(vector,esq++);
                }else
                {
                    aux[i] = get(vector,dir++);
                }
                //verifica o fim do vetor
                if(esq>meio)
                {
                    fim_esq = 1;
                }
                if(dir>meio)
                {
                    fim_dir = 1;
                }
            }else
            {
                //copia as sobras
                if(!fim_esq)
                {
                    aux[i] = at(vector,esq++);
                }else
                {
                    aux[i] = at(vector,dir++);
                }
            }
        }
        for(int j=0, k=inicio; j<tam; j++, k++)
        {
           
        }
    }
    free(aux);

}

*/