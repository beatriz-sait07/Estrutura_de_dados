#include <iostream>
using namespace std;

int somaArray(int array[], const int x)
{
    int soma = 0;
    int *ptr;
    int *const final_array = array + x;

    for (ptr = array; ptr < final_array; ptr++)
    {
        soma += *ptr;
    }

    return soma;
}
int subArray(int array[], const int x)
{
    int sub = 0;
    int *ptr;
    int *const final_array = array - x;

    for (ptr = array; ptr < final_array; ptr++)
    {
        sub = sub - *ptr;
    }

    return sub;
}

int ex1()
{
    cout << "voce esta executando o exercicio num 7!" << endl;

    int somaArray(int array[], const int x);
    int subArray(int array[], const int x);
    int array[3] = {3, 6, 9};
    cout << "a soma do vetor é = " << somaArray(array, 3) << endl;
    cout << "a subtracao do vetor eh : " << subArray(array, 3);

    return 0;
}

int ex2()
{
    cout << "voce esta executando o exercicio num 7! (por matriz)" << endl;

    int x[3] = {2, 4, 6}, *y;
    int (*mat[])(int, int) = {somaArray, subArray};
    (*mat[0])(x, y);
    cout << (*mat[0])(x, y) << endl;

    return 0;
}

int main()
{

    int dig;
    cout << "qual modelo do ex 13 voce deseja iniciar ??" << endl
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
