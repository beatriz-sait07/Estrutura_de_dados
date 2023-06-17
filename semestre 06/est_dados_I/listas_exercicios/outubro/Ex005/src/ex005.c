#include "ex005.h"

typedef struct _car{
    char *matricula;
    char *proprietario;
    char *hora_entrada;
    char *hora_saida;
    struct _car *next;
}Car;
typedef struct _carpark{
    Car *begin;
    Car *end;
    int size;
}CarPark;

Car *create_Car(char *matricula, char *proprietario, char *hora_entrada)
{
    Car *carro = (Car*)calloc(1, sizeof(Car));
    carro->matricula = matricula;
    carro->proprietario = proprietario;
    carro->hora_entrada = hora_entrada;
    carro->hora_saida = "00:00:00";
}
CarPark *CarPark_create()
{
    CarPark *park = (CarPark*)calloc(1, sizeof(CarPark));
    park->begin = NULL;
    park->end = NULL;
    park->size = 0;
}
bool is_Empty(const CarPark *park)
{
    return park->begin == NULL;
}

void register_Car(CarPark *park, char *matricula, char *proprietario, char *hora_entrada)
{
    Car *new = create_Car(matricula, proprietario, hora_entrada);

    if(is_Empty(park)){
        park->begin = park->end = new;
    }else{
        park->end->next = new;
        park->end = new;
    }
    park->size++;
}

void car_exit(CarPark *park, char *matricula, char *hora_saida)
{
    Car *p = park->begin;
    while(p != NULL && p->matricula != matricula){
        p = p->next;
    }
    p->hora_saida = hora_saida;
    park->size--;

}

void print_park(const CarPark *park)
{
    Car *p = park->begin;

    printf("\n------------------  Lista de Carros ------------------\n");
    printf("Quantidade de Carros no Park: %d", park->size);
    printf("\n| Matricula | Proprietario | Hora Entrada |  Hora Saida  |\n");
    while(p != NULL){
        printf("|  %s   |    %s    |   %s   |   %s   |\n", p->matricula, p->proprietario, p->hora_entrada, p->hora_saida);
        p = p->next;
    }
    printf("\n");
}