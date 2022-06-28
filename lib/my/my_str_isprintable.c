/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task16 - MY_STR_ISUPRINTABLE
*/

int my_str_isprintable(char const *str)
{
    if (*str == '\0')
        return 1;
    if (!(*str >= 32 && *str <= 126))
        return 0;
    my_str_isprintable(str + 1);
}