#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define M 5

int main()
{

         FILE *arq = fopen("ex2.csv", "r");
		 float a[M][M], x[M], ratio;
		 int i,j,k,n;
	
		 
		 printf("ordem do sistema: ");
		 scanf("%d", &n);
		 
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n+1;j++)
			  {
				   fscanf(arq, "%f,", &a[i][j]);

			  }
         
		 }
		 
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("ERRO NA MATRIZ!");
				   exit(0);
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=n+1;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		
		 for(i=1;i<=n;i++)
		 {
		  	x[i] = a[i][n+1]/a[i][i];
		 }

		 printf("\n\t\tResultado\n");

		 for(i=1;i<=n;i++)
		 {
		  	printf("x[%d] = %0.3f\n",i, x[i]);
		 }

		 return(0);
}
