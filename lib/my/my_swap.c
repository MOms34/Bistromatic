/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task01 - MY_SWAP
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}