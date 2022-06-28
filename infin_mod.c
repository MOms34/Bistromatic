/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** --
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
char *get_mod(char *min, char *max);
char *itoa(int number);

char *infin_mod_int(char *nb1, char *nb2)
{
    int nb_1 = my_getnbr(nb1);
    int nb_2 = my_getnbr(nb2);

    if (nb1[0] == '0' || nb2[0] == '0') return "E";
    return itoa(nb_1 % nb_2);
}

char *infin_mod(char *nb1, char *nb2)
{
    if (my_strlen(nb1) + my_strlen(nb2) > 10) {
        char *min = {0};
        char *max = {0};
        char *result = {0};
        char nb1_signe = nb1[0];
        char nb2_signe = nb2[0];

        delete_signe(&nb1, &nb2);
        get_max_min(nb1, nb2, &min, &max);
        adjust_length(&min, &max);
        if (nb1[0] == '0' || nb2[0] == '0') return "E";
        return get_mod(nb1, nb2);;
    } else
        return infin_mod_int(nb1, nb2);
}