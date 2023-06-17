#include <iostream>
using namespace std;

// fazendo os calculos para dar a receita na main
void massa_PASTEL(int *pessoa, float *result_mc, float *result_mt, float *result_a, float *result_p, float *result_l)
{
    float maca = (650 / 4), manteiga = (75 / 4), acucar = (150 / 4), pao = (100), leite = (150 / 4);
    *result_mc = maca * (*pessoa);
    *result_mt = manteiga * (*pessoa);
    *result_a = acucar * (*pessoa);
    *result_p = pao * (*pessoa);
    *result_l = leite * (*pessoa);
};

int ex1(void)
{
    cout << "voce esta executando o exercicio 5" << endl;
    float result_mc = 0, result_mt = 0, result_a = 0, result_p = 0, result_l = 0;
    int *pessoa, pessoa1;

    cout << "       VOCE ESTA EXECUTANDO O EXERCICIO 5! " << endl;
    cout << "quantas pessoasl foram convidadas: ";
    cin >> pessoa1; // perguntando quantas pessoas ira na festa

    pessoa = &pessoa1;
    massa_PASTEL(pessoa, &result_mc, &result_mt, &result_a, &result_p, &result_l); // passagem por ref

    // imprimindo os dados
    cout << "receita para " << pessoa1 << " pessoas: " << endl;
    cout << result_mc << "g de maca;" << endl;
    cout << result_mt << "g de manteiga;" << endl;
    cout << result_a << "g de acucar;" << endl;
    cout << result_p << "g de migalhas de pao;" << endl;
    cout << result_l << "ml de leite;" << endl;

    return 0;
}

int crianca(void)
{
    int baby;
    cout << "havera baby ? ( 1 = sim, 0 = nao)" << endl;
    cin >> baby;
    do
    {
        if (baby == 1)
        {
            baby = ex1(); // chamando a primeira funcao e dividando, pois baby come menos
        }
        if (baby == 2)
        {
            baby = ex1(); // chamando a primeira funcao normal
        }
        if (baby < 0)
        {
            cout << "digito invalido!" << endl;
        }
        if (baby > 2)
        {
            cout << "digito invalido!" << endl;
        }
    } while (baby < 2);
}

int ex2()
{

    // não tinh muita ideia do que fazer entao apenas chamei as funcoes e imprimi elas por matriz
    cout << "voce esta executando o exercicio 5 (por matriz de ponteiro)" << endl;
    int (*mat[])(void) = {ex1, crianca};
    (*mat[0])();
    cout << mat[0]() << endl;

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

// receita para quatro pessoas
// maca = 675
// manteiga = 75
// acucar = 150
// pao = 100
// leite = 150
