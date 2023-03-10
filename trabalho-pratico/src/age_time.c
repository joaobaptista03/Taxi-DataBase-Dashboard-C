/**
 * @file age_time.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Datas.
 * 
 */

#include "../include/age_time.h"

#define TODAY_YEAR 2022
#define TODAY_MONTH 10
#define TODAY_DAY 9

bool isDate(char *date) {
    return (
        (strlen(date) == 10) &&
        isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]) &&
        (date[2] == '/') && (date[5] == '/') &&
        (((date[3]-48)*10 + date[4]-48) <= 12) && (((date[0]-48)*10 + date[1]-48) >= 1) &&
        (((date[0]-48)*10 + date[1]-48) <= 31) && (((date[0]-48)*10 + date[1]-48) >= 1)
    );
}

int age(char date[]) {

    int day = (date[0]-48)*10 + date[1]-48;
    int month = (date[3]-48)*10 + date[4]-48;
    int year = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)*10 + date[9]-48;

    int alr_bday = 1;

    if (TODAY_MONTH > month) alr_bday = 0;
    else if (TODAY_MONTH == month) {
        if (TODAY_DAY >= day) alr_bday = 0;
    }

    return TODAY_YEAR - year - alr_bday;
}