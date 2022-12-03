#include <iostream>
#include <locale.h>
using namespace std;

int main()

{
    cout << "voce esta executando o exercicio num 16!" << endl;
    int vet[6] = {3, 5, 6, 9, 8, 2}, *vet1 = &vet[6];
    int x = 3, *cont = &x, final1 = 6, *final = &final1;

    setlocale(LC_ALL, "portuguese");

    for (int i = 0 ; i < final; i++)
    {
        if (cont == vet1[i])
        {
            cout << "valor existente!" << *cont << endl;
        }
        else
        {
            cont = cont + 1;
        }
    }
    if (cont == final)
    {
        cout << "valor inexistente!";
    }
    return 0;
}
