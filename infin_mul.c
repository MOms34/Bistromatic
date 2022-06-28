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
char *infin_mul(char *nb1, char *nb2);
char *itoa(int number);
int my_intlen(int number);

char *add_zero(char *nb, char signe)
{
    char *temp = malloc(sizeof(char) * (my_strlen(nb) + 2));

    my_strcat(temp, nb);
    temp[my_strlen(nb)] = signe;
    temp[my_strlen(nb) + 1] = '\0';
    return temp;
}

char *make_calcul(char nb1, char nb2, char **retenue)
{
    int nb_1 = nb1 - 48;
    int nb_2 = nb2 - 48;
    char *result;
    char *res = malloc(1 * (2 * my_strlen(*retenue) + 2));
    int i;

    nb_1 = nb_1 * nb_2;
    result = infin_add(itoa(nb_1), *retenue);
    *retenue = "0";
    if (my_strlen(result) >= 2) {
        result = my_revstr(result);
        res[0] = result[0];
        result += 1;
        *retenue = my_revstr(result);
    } else
        res = result;
    return res;
}

char *infin_mul(char *nb1, char *nb2)
{
    char *min = {0};
    char *max = {0};
    char nb1_signe = nb1[0];
    char nb2_signe = nb2[0];
    char *result;
    char *final_result;
    char *res_final;
    char *retenue;
    int n;
    int nb_zero = 0;

    delete_signe(&nb1, &nb2);
    get_max_min(nb1, nb2, &min, &max);
    adjust_length(&min, &max);
    result = malloc(1 * (my_strlen(max) * my_strlen(min) + 3));
    res_final = malloc(1 * (my_strlen(max) * my_strlen(min) + 3));
    retenue = malloc(1 * (my_strlen(max) * my_strlen(min) + 1));
    retenue = "0";
    for (int i = my_strlen(max)-1; i >= 0; i--) {
        final_result = malloc(1 * (my_strlen(max) * my_strlen(min) + 1));
        n = 0;
        for (int j = my_strlen(min)-1; j >= 0; j--) {
            if (min[j] != '0') {
                result = make_calcul(max[i], min[j], &retenue);
                final_result[n] = result[0];
                n++;
            } else {
                final_result[n] = retenue[0];
                n++;
                retenue = "0";
            }
        }
        if (retenue[0] != '0')
            final_result[n] = retenue[0];
        for (int j = 0; j != nb_zero; j++) {
            final_result = my_revstr(add_zero(my_revstr(final_result), '0'));
        }
        final_result = my_revstr(final_result);
        res_final = infin_add(res_final, final_result);
        free(final_result);
        result = "0";
        retenue = "0";
        nb_zero++;
    }
    if (nb1_signe == '-' || nb2_signe == '-')
        res_final = add_signe(res_final, '-');
    return res_final;
}