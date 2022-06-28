/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task10 - MY_STRCAPITALIZE
*/

int my_strlen(char const *str);

char my_charlowcase(char ch)
{
    if (ch > 64 && ch < 89)
        ch = ch + 32;
    return ch;
}

int check_sep_nb(char ch)
{
    int check_sep = ch == ' ' || ch == '-' || ch == '+' ? 1 : 0;
    int check_nb = ch >= 48 && ch <= 57 ? 1 : 0;

    if (check_sep == 1)
        return 1;
    else if (check_nb == 1)
        return 2;
    else
        return 0;
}

char *my_strcapitalize(char *str)
{
    if (*str == '\0')
        return str;
    *str = my_charlowcase(*str);
    if (*(str - 1) == '\0' && check_sep_nb(*(str)) == 0)
        *(str) = *str - 32;
    else if (check_sep_nb(*(str - 1)) == 1 && check_sep_nb(*(str)) == 0)
        *(str) = *str - 32;
    my_strcapitalize(str + 1);
    return str;
}