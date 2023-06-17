#include <iostream>
#include <string.h>
using namespace std;

char *inverso(char *s)
{
    int tam = strlen(s);
    int i, j;

    for (i = 0, j = tam - 1; i < j; i++, j--)
    {
        int inc = s[i];
        s[i] = s[j];
        s[j] = inc;
    }

    return s;
}

char *inverso1(char s)
{
    char s[] = "bia", *ptr;

    for (ptr = s; *ptr != 0; ptr++)
        putchar(*ptr);

    return s;
}

int ex1()
{
    cout << "voce esta executando o exercicio num 15!" << endl;
    char frase[] = "bem vindo";

    cout << inverso(frase) << endl;
    cout << inverso1(frase) << endl;
    return 0;
}

int ex2()
{
    cout << "voce esta executando o exercicio num 15! (por matriz)" << endl;
    char i[] = "bia", *j = &i;
    char (*matriz[])(char *) = {inverso, inverso1};
    (*matriz[1])(j);
    cout << (*matriz[1])(j);

    return 0;
}

int main()
{

    int dig;
    cout << "qual modelo do ex 15 voce deseja iniciar ??" << endl
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

//************nao consegui finalizar************
