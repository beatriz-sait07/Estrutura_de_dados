#include <stdio.h>
#include <math.h>

float func(float x)
{

  return exp(x) + ((1/2) * x);
}

float drv(float x)//DERIVADA
{
  float y;
  y = 2 + sin(x);
  return y;
}

float newR(float x0, float p) //FUNCAO QUE EFETUA O METODO DE NEWTON
{
    float xa, xa_anterior, funcao, derivada;

    int i=0;

    xa_anterior = 2 * p;

    printf("| i |    x    |   x+1   | precisao |\n");
    while(fabs(x0 - xa_anterior) > p){ 
        xa_anterior = x0;
        funcao = func(x0);
        derivada = drv(x0);
        xa = x0 - (funcao/derivada); 
        x0 = xa;
        i++;
        //IMPRIME VALORxANTERIOR, RESULTADODAFORMULA E PRECISÃO RESPECTIVAMENTE
        printf("| %d | %f | %f | %f |\n", i, xa_anterior, xa, p);

        if(i == 10){
            break;
        }
    }
return xa;//RETORNA O RESULTADO DA RAIZ
}

int main(){
  float raiz;

  printf("METODO DE NEWTON-RAPHSON Ex01:\n\n");

  raiz = newR (0.3927, 0.0001);//ATRIBUINDO VALORxINCIAL E A PRECISÃO
  printf("\nvalor da raiz = %g\n", raiz);

return 0;
}
