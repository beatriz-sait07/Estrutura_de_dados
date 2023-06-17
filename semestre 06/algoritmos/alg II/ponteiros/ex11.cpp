#include <iostream>
#include <math.h>
using namespace std;

float func1(float x)
{
    float var;
    var = (pow(x, 2) / 3) + (pow(x, 3) / 2) - (x / 10);
    return var;
}

float func2(float x)
{
    float y;
    y = (1 / pow((5 * x), 2)) - (10 / x);
    return y;
}
float func3(float x)
{
    float B = pow((x - 2), 2) * ((2 * x - 3));
    return B;
}
float func4(float x)
{
    float C = x / 2, sqrt(x);
    return C;
}
float func5(float x)
{
    float resul = exp(-5 * x);
    return resul;
}
float func6(float x)
{
    float result = -12 + (3 / 7 * (exp(-x) - 1));
    return result;
}
float func7(float x)
{
    float result = 1 / 3 * sin(3 * x);
    return result;
}
float func8(float x)
{
    float result = 3 * sin(((5 * acos(0.0) / 3) * x) + (acos(0.0) / 10));
    return result;
}
float func9(float x)
{
    float result = log(x + 1);
    return result;
}
float func10(float x)
{
    float result = log(log(x + 1));
    return result;
}
int ex1()
{
    cout << "voce esta executando o exercicio num 7!" << endl;
    float X = 3.2, *x = &X;
    float funcA = func1(*x);
    float funcB = func2(*x);
    float funcC = func3(*x);
    float funcD = func4(*x);
    float funcE = func5(*x);
    float funcF = func6(*x);
    float funcG = func7(*x);
    float funcH = func8(*x);
    float funcI = func9(*x);
    float funcJ = func10(*x);

    cout << "f(x) = x^2/3 + x^3/2 - x/10 = " << funcA << endl;
    cout << "f(x) = 1/5x^2 - 10/x = " << funcB << endl;
    cout << "f(x) = (x-2)^2 * (2x-3) = " << funcC << endl;
    cout << "f(x) = x/2*sqrt(x) = " << funcD << endl;
    cout << "f(x) = e^-5x = " << funcE << endl;
    cout << "f(x) = -12 + 3/7*(e^-x - 1) = " << funcF << endl;
    cout << "f(x) = 1/3*sin(3x) = " << funcG << endl;
    cout << "f(x) = 3*sin((5*pi/3)*x + pi/10) = " << funcH << endl;
    cout << "f(x) = ln(x+1) = " << funcI << endl;
    cout << "f(x) = ln(ln(x)) = " << funcJ << endl;

    return 0;
}

int ex2()
{
    cout << "voce esta executando o exercicio num 7! (por matriz)" << endl;
    float (*matriz[])(float) = {func1, func2, func3, func4, func5, func6, func7, func8, func9, func10};
    float x = 3.2, *y = &x;
    (*matriz[0])(*y);
    cout << matriz[0](*y) << endl;

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
