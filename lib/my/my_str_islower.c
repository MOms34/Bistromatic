/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task14 - MY_STR_ISLOWER
*/

int my_str_islower(char const *str)
{
    if (*str == '\0')
        return 1;
    if (!(*str >= 97 && *str <= 122))
        return 0;
    my_str_islower(str + 1);
}