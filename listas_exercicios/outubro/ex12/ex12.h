#ifndef ESTATICA
#define ESTATICA
#include <stdbool.h>

typedef struct _static_stack Estatica;
Estatica *create_estatica(long capacity);
void destroy_estatica(Estatica **ref_pilha);
bool estatica_vazia(Estatica *s);
bool estatica_cheia(Estatica *s);
long estatica_tamanho(Estatica *s);
char estatica_push(Estatica *s, char *elem);
char estatica_pop(Estatica *s, Estatica *s1, char *elem);

#endif