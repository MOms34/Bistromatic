/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task12 - MY_STR_ISNUM
*/

int my_str_isnum(char const *str)
{
    if (*str == '\0')
        return 1;
    if (!(*str >= 48 && *str <= 57))
        return 0;
    my_str_isnum(str + 1);
}