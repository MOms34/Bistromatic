/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** Task07 - MY_PUTNBR_BASE
*/

void my_putchar(char ch);
void my_putstr(char const *str);
int my_strlen(char const *str);

int my_putnbr_base(int number, char const *base)
{
    if (number == -2147483648)
        my_putstr("-2147483648");
    if (number == 0) {
        my_putchar('0');
        return 0;
    } else if (number < 0) {
        my_putchar('-');
        number = number * -1;
    }
    if (number > 0 && number <= my_strlen(base))
        my_putchar(base[number]);
    else {
        my_putnbr_base(number / my_strlen(base), base);
        my_putchar(base[number % my_strlen(base)]);
    }
    return 0;
}
