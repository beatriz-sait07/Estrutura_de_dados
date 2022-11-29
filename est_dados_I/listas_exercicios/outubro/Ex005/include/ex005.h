#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct _car Car;
typedef struct _carpark CarPark;

Car *create_car(char *matricula, char *proprietario, char *hora_entrada);
CarPark *CarPark_create();
bool is_Empty(const CarPark *park);

void register_Car(CarPark *park, char *matricula, char *proprietario, char *hora_entrada);
void print_park(const CarPark *park);
void car_exit(CarPark *park, char *matricula, char *hora_saida);
