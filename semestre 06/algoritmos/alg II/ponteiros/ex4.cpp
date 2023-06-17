#include <iostream>
using namespace std;

float exp(float *massaA, float *massaB)
{
    float result = (((*massaA) * (*massaB)) / ((*massaA) + (*massaB)));
    return result;
}

int ex1()
{
    float massa1, massa2, result;
    float *massaA = &massa1;
    float *massaB = &massa2;
    float *resul = &result;

    cout << "     VOCE ESTA EXECUTANDO O EXERCICIO 4" << endl;
    cout << "Digite o valor para M1: " << endl;
    cin >> massa1;
    cout << "Digite o valor para M2: " << endl;
    cin >> massa2;
    cout << " result = (M1 * M2) / (M1 + M2) " << endl;
    result = exp(massaA, massaB);
    cout << "result = " << *resul << endl;
}

float rest(float *massaA, float *massaB)
{
    float massa1 = 4, massa2 = 6, *massaA = &massa1, *massaB = &massa2;
    float result = (((*massaA) * (*massaB)) / ((*massaA) + (*massaB)));
    return result;
}

int ex2()
{
    cout << "voce esta executando o exercicio 4 (por matriz)" << endl;
    float massa1 = 6;
    float (*matriz[])(float) = {exp, rest};
    (*matriz[1])(massa1);
    cout << (*matriz[1])(massa1);

    return 0;
}

int main()
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
//********NAO NAO NAO CONCLUIDO
