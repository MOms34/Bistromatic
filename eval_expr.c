/*
** EPITECH PROJECT, 2021
** Evalexpr
** File description:
** Main
*/

#include <stdbool.h>
#include "./include/my.h"
#include <stdlib.h>

char *parse_expressions(char **str, char *number);
char *infin_add(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
char *infin_mul(char *nb1, char *nb2);
char *infin_div(char *nb1, char *nb2);
char *infin_mod(char *nb1, char *nb2);
char *itoa(int number);
int my_intlen(int number);
bool is_digits(char ch);

char *parse_digits(char **str, char *number)
{
    char *res = malloc(sizeof(char) * (my_strlen(*str) + 1));
    int i = 0;

    while (is_digits(**str)) {
        res[i] = **str;
        *str += 1;
        i++;
    }
    res[i] = '\0';
    return res;
}

char *parse_factor(char **str, char *number)
{
    if (**str == '(') {
        *str += 1;
        if (*(*str - 2) == '-')
            number = parse_expressions(str, number);
        else
            number = parse_expressions(str, number);
        *str += 1;
    } else
        number = parse_digits(str, number);
    return number;
}

char *parse_term(char **str, char *number)
{
    number = parse_factor(str, number);
    while (true) {
        if (**str == '*') {
            *str += 1;
            number = infin_mul(number, parse_factor(str, number));
        } else if (**str == '/') {
            *str += 1;
            number = infin_div(number, parse_factor(str, number));
        } if (**str == '%') {
            *str += 1;
            number = infin_mod(number, parse_factor(str, number));
        } else
            break;
    }
    return number;
}

char *parse_expressions(char **str, char *number)
{
    number = parse_term(str, number);
    if (number[0] == 'E')
        return "E";
    while (true) {
        if (**str == '+') {
            *str += 1;
            number = infin_add(number, parse_term(str, number));
        } else if (**str == '-') {
            *str += 1;
            number = infin_sub(number, parse_term(str, number));
            (number[0] == '-' && my_strlen(number) == 1) ? number = "\0" : 0;
        } else
            break;
    }
    return number;
}