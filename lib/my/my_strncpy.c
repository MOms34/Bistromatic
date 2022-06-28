/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task02 - MY_STRNCPY
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}
