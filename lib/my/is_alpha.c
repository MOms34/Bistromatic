/*
** EPITECH PROJECT, 2021
** Utilities
** File description:
** My Is_Alpha
*/

int is_alpha(char ch)
{
    int cond_nb = ch >= '0' && ch <= '9' ? 1 : 0;

    if (!(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || cond_nb == 1))
        return 0;
    return 1;
}