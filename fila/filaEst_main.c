#include"fila_est.h"

#include<stdio.h>
#include<stdlib.h>

int main(){

    StaticQueue *fila = create_StaticQueue(5);

    // Fila Vazia:
    // print_StaticQueue(fila);
    // int val = peek_StaticQueue(fila);

    printf("-------- ENQUEUE (10, 50, 30) --------\n");
    enqueue_StaticQueue(fila, 10);
    enqueue_StaticQueue(fila, 50);
    enqueue_StaticQueue(fila, 30);
    print_StaticQueue(fila);

    int val = peek_StaticQueue(fila);
    printf("PEEK: %d\n", val);

    val = dequeue_StaticQueue(fila);
    printf("DEQUEUE: %d\n", val);
    print_StaticQueue(fila);

    printf("-------- ENQUEUE (60, 70, 80) --------\n");
    enqueue_StaticQueue(fila, 60);
    enqueue_StaticQueue(fila, 70);
    enqueue_StaticQueue(fila, 80);
    // enqueue_StaticQueue(fila, 90); // Fila Cheia
    print_StaticQueue(fila);

    val = peek_StaticQueue(fila);
    printf("PEEK: %d\n", val);

    val = dequeue_StaticQueue(fila);
    printf("DEQUEUE: %d\n", val);
    print_StaticQueue(fila);

    destroy_StaticQueue(&fila);


return 0;
}