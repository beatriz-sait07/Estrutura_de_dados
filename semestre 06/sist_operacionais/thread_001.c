//criando varias threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NUMERO_DE_THREADS 5
void *imprima_ola_mundo(void *tid){
int *id = (int *)(tid);
printf("ola mundo saudacoes da thread %d\n", *id);
pthread_exit ((void * ) NULL);
}
int main (){
pthread_t vet_threads [NUMERO_DE_THREADS];
int status, i;
for (i=1; i<NUMERO_DE_THREADS; i++){
printf("funcao principal (main) aqui. criando a thread %d\n", i);
status = pthread_create(&vet_threads[i], NULL, imprima_ola_mundo, (void *) (&i));
pthread_join(vet_threads[i], NULL);
if (status !=0){
printf("opa....pthread_create retornou o codigo de erro %d\n", status);
return -1;
}
}
return 0;
}