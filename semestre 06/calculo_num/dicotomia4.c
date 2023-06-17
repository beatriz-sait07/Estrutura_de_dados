// Dicotomia
// f(x) = x - 3 - x^-x     precisão: 0,0001    intervalo[0:2]


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float dicotomia(float xa, float xb)
{
    float f_xa, dit_xa = xa, f_xb, dit_xb;
    int i = 0;
    f_xa = xa - 3 - pow(xa, -xa);
    f_xb = xb - 3 - pow(xb, -xb);

    //Parte Positiva
    if(f_xb < 0)
    {
        xb = xb + 0.1;
    }
    dit_xb = xb;


    float f_xc, dit_xc, xc_anterior, precisao = 0.0001;
    xc_anterior = dit_xb;
    dit_xc = dit_xa;

    while(fabs(dit_xc - xc_anterior) > precisao)
    {
        xc_anterior = dit_xc;
        dit_xc = (dit_xa + dit_xb) / 2.0;

        f_xa = dit_xa - 3 - pow(dit_xa, -dit_xa);
        f_xb = dit_xb - 3 - pow(dit_xb, -dit_xb);
        f_xc = dit_xc - 3 - pow(dit_xc, -dit_xc);

        if( f_xa * f_xc < 0.0)
        {
            dit_xb = dit_xc;
        }
        else
        {
            if( f_xb * f_xc < 0.0)
            {
                dit_xa = dit_xc;
            }
        }
        i++;
        printf("| %d  | %f | %f | %f | %f   | %f   | %f |\n", i, xa, xb, dit_xa, f_xa, f_xb*f_xc, dit_xa - xc_anterior);

    }
    return (dit_xc);   
}

int main()
{

    printf("\t\texercicio 05\n");
    float raiz = dicotomia(1,3);
    printf("A Raiz aproximada da funcao:  %g\n\n", raiz);

    return (0);
}
