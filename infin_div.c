/*
** EPITECH PROJECT, 2021
** INFIN_DIV
** File description:
** MAIN
*/

#include <unistd.h>
#include "./include/my.h"
#include <stdlib.h>

void adjust_length(char **min, char **max);
void get_max_min(char *nb1, char *nb2, char **min, char **max);
int delete_signe(char **nb1, char **nb2);
char *add_signe(char *nb, char signe);
char *infin_add(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
char *get_div(char *min, char *max, char signe1, char signe2);
char *itoa(int number);

char *infin_div_int(char *nb1, char *nb2)
{
    int nb_1 = my_getnbr(nb1);
    int nb_2 = my_getnbr(nb2);

    if (nb1[0] == '0' || nb2[0] == '0') return "E";
    return itoa(nb_1 / nb_2);
}

char *infin_div(char *nb1, char *nb2)
{
    if (my_strlen(nb1) + my_strlen(nb2) > 10) {
        char *min = {0};
        char *max = {0};
        char nb1_signe = nb1[0];
        char nb2_signe = nb2[0];

        delete_signe(&nb1, &nb2);
        get_max_min(nb1, nb2, &min, &max);
        adjust_length(&min, &max);
        if (nb1[0] == '0' || nb2[0] == '0') return "E";
        if (max == nb1) {
            nb2 = max;
            nb1 = min;
        } else {
            nb1 = max;
            nb2 = min;
        }
        return get_div(nb1, nb2, nb1_signe, nb2_signe);
    } else
        return infin_div_int(nb1, nb2);
}