#include <iostream>
using namespace std;

int ex1()
{
    cout << "voce esta executando o exercicio num 17!" << endl;
    int vet[6] = {3, 5, 6, 9, 8, 2};
    int *vet1, *vet2, vetX, vetY;
    int vetA[6] = {1, 3, 6, 9, 7, 5};

    vet1 = vet;
    vet2 = vetA;
    cout << "vetor 1 = " << *vet1 << "      "
         << "vetor 2 = " << *vet2 << endl;
    cout << "*********apos troca********" << endl;

    vet1 = vetA;
    vet2 = vet;

    cout << "vetor 1 = " << *vet1 << "      "
         << "vetor 2 = " << *vet2 << endl;
    return 0;
}

int var(void)
{
    int vet[3] = {2, 4, 6};
    int *vet1 = vet;
    return *vet1;
}
int var1(void)
{
    int vet[3] = {3, 6, 9};
    int *vet1 = &vet[2];
    return *vet1;
}
int ex2()
{
    cout << "voce esta executando o exercicio num 17! (por matriz)" << endl;
    int (*mat[])() = {var, var1};
    (*mat[1])();
    cout << var << "    " << var1 << endl;
    cout << *mat << endl;
    return 0;
}

int main()
{

    int dig;
    cout << "qual modelo do ex 17 voce deseja iniciar ??" << endl
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
