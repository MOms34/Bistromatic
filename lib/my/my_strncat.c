/*
** EPITECH PROJECT, 2021
** Day07
** File description:
** Task03 - MY_STRNCAT
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int start_len = my_strlen(dest);

    while (src[i] != '\0' && i < n) {
        dest[start_len + i] = src[i];
        i++;
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}