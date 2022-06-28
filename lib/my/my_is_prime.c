/*
** EPITECH PROJECT, 2021
** Day05
** File description:
** Task06 - MY_IS_PRIME
*/

int make_square(int nb)
{
    int num;

    if (nb < 0)
        return 0;
    for (int i = 0; i < 46341; i++) {
        num = i * i;
        if (nb == num)
            return i;
        else if (nb < num)
            return i;
    }
    return 0;
}

int my_is_prime(int num)
{
    int k;

    if (num == 2)
        return 1;
    else if (num < 2 || num % 2 == 0)
        return 0;
    for (k = make_square(num); k > 1; k--) {
        if (num % k == 0)
            return 0;
    }
    return 1;
}
