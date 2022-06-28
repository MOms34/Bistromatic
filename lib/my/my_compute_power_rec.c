/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task04 - MY_COMPUTE_POWER_REC
*/

int my_compute_power_rec(int nb, int p)
{
    long int result = nb * p;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (result > 2147483647 || result < -2147483648)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
