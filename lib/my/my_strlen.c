/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task03 - MY _STRLEN
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
