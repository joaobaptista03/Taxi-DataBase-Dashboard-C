/**
 * @file batch.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com o modo Batch.
 * 
 */

#include "../include/batch.h"

void batch (char **argv) {
    FILE *drivers = open_files(argv[1], "/drivers.csv");
    FILE *users = open_files(argv[1], "/users.csv");
    FILE *rides = open_files(argv[1], "/rides.csv");
    FILE *inputs; inputs = fopen(argv[2], "r");

    Driver *drivers_cat = inserir_drivers(drivers);
    return_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    handle_inputs(drivers_cat, users_struct.userscat, users_struct.usershash, rides_cat, inputs);

    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");
}