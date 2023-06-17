#include <iostream>
#include <math.h>
using namespace std;

// criando  as funcoes para cada expressao
int sub(int *x1)
{
    return *x1 - 1;
};
int somar(int *x1)
{
    return *x1 + 1;
};
int func(int *x1)
{
    return ((pow((*x1), 2)) + (*x1) - 2); // (pow) é uma função da biblioteca math.h usada para num exponenciais
};

int ex1()
{
    int x = 4;
    int *x1 = &x;

    cout << "      VOCE ESTA EXECUTANDO O EXERCICIO NUM 3!" << endl;
    int subt = sub(x1);    // chamando as funcoes
    int soma = somar(x1);  // chamando as funcoes
    int funcao = func(x1); // chamando as funcoes

    // imprimindo no terminal as operaçoes e seus respectivos resultados
    cout << *x1 << " - 1 = " << subt << endl;
    cout << *x1 << " + 1 = " << soma << endl;
    cout << *x1 << "^2 + " << x << " - 2 = " << funcao << endl;

    return 0;
}

int ex2()
{
    int (*matriz[])(int *) = {sub, somar};
    cout << "voce esta executando exercicio num 3 (por matriz)" << endl;
    int x = 3, *x1 = &x;
    (*matriz[0])(x1);
    cout << matriz[1](x1) << endl;
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
