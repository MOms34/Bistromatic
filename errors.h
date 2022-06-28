/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** File Header
*/
#include <stdbool.h>

#ifndef ERRORS
    #define ERRORS

bool is_operator(char ch);
bool is_factors(char ch);
bool is_digits(char ch);
int my_putstr_error(char const *str);
int print_error_message(int error, char *msg);
int check_digits_base(int argc, char **argv);
int check_parenthesis(char *buff);
int check_operators_base(char *base, char *operator);
int check_operators_expr(char *buff);

#endif