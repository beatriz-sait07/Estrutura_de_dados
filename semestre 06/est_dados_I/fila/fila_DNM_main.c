#include"fila_dinam.h"
#include<stdio.h>
#include<stdlib.h>

int main(){

    Queue *fila = create_Queue();

    //Fila Vazia:
    // print_Queue(fila);
    // int val = peek_Queue(fila);

    printf("-------- ENQUEUE (10, 50, 30) --------\n");
    enqueue_Queue(fila, 10);
    enqueue_Queue(fila, 50);
    enqueue_Queue(fila, 30);
    print_Queue(fila);

    int val = peek_Queue(fila);
    printf("PEEK: %d\n", val);

    val = dequeue_Queue(fila);
    printf("DEQUEUE: %d\n", val);
    print_Queue(fila);

    printf("-------- ENQUEUE (60, 70, 80) --------\n");
    enqueue_Queue(fila, 60);
    enqueue_Queue(fila, 70);
    enqueue_Queue(fila, 80);
    enqueue_Queue(fila, 90);
    print_Queue(fila);

    val = peek_Queue(fila);
    printf("PEEK: %d\n", val);

    val = dequeue_Queue(fila);
    printf("DEQUEUE: %d\n", val);
    print_Queue(fila);

    destroy_Queue(&fila);

return 0;
}