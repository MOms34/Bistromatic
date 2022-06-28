/*
** EPITECH PROJECT, 2021
** add_functions
** File description:
** ///
*/

#include "./include/my.h"
#include <stdlib.h>

int my_intlen(int number)
{
    int i;

    for (i = 0; number > 0; i++)
        number = number / 10;
    return i;
}

char *itoa(int number)
{
    char *result = malloc(sizeof(char) * (my_intlen(number) + 1));

    if (number == 0)
        return "0";
    for (int i = my_intlen(number) - 1; i >= 0; i--) {
        result[i] = number % 10 + 48;
        number /= 10;
    }
    return result;
}

int delete_signe(char **nb1, char **nb2)
{
    if (**nb1 == '-' || (**nb1 == '0' && my_strlen(*nb1) > 1)) {
        *nb1 += 1;
        delete_signe(nb1, nb2);
    }
    if (**nb2 == '-' || (**nb2 == '0' && my_strlen(*nb2) > 1)) {
        *nb2 += 1;
        delete_signe(nb1, nb2);
    }
    return 0;
}

char *add_signe(char *nb, char signe)
{
    char *temp = malloc(sizeof(char) * (my_strlen(nb) + 2));

    temp[0] = signe;
    my_strcat(temp, nb);
    nb = temp;
}