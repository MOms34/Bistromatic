/*
** EPITECH PROJECT, 2021
** Day03
** File description:
** Task07 - MY_PUT_NBR
*/

void my_putchar(char ch);
void my_putstr(char const *str);

int my_put_nbr(int number)
{
    if (number == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (number == 0) {
        my_putchar('0');
        return 0;
    } else if (number < 0) {
        my_putchar('-');
        number = number * -1;
    }
    if (number > 0 && number <= 9){
        my_putchar(number + 48);
    } else {
        my_put_nbr(number / 10);
        my_putchar(number % 10 + 48);
    }
    return 0;
}