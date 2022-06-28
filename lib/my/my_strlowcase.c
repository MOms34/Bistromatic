/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task09 - MY_STRLOWCASE
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int k = 0;

    while (k < my_strlen(str)) {
        if (str[k] > 64 && str[k] < 89)
            str[k] = str[k] + 32;
        k++;
    }
    return str;
}
