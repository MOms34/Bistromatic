/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task20
*/

int my_strlen(char const *str);
void my_putchar(char ch);
int my_putnbr_base(int number, char const *base);

int my_char_isprintable(char const ch)
{
    if (!(ch >= 32 && ch <= 126))
        return 0;
    return 1;
}

void print_zero(char ch)
{
    if (ch >= 15)
        my_putchar('1');
    else
        my_putchar('0');
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isprintable(str[i]) == 0) {
            my_putchar(92);
            print_zero(str[i]);
            my_putnbr_base((int) str[i], "0123456789abcdef");
        } else
            my_putchar(str[i]);
        i++;
    }
    return 0;
}