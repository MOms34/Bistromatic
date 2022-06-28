/*
** EPITECH PROJECT, 2021
** Day01
** File description:
** MY_PUTCHAR
*/

#include <unistd.h>

void my_putchar(char ch)
{
    write(1, &ch, 1);
}