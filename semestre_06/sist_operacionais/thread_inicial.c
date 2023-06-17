//aprendendo a criar thread

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> //biblioteca que chama a thread


void *funcao1 (void *arg) {
printf("hello world da thread 1\n");
pthread_exit ((void*) NULL);
}
void *funcao2 (void *arg) {
printf("hello world da thread 2\n");
pthread_exit ((void*) NULL);
}
int main (){

pthread_t t1, t2; //criando a tread
pthread_create(&t1, NULL, funcao1, NULL);
pthread_create(&t2, NULL, funcao2, NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);

return 0;
}

// *****LINOX****
//ls----mostra o que tem dentro da pasta |||| cd----entra na pasta
//salvar o arquivo com a linguagem desejada-----ex: este esta na linguagem "C"
//terminal chamar o lacal salvo ----- ex: documento, eng comp7, beatriz saito.
// exemplo para chamar o cod***** gcc -pthread (nome do arquivo.linguagem)(tread.c) -o (nomeia o arquivo)(tread)
// ./(nome do arquivo)