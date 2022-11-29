#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float dicotomia(float xa, float xb)
{
    float f_xa, dit_xa, f_xb, dit_xb;
    
    if(xa > 0.9)
    {
        xb = 1;
        f_xa = pow(xa, 2) - xa + sin(5*xa);
            
        //Parte Positiva
        while(f_xa < 0)
        {
            xa = xa + 0.1;
            f_xa = pow(xa, 2) - xa + sin(5*xa);
        }
        dit_xa = xa;
        dit_xb = xb;
    }

    if(xa > 0.3 && xa < 0.9)
    {
        xb = 0.8;
        f_xa = pow(xa, 2) - xa + sin(5*xa);
            
        //Parte Positiva
        while(f_xa < 0)
        {
            xa = xa - 0.1;
            f_xa = pow(xa, 2) - xa + sin(5*xa);
        }
        dit_xa = xa;
        dit_xb = xb;
    }

    if(xa > -0.25 && xa < 0.28)
    {
        xb = 0.28;
        f_xa = pow(xa, 2) - xa + sin(5*xa);
            
        //Parte Positiva
        while(f_xa < 0)
        {
            xa = xa + 0.1;
            f_xa = pow(xa, 2) - xa + sin(5*xa);
        }
        dit_xa = xa;
        dit_xb = xb;
    }

    if(xa < -0.26)
    {
        xb = -0.26;
        f_xa = pow(xa, 2) - xa + sin(5*xa);
            
        //Parte Positiva
        while(f_xa < 0)
        {
            xa = xa + 0.1;
            f_xa = pow(xa, 2) - xa + sin(5*xa);
        }
        dit_xa = xa;
        dit_xb = xb;
    }
    
    
    float f_xc, dit_xc, xc_anterior, precisao = 0.001;
    xc_anterior = dit_xb;
    dit_xc = dit_xa;

    while(fabs(dit_xc - xc_anterior) > precisao)
    {
        xc_anterior = dit_xc;
        dit_xc = (dit_xa + dit_xb) / 2.0;

        f_xa = pow(dit_xa, 2) - dit_xa + sin(5*dit_xa);
        f_xb = pow(dit_xb, 2) - dit_xb + sin(5*dit_xb);
        f_xc = pow(dit_xc, 2) - dit_xc + sin(5*dit_xc);

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
   float xa, xb;
    printf("\t\texercicio 03\n");
    printf("valores para os intervalos [x,y]:\n");
    printf("x = ");
    scanf("%f", &xa);
    printf("y = ");
    scanf("%f", &xb);

    float raiz = dicotomia(xa, xb);
    printf("A Raiz aproximada da funcao:  %g\n\n", raiz);

    return (0);
}
