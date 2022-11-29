#include <stdio.h>
#include <stdlib.h>

int n;
//float b[30];
//float x[30];
//float a[30][30];

float b[3];
float x[3];
float a[3][3];

void show()
{
      int i, j;

      printf("ordem do sistema linear: n= %d\n\n\n", n);
      for(i = 0; i < n; i++)
      {
          for(j = 0; j < n; j++)
          {
                printf("  %10.6f", a[i][j]);
           }
          printf(" | %10.6f\n", b[i]);
      }
  printf("\n\n\n");

  }

void ler_matriz()
{
      int i, j;

      FILE *arq = fopen("dados.csv", "r");

      if(arq == NULL)printf("nao foi possivel criar o arquivo!\n");


      printf("Ordem do sistema: n= ");
      scanf("%d", &n);
  

      
           for(i = 0; i < n; i++)
           {
                printf("linha %3d:\n", i + 1);
                for(j = 0; j < n; j++)
                {
                    fscanf(arq, "%f,", &(a[i][j]));
                }

                fscanf(arq, "%f,", &(b[i]));
           }
    
     
     show();

}

float det(float a, float b, float c, float d)
{
    return((a * d) - (b * c));
}

void triang()
{
      int i, j, k;

      for(k = 0; k < (n - 1); k++)
      {
            for(i = k + 1; i < n; i++)
            {
                for(j = k + 1; j < n; j++)
                {
                    a[i][j] = det(a[k][k], a[i][k], a[k][j], a[i][j]);
                    show();
                }
            b[i] = det(a[k][k], a[i][k], b[k], b[i]);
            a[i][k] = 0;
            show();
            }
      }
}

void solucao()
{
      int k, j;
      float s;

      x[n - 1] = b[n - 1]/a[n - 1][n - 1];
      for(k = n - 2; k >= 0; k--)
      {
          s = 0;
          for(j = k + 1; j < n; j++)
          {
                s += a[k][j] * x[j];
          }
          x[k] = (b[k] - s) / a[k][k];
      }
}

void imprime()
{
    int i;

    printf("Solucao do sistema linear\n");
    
    for(i = 0; i < n; i++)
    {
        printf("x(%3d)=%10.6g\n", i, x[i]);
    }
  
    printf("Problema encerrado.\n");
}


int main (int argc,char *argv[]){
    
    ler_matriz();
    triang();
    solucao();
    imprime();

    return 0;
}
