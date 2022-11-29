/*
Pretende-se fazer a gestao informatica de um parque automovel. Para isso, estipula-se
que, sempre que um automovel entra no parque, deve ser registado a sua matrıcula, o
nome do proprietario e a hora de entrada. Quando o automovel sai, e-lhe dado baixa.
Implemente um programa que permita fazer a gestao do parque, possibilitando ao responsavel 
determinar quantos carros se encontram atualmente no parque e que carros sao esses.
*/

#include<stdio.h>
#include<stdlib.h>
#include "ex005.h"


int main(){

    CarPark *Park = CarPark_create();

    register_Car(Park, "341461", "Taynan", "17:02:03");
    register_Car(Park, "728379", "Brenda", "18:14:57");
    register_Car(Park, "438945", "Robert", "18:35:21");
    register_Car(Park, "238742", "Tereza", "20:00:17");
    register_Car(Park, "686271", "Wesley", "20:00:58");
    register_Car(Park, "384242", "Thiago", "21:15:27");
    register_Car(Park, "968202", "Carlos", "21:26:21");
    register_Car(Park, "602429", "Marcos", "21:34:55");
    register_Car(Park, "929503", "Arthur", "22:41:41");
    register_Car(Park, "981420", "Cleber", "22:58:29");
    register_Car(Park, "238742", "Victor", "23:00:00");

    print_park(Park);

    car_exit(Park, "686271", "20:40:00");
    car_exit(Park, "238742", "21:00:00");
    car_exit(Park, "981420", "23:10:15");

    printf("Wesley, Tereza e Cleber sairam...\n");
    
    print_park(Park);


return 0;
}