#include "float_vector.h"
#include <stdio.h>
struct float_vector
{
    int capacity; //numero maximo de elementos
    int size; //controlar a quantidade atual de elementos
    float *data; //vetor de float
};

/**
*@brief Cria(aloca) um vetor de flaot com uma dada capacidade
*
* @param tam
* @return FloatVector* ponteiro de um vetor de floats
**/

FloatVector *create (int tam) //aloca dinamicamente
{
FloatVector *vet = (FloatVector*)calloc(1, sizeof(FloatVector)); //quantidade
vet -> capacity = tam;
vet -> size = 0;
vet -> data = (float*) calloc(vet->capacity, sizeof(float));
//vet -> data = (float*) malloc(quantidade de vetor * tam)

return vet;
}

void destroy (FloatVector **vet_ref)
{
    FloatVector *vet = *vet_ref;
    free(vet->data); //pegou a strutura e dentro dela, entrou na var data e destruiu ela
    free(vet); //aqui destruiu a estrutura inteira
    *vet_ref = NULL; //setamo null no valor da função main para não causar um mal subito no pc 
}