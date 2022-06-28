/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task12 - MY_STR_ISALPHA
*/

int my_str_isalpha(char const *str)
{
    if (*str == '\0')
        return 1;
    if (!((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122)))
        return 0;
    my_str_isalpha(str + 1);
}