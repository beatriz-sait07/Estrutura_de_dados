#include <math.h>
#include <stdio.h>
#include<stdlib.h>

//f(x) = expf(x) * ((x-1) / 2)
float n(float x)
{
    return expf(-x) * ((x-1) / 2);
}

//valor aproximado da raiz
float dicotomia(float a, float b, float precisao)
{
    int i=1;
    float c, fa, fb, fc;
    //dando resultados para funcao f(x)
    fa = n(a);
    fb = n(b);

    while(fabs(b-a)>precisao){//verifica se o valor absoluto é < presisão
        c = (a+b)/2;//ponto médio
        fc = n(c);//resultado de f(c) = uma variavel

        printf("| %d  | %f | %f | %f | %f   | %f   | %f |\n", i, a, b, c, fc, fa*fc, fabs(b-a));

        //verificaando sinais
        //negativo
        if(fa*fc<0){
            b=c;
            fb = fc;
        }
        //positivo
        else{
            a=c;
            fa = fc;
        }
    i++;
    }

    //raiz da função
    c = (a+b)/2;
    return c;
}

int main (){


    printf("\t\texercicio 02\n");
    float xa = 0, xb = 2, R;
    float prc = 0.0001;

    printf("valores para os intervalos [0, 2]:\n");
  
    printf("| i  |     XA    |     XB    |     XC    |     F(c)     |    Fa*Fc   |   |b-a|  |\n");

    //intervalo na precisão
    R = dicotomia(xa, xb, prc);

    printf("\nRaiz Aproximada = %.4f\n", R);

return 0;
}
