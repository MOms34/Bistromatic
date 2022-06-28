/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task07 - MY_FIND_PRIME_SUP
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1) {
        return nb;
    } else {
        return my_find_prime_sup(nb + 1);
    }
}
