/*
** EPITECH PROJECT, 2021
** Day07
** File description:
** Task02 - MY_STRCAT
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int start_len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[start_len + i] = src[i];
        i++;
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}
