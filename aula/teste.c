#include<stdio.h>
#include<stdlib.h>

typedef struct cadastro_struc {
    /*char nome_cad[50];
    char rua_cad[50];
    char cell_cad[15];*/
    int n1, n2, media;
} Dados;

int cadastro (Dados *p, int num1, int num2){
    p->n1 = num1;
    p->n2 = num2;
    p->media = num1 + num2;

    return p->media;
}

int main (){

    Dados *pessoa;
    cadastro(&pessoa, 1, 7);
    printf("media: %d\n", pessoa.media);

    return 0;
}