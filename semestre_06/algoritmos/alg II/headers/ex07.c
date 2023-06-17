#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[100], cpf[14];
    int dia, mes, ano;
}Cadastro;


void coleta_dados(Cadastro *dados){
    strcpy(dados->nome, "beatriz saito");
    strcpy(dados->cpf, "070.956.635-06");
    dados->dia = 07;
    dados->mes = 03;
    dados->ano = 1992;
}

void imprime(Cadastro *dados){
    printf("NOME: %s\n", dados->nome);
    printf("CPF: %d\n", dados->cpf);
    printf("DATA DE NASCIMENTO: %d/%d/%d", dados->dia, dados->mes, dados->ano);
}
int main (){

    Cadastro *dados = malloc(sizeof(Cadastro));

    coleta_dados(dados);
    imprime(dados);
    printf("\n\n");

    return 0;
}
