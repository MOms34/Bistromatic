/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task15 - MY_STR_ISUPPER
*/

int my_str_isupper(char const *str)
{
    if (*str == '\0')
        return 1;
    if (!(*str >= 65 && *str <= 90))
        return 0;
    my_str_isupper(str + 1);
}