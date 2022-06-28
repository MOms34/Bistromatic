/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Handle Errors
*/

#include "./include/my.h"
#include "./errors.h"
#include <stdbool.h>
#include <stdio.h>

bool is_operator(char ch);

int check_digits_base(int argc, char **argv)
{
    char *base_digits = argv[1];
    int i;
    int j;

    for (i = 0; i < my_strlen(base_digits); i++) {
        for (j = i + 1; j < my_strlen(base_digits); j++) {
            if (base_digits[i] == base_digits[j])
                return 84;
        }
    }
    return 0;
}

int check_parenthesis(char *buff)
{
    int k;
    int tmp1 = 0;
    int tmp2 = 0;

    for (k = 0; k < my_strlen(buff); k++) {
        if (buff[k] == '(')
            tmp1++;
        if (buff[k] == ')')
            tmp2++;
    }
    if (tmp1 != tmp2)
        return 84;
    return 0;
}

int check_operators_base(char *base, char *operator)
{
    int i;
    int j;

     for (i = 0; i < my_strlen(operator); i++) {
        for (j = 0; j < my_strlen(base); j++) {
            if (operator[i] == base[j])
                return 84;
        }
    }
    return 0;
}

int check_operators_expr(char *buff)
{
    int cond;
    int cond2;

    for (int i = 0; i < my_strlen(buff); i++) {
        cond = (buff[i + 1] == '*' || buff[i + 1] == '/') ? 1 : 0;
        cond2 = (buff[i] == '(' && is_factors(buff[i + 1])) ? 1 : 0;
        if (is_digits(buff[i]) && buff[i + 1] == '(' || (cond2 == 1))
            return 84;
        if (buff[1] == '\0')
            return 84;
        if ((buff[i] == '-' || buff[i] == '+') && (cond == 1))
            return 84;
    }
}

int charset_checker(char *buff, char *base, char *operators)
{
    int i = 0;
    int cnd;
    int x = 0;

    for (int i = 0; i < my_strlen(buff); i++) {
        cnd = (buff[i] == '(' || buff[i] == ')' || buff[i] == '\n') ? 1 : 0;
        if (is_digits(buff[i]) == 1 || is_operator(buff[i]) == 1 || cnd == 1) {
            x++;
        } else {
            return 84;
        }
    }
    return 0;
}