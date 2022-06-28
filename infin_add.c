/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** Main
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

char *infin_add(char *nb1, char *nb2)
{
    char *min = {0};
    char *max = {0};
    char *result = {0};
    char signe = '\0';
    char nb1_signe = nb1[0];
    char nb2_signe = nb2[0];

    delete_signe(&nb1, &nb2);
    get_max_min(nb1, nb2, &min, &max);
    adjust_length(&min, &max);
    if (nb1_signe == '-' && nb2_signe == '-') {
        result = get_add(min, max);
        add_signe(result, '-');
    } else
        return (get_add(min, max));
    return result;
}