#include <iostream>
using namespace std;

float SOMAR(float num1[]) // funcao para fazer o calculo
{
    float soma = 0;
    for (int i = 0; i < 10; i++)
    {
        soma = soma + num1[i];
    }
    return soma;
}

float ex1() // funcao pra executar o que foi pedido em primeira instancia
{
    float num[10];
    float soma = 0;
    cout << "VOCE ESTA EXECUTANDO O EXERCICIO 1" << endl;

    cout << "digite os valores para seus vetores: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }
    soma = SOMAR(num);
    cout << "Soma = " << soma << endl;
    return 0;
}

void ler_funcao(float *mat)
{ // lendo os dados
    cout << "digite os valores para seu vetor: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> mat[i];
    }
}

void imp_funcao(float *vet)
{ // imprimindo os dados coletados
    for (int i = 0; i < 10; i++)
    {
        vet[i] = i;
    }
    cout << vet;
}
void par(int num[])
{
    for (int i = 0; i < 4; i++)
    {
        if (num[i] % 2 == 0)
            cout << num[i];
    }
}

void impar(int num[])
{
    for (int i = 0; i < 4; i++)
    {
        if (num[i] % 2 != 0)
            cout << num[i];
    }
}

float ex2() // funcao para executar o que foi pedido, porem utilizando matriz de ponteiro
{
    // tipo de retor - nome d funcao - parametros
    void (*mat[])(int[]) = {par, impar}; // criando a matriz
    cout << "voce esta executando o exercicio 1! (por matriz)" << endl;
    int num[4] = {3, 2, 5, 6};
    (*mat[1])(num);
    return 0;
}

int main() // funcao principal
{
    int dig;
    cout << "qual modelo do ex 1 voce deseja iniciar ??" << endl
         << " 1 = passagem de parametro" << endl
         << " 2 = matriz" << endl;
    cin >> dig;
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
