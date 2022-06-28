/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task05 - MY_COMPUTE_SQUARE_ROOT
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0)
        return 0;
    while (i * i != nb) {
        if (i > nb / 2 || nb > 46341) {
            return 0;
        }
        i++;
    }
    return i;
}
