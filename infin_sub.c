/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** --
*/

#include <unistd.h>
#include "./include/my.h"
#include <stdlib.h>

char *print_sub_result(char *result, char signe_max, char retenue);
char *get_add(char *min, char *max);
char *get_sub(char *min, char *max, char signe_max);
void adjust_length(char **min, char **max);
void get_max_min(char *nb1, char *nb2, char **min, char **max);
int delete_signe(char **nb1, char **nb2);
char *add_signe(char *nb, char signe);

void make_simulation_max(int *a, int *b, char nb1_signe, char nb2_signe)
{
    if (nb1_signe == '-' && nb2_signe != '-') {
        *a = -100;
        *b = 10;
    } else if (nb2_signe == '-' && nb1_signe == '-') {
        *a = -100;
        *b = -10;
    } else if (nb1_signe != '-' && nb2_signe == '-') {
        *a = 100;
        *b = -10;
    } else {
        *a = 100;
        *b = 10;
    }
}

void make_simulation_min(int *a, int *b, char nb1_signe, char nb2_signe)
{
    if (nb1_signe == '-' && nb2_signe != '-') {
        *a = -100;
        *b = 1000;
    } else if (nb2_signe == '-' && nb1_signe == '-') {
        *a = -100;
        *b = -1000;
    } else if (nb1_signe != '-' && nb2_signe == '-') {
        *a = 100;
        *b = -1000;
    } else {
        *a = 100;
        *b = 1000;
    }
}

char *get_result(char nb1_signe, char nb2_signe, char *max, char *min, char *n)
{
    char signe = '\0';
    char *result = {0};
    int a;
    int b;

    if (max == n)
        make_simulation_max(&a, &b, nb1_signe, nb2_signe);
    else
        make_simulation_min(&a, &b, nb1_signe, nb2_signe);
    if (nb1_signe == '-' && nb2_signe == '-') {
        result = get_sub(min, max, signe);
    } else if (nb1_signe == '-' || nb2_signe == '-') {
        result = get_add(min, max);
    } else
        result = get_sub(min, max, signe);
    if (a - b < 0)
        result = add_signe(result, '-');
    if (result[0] == '-' && my_strlen(result) == 1)
        return "0";
    return result;
}

char *infin_sub(char *nb1, char *nb2)
{
    char *min = {0};
    char *max = {0};
    char nb1_signe = nb1[0];
    char nb2_signe = nb2[0];

    delete_signe(&nb1, &nb2);
    get_max_min(nb1, nb2, &min, &max);
    adjust_length(&min, &max);
    return get_result(nb1_signe, nb2_signe, max, min, nb1);
}
