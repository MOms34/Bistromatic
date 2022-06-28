/*
** EPITECH PROJECT, 2021
** Day01
** File description:
** Task04 - MY_ISNEG
*/

void my_putchar(char ch);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return 0;
}
