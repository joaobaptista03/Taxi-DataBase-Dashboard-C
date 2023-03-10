/**
 * @file tests.c
 *  Este ficheiro contém as funções relacionadas com os testes funcionais e de desempenho.
 * 
 */

#include <time.h>

#include "../include/query1.h"
#include "../include/query2.h"
#include "../include/query3.h"
#include "../include/query4.h"
#include "../include/query5.h"
#include "../include/query6.h"
#include "../include/query7.h"
#include "../include/query8.h"
#include "../include/query9.h"
#include "../include/files.h"

void check(int counter) {
    char filename[30], filepath[60], resultfile[50];
    sprintf(filename, "command%d_output.txt", counter);
    sprintf(resultfile, "Resultados/%s", filename);

    sprintf(filepath, "test-outputs/%s", filename);

    FILE *expected = fopen(filepath, "r");
    FILE *result = fopen(resultfile, "r");
    if (compare(expected, result)) printf("Test %d passed ✅\n", counter);
        else printf("Test %d failed ❌\n", counter);
    fclose(expected);
    fclose(result);
}

void q1_test(int counter, char *id) {
    query1(counter, id, 3);
    check(counter);
}

void q2_test(int counter, char *input) {
    query2(counter, input, 3);
    check(counter);
}

void q3_test(int counter, char *input) {
    query3(counter, input, 3);
    check(counter);
}

void q4_test(int counter, char *input) {
    query4(counter, input, 3);
    check(counter);
}

void q5_test(int counter, char *data1, char *data2) {
    query5(counter, data1, data2, 3);
    check(counter);
}

void q6_test(int counter, char *input) {
    query6(counter, input, 3);
    check(counter);
}

void q7_test(int counter, char *input) {
    query7(counter, input, 3);
    check(counter);
}

void q8_test(int counter, char *input) {
    query8(counter, input, 3);
    check(counter);
}

void q9_test(int counter, char *data1, char *data2) {
    query9(counter, data1, data2, 3);
    check(counter);
}

int main() {

    clock_t start = clock();

    puts("Bem-vindo ao Programa de Testes! Para continuar, coloque o caminho do diretório dos ficheiros CSV (Dataset Large with Invalid entries obrigatoriamente).\n");

    char csvs[200];
    scanf("%s", csvs);

    FILE *drivers = open_files(csvs, "/drivers.csv");
    FILE *users = open_files(csvs, "/users.csv");
    FILE *rides = open_files(csvs, "/rides.csv");
    FILE *inputs = fopen("test-outputs/inputs.txt", "r");

    system("mkdir Resultados");
    
    inserir_drivers(drivers);
    inserir_users(users);
    inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';
        puts("-----------------------------------------------");
        printf("Input: %s\n", input);
        if (input[0] == '1') q1_test(counter, input + 2);
        else if (input[0] == '2') q2_test(counter, input + 2);
        else if (input[0] == '3') q3_test(counter, input + 2);
        else if (input[0] == '4') q4_test(counter, input + 2);
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13);
        else if (input[0] == '6') q6_test(counter, input + 2);
        else if (input[0] == '7') q7_test(counter, input + 2);
        else if (input[0] == '8') q8_test(counter, input + 2);
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13);
        counter++;
    }

    free_drivers();
    free_users();
    free_rides();
    free_all_stats();

    fclose(inputs);
    free(input);
    system("rm -r Resultados");
    puts("-------------------------------------------");

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );
}