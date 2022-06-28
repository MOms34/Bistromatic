/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task08 - MY_STRUPCASE
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int k = 0;

    while (k < my_strlen(str)) {
        if (str[k] > 96 && str[k] < 121)
            str[k] = str[k] - 32;
        k++;
    }
    return str;
}
