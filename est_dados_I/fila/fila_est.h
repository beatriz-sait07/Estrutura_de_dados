#ifndef FILA_EST_H
#define FILA_EST_H
#include <stdbool.h>

typedef struct _static_queue StaticQueue;

StaticQueue *create_StaticQueue(long capacity);
void destroy_StaticQueue(StaticQueue **Q_Ref);

bool is_empty_StaticQueue(const StaticQueue *Q);
bool is_full_StaticQueue(const StaticQueue *Q);
long size_StaticQueue(const StaticQueue *Q);
void print_StaticQueue(const StaticQueue *Q);

void enqueue_StaticQueue(StaticQueue *Q, int info);
int dequeue_StaticQueue(StaticQueue *Q);
int peek_StaticQueue(const StaticQueue *Q);

#endif