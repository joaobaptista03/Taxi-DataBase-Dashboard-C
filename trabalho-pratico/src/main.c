/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <string.h>

#include "../include/catalog.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Número de argumentos inválido (%i).\n", argc);
        return -1;
    }

    FILE *drivers;
        char *driverspath;
        driverspath = (char *) malloc(1000 * sizeof(char));
        strcpy(driverspath, argv[1]);
        strcat(driverspath, "drivers.csv");
        drivers = fopen(driverspath, "r");
        free(driverspath);
    FILE *users;
        char *userspath;
        userspath = (char *) malloc(1000 * sizeof(char));
        strcpy(userspath, argv[1]);
        strcat(userspath, "users.csv");
        users = fopen(userspath, "r");
        free(userspath);
    FILE *rides;
        char *ridespath;
        ridespath = (char *) malloc(1000 * sizeof(char));
        strcpy(ridespath, argv[1]);
        strcat(ridespath, "rides.csv");
        rides = fopen(ridespath, "r");
        free(ridespath);
    FILE *inputs;
        inputs = fopen(argv[2], "r");

    inserir_dados(drivers, users, rides, inputs);                             // Inserir dados nos catálogos

    fclose(drivers);
    fclose(rides);
    fclose(users);
    fclose(inputs);
    
    return 0;
}
