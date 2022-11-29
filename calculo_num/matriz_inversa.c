#include<stdio.h>
#include<stdlib.h>

float principal(float [][25], float);
void solucao(float [][25], float);
void transposta(float [][25], float [][25], float);

int main(){
    float a[25][25], n, d;

    printf("Digite a ordem da matriz que esta no arquivo: ");
    scanf("%f", &n);

    FILE *arq = fopen("inversa.csv", "r");
    if(arq == NULL){
        printf("\n\nErro na abertura do arquivo!\n");
        exit(1);
    }

    printf("\n\n\t\t\t MATRIZ ORIGEM\n");
    int i, j;
    for(i=0; i<n; i++){
        printf("\n");
        for(j=0; j<n; j++){
            fscanf(arq, "%f,", &a[i][j]);
            printf("\t%f", a[i][j]);
        }
    }
    d = principal(a, n);
    if (d == 0)
    printf("\nERRO! \nNÃO É POSSIVEL UTILIZAR ESTA MATRIZ PARA O METOTO DE INVERSAO DE GAUSS JORDAN!\n");
    else
    solucao(a, n);

printf("\n\n\n");
return 0;
}

float principal(float a[25][25], float k)
{
    float s=1, det=0, b[25][25];
    int i, j, m, n, c;
    if(k == 1){
        return (a[0][0]);
    }else{
        det = 0;
        for (c = 0; c < k; c++){
            m = 0;
            n = 0;
            for (i = 0;i < k; i++){
                for (j = 0 ;j < k; j++){
                    b[i][j] = 0;
                    if (i != 0 && j != c){
                        b[m][n] = a[i][j];
                        if (n < (k - 2)){
                            n++;
                        }else{
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * principal(b, k - 1));
            s = -1 * s;
        }
    }
    return (det);
}

void solucao(float num[25][25], float f)
{
    float b[25][25], fac[25][25];
    int p, q, m, n, i, j;
    for (q = 0;q < f; q++){
        for (p = 0;p < f; p++){
            m = 0;
            n = 0;
            for (i = 0;i < f; i++){
                for (j = 0;j < f; j++){
                    if (i != q && j != p){
                        b[m][n] = num[i][j];
                        if (n < (f - 2)){
                            n++;
                        }else{
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] =  (-1^(q + p)) * principal(b, (f - 1));
        }
    }
    transposta(num, fac, f);
}

void transposta(float num[25][25], float fac[25][25], float x)
{
    int i, j;
    float b[25][25], inversa[25][25], d;

    for (i = 0;i < x; i++){
        for (j = 0;j < x; j++){
            b[i][j] = fac[j][i];
        }
    }
    d = principal(num, x);
    for (i = 0;i < x; i++){
        for (j = 0;j < x; j++){
            inversa[i][j] = b[i][j] / d;
        }
    }

    printf("\n\n\t\t\t MATRIZ INVERSA\n");
    
    for (i = 0;i < x; i++){
        printf("\n");
        for (j = 0;j < x; j++){
            printf("\t%f", inversa[i][j]);
        }
    }

}
