/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./include/my.h"
#include "./bistromatic.h"
#include "./errors.h"

char *parse_expressions(char **str, char *number);
char *checker_syntax(char *base, char *str, char *operators);
int charset_checker(char *buff, char *base, char *operators);

void print_result(char *result, char **argv) // norme ok
{
    for (int x = 0; x < my_strlen(result); x++) {
        (result[x] == '-') ? my_putchar(result[x]) : 0;
        (result[x] != '-') ? my_putchar(argv[1][result[x] - 48]) : 0;
    }
}

int check_all_errors(char *buff, int argc, char **argv) // norme ok
{
    if (argc != 4)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (check_digits_base(argc, argv) == 84)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (check_parenthesis(buff) == 84)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (check_operators_base(argv[1], argv[2]) == 84)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (check_operators_expr(buff) == 84)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (my_strlen(argv[2]) != 7)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    if (charset_checker(buff, argv[2], argv[1]) == 84)
        return print_error_message(84, SYNTAX_ERROR_MSG);
    return 0;
}

int main(int argc, char **argv) // norme OK
{
    char *buff = malloc(sizeof(char) * (40000 + 1));
    int offset = 0;
    int len;
    char *number = malloc(sizeof(char) * (my_strlen(buff) + 1));
    char *result = malloc(sizeof(char) * (40000 + 1));

    while ((len = read(0 , buff + offset , 40000 - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (len < 0)
        return 84;
    buff = checker_syntax(argv[1], buff, argv[2]);
    if (check_all_errors(buff, argc, argv) == 84)
        return 84;
    result = parse_expressions(&buff, number);
    if (result[0] == 'E')
        return print_error_message(84, SYNTAX_ERROR_MSG);
    print_result(result, argv);
    return 0;
}
