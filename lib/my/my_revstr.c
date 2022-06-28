/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task03 - MY_REVSTR
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int end = my_strlen(str) - 1;
    char temp;

    while (i < end) {
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
        i++;
        end--;
    }
    str[my_strlen(str)] = '\0';
    return str;
}
