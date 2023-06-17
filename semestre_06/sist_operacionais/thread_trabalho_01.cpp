#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int vetor[50];
pthread_t threads [4];

void* parte1 (void* arg){
	for (int i = 0; i < 10; i++){
		printf("[%s]: vetor[%2d] = [%3d]\n", (char*)arg, i, vetor[i]);
	}	
	printf("fim de execucao (0 - 9) %s", (char*)arg);
	pthread_exit (arg);
}

void* parte2 (void* arg){
	for (int i = 10; i < 20; i++){
		printf("[%s]: vetor[%2d] = [%3d]\n", (char*)arg, i, vetor[i]);
	}	
	printf("fim de execucao (10 - 19) %s", (char*)arg);
	pthread_exit (arg);
}


void* parte3 (void* arg){
	for (int i = 20; i < 30; i++){
		printf("[%s]: vetor[%2d] = [%3d]\n", (char*)arg, i, vetor[i]);
	}	
	printf("fim de execucao (20 - 29) %s", (char*)arg);
	pthread_exit (arg);
}

void* parte4 (void* arg){
	for (int i = 30; i < 40; i++){
		printf("[%s]: vetor[%2d] = [%3d]\n", (char*)arg, i, vetor[i]);
	}	
	printf("fim de execucao (30 - 49) %s", (char*)arg);
	pthread_exit (arg);
}
int ex4(float num4){
	
	return 0;
}

int main (){
	
	for (int i = 0; i < 50; i++){
		vetor[i] = i;
	}
	
	printf("      VOCE ESTA EXECUTANDO A PRIMEIRA PARTE DA THREAD\n\n!");
	pthread_create(&threads[0], NULL, parte1, (void*)("Thread_1"));
	printf("Thread_1 iniciada...\n");
	pthread_join(threads[0], NULL);
	
	printf("      VOCE ESTA EXECUTANDO A PRIMEIRA PARTE DA THREAD\n\n!");
	pthread_create(&threads[10], NULL, parte2, (void*)("Thread_2"));
	printf("Thread_2 iniciada...\n");
	pthread_join(threads[10], NULL);
	
	printf("      VOCE ESTA EXECUTANDO A PRIMEIRA PARTE DA THREAD\n\n!");
	pthread_create(&threads[20], NULL, parte3, (void*)("Thread_3"));
	printf("Thread_3 iniciada...\n");
	pthread_join(threads[20], NULL);
	
	printf("      VOCE ESTA EXECUTANDO A PRIMEIRA PARTE DA THREAD\n\n!");
	pthread_create(&threads[30], NULL, parte4, (void*)("Thread_4"));
	printf("Thread_4 iniciada...\n");
	pthread_join(threads[30], NULL);
	
	return 0;
}
