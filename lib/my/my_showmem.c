/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task21 - MY_SHOWMEM
*/

int my_strlen(char const *str);
void my_putchar(char ch);
int my_getnbr(char *str);
int my_put_nbr(int number);
void my_putstr(char const *str);
int my_putnbr_base(int number, char const *base);

int is_printable(char const ch)
{
    if (!(ch >= 32 && ch <= 126)) {
        return 0;
    }
    return 1;
}

int my_print_ascii(char const *str, int size, int start)
{
    int i = start;
    int j = 0;

    while (i < size) {
        if (is_printable(str[i]) == 1)
            my_putchar(str[i]);
        else
            my_putchar('.');
        if (j == 16) {
            my_putchar('\n');
            j = 0;
            return 0;
        }
        j++;
        i++;
    }
}

int my_print_hexa(char const *str, int size, int start)
{
    int i = start;
    int j = 0;
    int k = 1;

    while (i < size) {
        my_putnbr_base((int) str[i], "0123456789abcdef");
        if (k == 2) {
            my_putchar(' ');
            k = 0;
        }
        if (j == 15) {
            my_putchar(' ');
            my_print_ascii(str, size, start);
            j = 0;
            return 0;
        }
        j++;
        i++;
        k++;
    }
}

int calculate_0(int n)
{
    int compteur = 0;

    if (n == 0)
        return 1;

    while (n != 0) {
        compteur++;
        n = n / 10;
    }
    return compteur;
}

int my_showmem(char const *str, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n = 0;

    while (i < (size / 16)) {
        n = 8 - calculate_0(k);
        while (n != 0) {
            my_putchar('0');
            n--;
        }
        my_put_nbr(k);
        my_putchar(':');
        my_putchar(' ');
        my_print_hexa(str, size, j);
        j += 16;
        k += 10;
        i++;
    }
}