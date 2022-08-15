void merge(int *array[], int  inicio, int meio, int fim)
{
    int array;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int sub_esquerda[n1],sub_direita[n2];

    //realizando a divisao dos subvetores
    for(int i =0; i < n1; i++)
    {
        sub_esquerda[n1 + i];
    }
    for(int i =0; i < n2; i++)
    {
        sub_esquerda[meio + i];
    }
    
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)//anda os subvetores juntos, subvetor de A e B
    {
        if(sub_esquerda[i] <= sub_direita[j])
        {
            array[k] = sub_esquerda[i];//manda direto para o vetor principal ao inves da subdivisão
            i++;
        }
        else
        {
            array[k] = sub_direita[j];
            j++;
        }
        k++;
    }

    while(j < n2)
    {
        array[k] = sub_direita[j];
        j++;
        k++;
    }

    //ordenar o que faltou caso as casa de um lado tenha sido menor e finalizada antes do outro lado
    while(j < n1)
    {
        array[k] = sub_esquerda[i];
        j++;
        k++;
    }


}

int mergesort(int *array[], int inicio, int fim)
{



    //dividindo para conquistar
    if(inicio < fim)
    {

        int meio = inicio + (fim - inicio) / 2;
        mergesort(array, inicio, meio); //faz as partes do subvetores (1,2)
        mergesort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}