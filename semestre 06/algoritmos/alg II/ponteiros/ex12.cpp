#include <iostream>
#include <string.h>
using namespace std;

// o programa a baixo busca elementos dentro de um vetor, armaze e apresenta o mesmo!

int ex1()
{
    cout << "voce esta executando o exercicio num 17!" << endl;

    int arr1[25], i, elem;
    int *array = arr1, *elemento = &elem;
    printf("\n\n armazena e recupera elementos de um vetor:\n");
    printf("------------------------------------------------------------\n");
    printf(" tamanho do vetor :");
    scanf("%d", &elem);
    printf(" insira %d numeros de elementos no array :\n", elem);

    for (i = 0; i < elem; i++)
    {
        printf("elemento - %d : ", i);
        scanf("%d", array + i);
    }

    printf(" os elemetos digitados sao : \n");

    for (i = 0; i < elem; i++)
    {
        printf(" elementos - %d : %d \n", i, *array);
        *array++;
    }

    return 0;
}

 int rest(void)
 {
    char arr1[] = "beto";
	int i, elem, *elemento = &elem;
    char *array = arr1;

    for (i = 0; i < elem; i++)
    {
        printf("%d \n", *array);
        *array++;
    }

     return *array;
 }
 
 int rest1 (void)
 {
    char arr1[] = "brenda";
	int i, elem, *elemento = &elem;
    char *array = arr1;

    for (i = 0; i < elem; i++)
    {
        printf("%d  \n", *array);
        *array++;
    }

     return *array;
 }
int ex2()
{
    cout << "voce esta executando o exercicio num 12! (por matriz)" << endl;
    
     int (*mat[])() = {rest, rest};
     (*mat[0])();
     cout << mat[0]() << endl;
    return 0;
}

int main()
{

    int dig;
    printf("qual modelo do ex 12 deseja iniciar ?\n 1 - pedido pelo ex da lista\n 2 - por matriz\n");
    scanf("%d", &dig);
   
    do
    {
        if (dig == 1)
        {
            dig = ex1(); // chamando a primeira funcao
        }
        if (dig == 2)
        {
            dig = ex2(); // chamando a segunda funcao
        }
        if (dig < 0)
        {
            cout << "digito invalido!" << endl;
        }
        if (dig > 2)
        {
            cout << "digito invalido!" << endl;
        }
    } while (dig < 2);
    return 0;
}
