/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task05 - MY_STRSTR
*/

int my_strlen(char const *str);

int make_loop(char *str, char const *to_find, int *ptr_i)
{
    int k = *ptr_i;
    int j = 0;

    while (str[k] == to_find[j]) {
        if (my_strlen(to_find) - 1 == j) {
            return 1;
        }
        k++;
        j++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int *ptr_i = &i;
    int condition;
    char *first_char;

    if (to_find[0] == '\0')
        return str;
    while (i < my_strlen(str)) {
        if (to_find[0] == str[i])
            condition = make_loop(str, to_find, ptr_i);
        first_char = str + i;
        if (condition != 0)
            return first_char;
        i++;
    }
    return '\0';
}