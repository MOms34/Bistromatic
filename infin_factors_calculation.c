/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** --
*/

#include "./include/my.h"
#include <stdlib.h>

char *infin_add(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
char *infin_mul(char *nb1, char *nb2);
char *infin_div(char *nb1, char *nb2);
char *add_signe(char *nb, char signe);

int check_max_strnb(char *nb1, char *nb2)
{
    int k = 0;

    if (my_strlen(nb1) > my_strlen(nb2))
        return 1;
    else if (my_strlen(nb1) < my_strlen(nb2))
        return 2;
    else {
        while (nb1[k] == nb2[k] && nb1[k + 1] != '\0')
            k++;
        if (nb1[k] > nb2[k])
            return 1;
        else if (nb1[k] < nb2[k])
            return 2;
        else
            return 3;
    }
}

char *get_div(char *nb1, char *nb2, char nb1_signe, char nb2_signe)
{
    char *compteur = malloc(1 * (my_strlen(nb1) + my_strlen(nb2) + 2));
    char *result = malloc(1 * (my_strlen(nb1) + my_strlen(nb2) + 2));

    compteur = "0";
    while (check_max_strnb(nb2, result) == 1) {
        compteur = infin_add(compteur, "1");
        result = infin_mul(nb1, compteur);
    }
    if (check_max_strnb(nb2, result) != 3) {
        compteur = infin_sub(compteur, "1");
        if (nb1_signe == '-' || nb2_signe == '-')
                compteur = add_signe(compteur, '-');
        return compteur;
    }
    if (nb1_signe == '-' || nb2_signe == '-')
        compteur = add_signe(compteur, '-');
    return compteur;
}

char *get_mod(char *nb1, char *nb2)
{
    char *result = malloc(1 * (my_strlen(nb1) * my_strlen(nb2) + 2));

    result = infin_sub(infin_mul(infin_div(nb1, nb2), nb2), nb1);
    if (my_strlen(result) >= 2)
        result += 1;
    return result;
}