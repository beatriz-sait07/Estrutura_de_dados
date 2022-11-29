#ifndef EX12
#define EX12
#include <stdbool.h>

typedef struct _static_stack Estatica;

Estatica *create_estatica(long capacity);
void destroy_estatica(Estatica **ref_pilha);
bool estatica_vazia(Estatica *s);
bool estatica_cheia(Estatica *s);
void estatica_push(Estatica *s, int elem);
void estatica_peek(Estatica *s);
int estatica_pop(Estatica *s, int elem);
void estatica_print(const Estatica *s);



#endif