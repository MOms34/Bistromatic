/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Handle Errors - Utilities
*/

#include <stdbool.h>
#include "./include/my.h"
#include <stdbool.h>
#include <unistd.h>

int is_operator(char ch)
{
    if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '%')
        return 1;
    else
        return 0;
}

bool is_factors(char ch)
{
    return ch == '*' || ch == '/' || ch == '%';
}

int is_digits(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int my_putstr_error(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return (0);
}

int print_error_message(int error, char *msg)
{
    my_putstr_error(msg);
    return error;
}