/*14.
Escreva um programa que implemente uma fila circular utilizando uma lista linear. O
programa deve ser capaz de inserir, remover e informar o tamanho da fila em um dado
momento.
*/
#include<stdio.h>
#include<stdlib.h>
#include"ex014.h"

int main(){

    Queue *fila = create_Queue();
    int tam, removido;


    printf("-------- ENQUEUE (10, 50, 30, 40, 60) --------\n");
    enqueue_Queue(fila, 10);
    enqueue_Queue(fila, 50);
    enqueue_Queue(fila, 30);
    enqueue_Queue(fila, 40);
    enqueue_Queue(fila, 60);
    print_Queue(fila);

    tam = size_Queue(fila);
    printf("\nTamanho da fila: %d elementos\n\n", tam);

    printf("-------- ENQUEUE (20, 80, 70) --------\n");
    enqueue_Queue(fila, 20);
    enqueue_Queue(fila, 80);
    enqueue_Queue(fila, 70);
    print_Queue(fila);

    tam = size_Queue(fila);
    printf("\nTamanho da fila: %d elementos\n\n", tam);

    printf("-------- DEQUEUE --------\n");
    removido = dequeue_Queue(fila);
    printf("Dequeue no %d\n", removido);
    print_Queue(fila);

    tam = size_Queue(fila);
    printf("\nTamanho da fila: %d elementos\n\n", tam);
    
    printf("-------- DEQUEUE --------\n");
    removido = dequeue_Queue(fila);
    printf("Dequeue no %d\n", removido);
    print_Queue(fila);

    tam = size_Queue(fila);
    printf("\nTamanho da fila: %d elementos\n\n", tam);

    destroy_Queue(&fila);

return 0;
}