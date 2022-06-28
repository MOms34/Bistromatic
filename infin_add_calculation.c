/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** Main
*/

#include "./include/my.h"
#include <stdlib.h>

char *add_signe(char *nb, char signe);
int delete_signe(char **nb1, char **nb2);

char *print_sub_result(char *result, char signe_max, char retenue)
{
    int k = 1;

    while (result[my_strlen(result) - k] == '0')
        k++;
    result[my_strlen(result) - k + 1] = '\0';
    result = my_revstr(result);
    result = add_signe(result, signe_max);
    return result;
}

char *get_add(char *min, char *max)
{
    char retenue = '0';
    int i = my_strlen(min) - 1;
    int j = 0;
    int k = 1;
    char *result = malloc(sizeof(char) * (my_strlen(max) * 2));

    while (i >= 0) {
        result[j] = ((max[i] - 48 + min[i] - 48 + retenue - 48) % 10) + 48;
        retenue = ((max[i] - 48 + min[i] - 48 + retenue - 48) / 10) + 48;
        i--;
        j++;
    }
    if (retenue != '0')
        result = my_revstr(add_signe(my_revstr(result), retenue));
    result = my_revstr(result);
    return result;
}

char *get_sub(char *min, char *max, char signe_max)
{
    char retenue = '0';
    int i = my_strlen(min) - 1;
    int j = 0;
    int k = 1;
    char *r = malloc(sizeof(char) * (my_strlen(max) + 2));

    while (i >= 0) {
        if (min[i] + retenue - 48 > max[i]) {
            r[j] = ((max[i] + 10 - 48) - (min[i] - 48 + retenue - 48) + 48);
            retenue = '1';
        } else {
            r[j] = (((max[i] - 48) - (min[i] - 48)  - (retenue - 48)) + 48);
            retenue = '0';
        }
        i--;
        j++;
    }
    return print_sub_result(r, signe_max, retenue);
}

void adjust_length(char **min, char **max)
{
    int i = 0;
    char *min_temp = malloc(sizeof(char) * (my_strlen(*max) + 2));

    while (i < my_strlen(*max) - my_strlen(*min)) {
        min_temp[i] = '0';
        i++;
    }
    my_strcat(min_temp, *min);
    *min = min_temp;
}

void get_max_min(char *nb, char *nb2, char **min, char **max)
{
    int k = 0;

    if (my_strlen(nb) > my_strlen(nb2)) {
        *max = nb;
        *min = nb2;
    } else if (my_strlen(nb) < my_strlen(nb2)) {
        *max = nb2;
        *min = nb;
    } else {
        while (nb[k] == nb2[k] && nb[k + 1] == '\0')
            k++;
        (nb[k] > nb2[k]) ? (*max = nb, *min = nb2) : (*max = nb2, *min = nb);
    }
}