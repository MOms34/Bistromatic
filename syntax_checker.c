/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** ---
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_getnbr_base(char *str, char *base);
char *parse_expressions(char **str, char *number);
int is_digits(char ch);
int get_negative_factor(char *str, int nb_less, int *i);

char *remove_starting_ops(char *str, int nb_less, char *no_ops_str)
{
    int i = 0;
    int k = 0;

    if (nb_less % 2 == 1) {
        no_ops_str[k] = '-';
        k++;
    }
    while (str[i] == '-' || str[i] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        no_ops_str[k] = str[i];
        k++;
        i++;
    }
    no_ops_str[k] = '\0';
    return no_ops_str;
}

void ops_subst(char input, char operators, char *c, int *j)
{
    if (input == operators) {
        if (*j == 0)
            *c = '(';
        if (*j == 1)
            *c = ')';
        if (*j == 2)
            *c = '+';
        if (*j == 3)
            *c = '-';
        if (*j == 4)
            *c = '*';
        if (*j == 5)
            *c = '/';
        if (*j == 6)
            *c = '%';
    }
    (*j)++;
}

char *convert_input(char *input, char *base, char *operators)
{
    int x = 0;
    char *no_ops_str = malloc(my_strlen(input) + 1);
    int nb_less = get_negative_factor(input, 0, &x);
    char *final_string = malloc(sizeof(char) * my_strlen(input) + 1);
    remove_starting_ops(input, nb_less, no_ops_str);
    int i;
    int j = 0;
    char c;

    for (i = 0; i < my_strlen(no_ops_str); i++) {
        c = no_ops_str[i];
        while (j < my_strlen(operators)) {
            ops_subst(no_ops_str[i], operators[j], &c, &j);
        }
        j = 0;
        final_string[i] = c;
    }
    final_string[i] = '\0';
    return final_string;
}

int get_negative_factor(char *str, int nb_less, int *i)
{
    while (*str == '-' || *str == '+') {
        if (*str == '-')
            nb_less++;
        str += 1;
        (*i)++;
    }
    return nb_less;
}

char *checker_syntax(char *base, char *str, char *operators)
{
    char *final = malloc(my_strlen(str) + 1);
    char *tmp = malloc(my_strlen(str) + 1);
    tmp = convert_input(convert_input(str, base, operators), base, operators);
    tmp[my_strlen(str) - 1] = '\0';
    int z = 0;
    int u = 0;
    char *number;
    char *result = malloc(sizeof(char) * 1000);

    for (int i = 0; i < my_strlen(tmp); i++) {
        for (int k = 0; k < my_strlen(base); k++) {
            (tmp[i] == base[k]) ? u += 1, final[z++] = k + 48 : 0;
        }
        (u != 1) ? final[z++] = tmp[i] : 0;
        u = 0;
    }
    final[z] = '\0';

    char *final2 = malloc(my_strlen(final));
    int k = 0;
    int nb_less = 0;
    int indic = 0;
    int i = 0;

    while (*final != '\0') {
        if (*final == '-' || *final == '+' && (*(final + 1) == '+' ||
                                                    *(final + 1) == '-')) {
            nb_less = get_negative_factor(final, 0, &i);
            final2[k] = (nb_less % 2 == 1) ? '-' : '+';
            indic++;
            final += i;
            i = 0;
            k++;
        } else if (*final == '*' && (*(final + 1) == '+' ||
                                        *(final + 1) == '-')) {
            nb_less = get_negative_factor(++final, 0, &i);
            final2[k++] = '*';
            final2[k++] = '(';
            indic++;
            final2[k] = (nb_less % 2 == 1) ? '-' : '+';
            final += i;
            indic += my_strlen(final);
            i = 0;
            k++;
        } else if (*final == '%' && (*(final + 1) == '+' ||
                                        *(final + 1) == '-')) {
            nb_less = get_negative_factor(++final, 0, &i);
            final2[k++] = '%';
            final2[k++] = '(';
            indic++;
            final2[k] = (nb_less % 2 == 1) ? '-' : '+';
            final += i;
            indic += my_strlen(final);
            i = 0;
            k++;
        } else if (*final == '/' && (*(final + 1) == '+' ||
                                        *(final + 1) == '-')) {
            nb_less = get_negative_factor(++final, 0, &i);
            final2[k++] = '/';
            final2[k++] = '(';
            indic++;
            final2[k] = (nb_less % 2 == 1) ? '-' : '+';
            final += i;
            indic += my_strlen(final);
            i = 0;
            k++;
        }  else {
            final2[k++] = *final;
            (indic > 0) ? indic -= 1 : 0;
            (indic == 1) ? final2[k++] = ')', indic = 0 : 0;
            final += 1;
        }
    }
    final2[k] = '\0';
    return final2;
}