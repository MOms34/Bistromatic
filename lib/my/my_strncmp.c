/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task07 - MY_STRCMP
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (my_strlen(s1) - n == i || my_strlen(s2) - n == i)
            return 0;
        i++;
    }
    if (s1[i] > s2[i])
        return s1[i];
    else
        return -s2[i];
}
