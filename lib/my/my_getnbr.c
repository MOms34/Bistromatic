/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task05 - MY_GETNBR
*/

int get_calculations(char const *str, int i, int *ptr, int number)
{
    if (str[i] >= 48 && str[i] <= 57) {
        number = (number * 10) + (str[i] - 48);
        return number;
    } else if (str[i] == '-') {
        *ptr += 1;
        return number;
    } if (str[i] != '+')
        return number;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int number = 0;
    int operator_logic = 0;

    while (str[i] != '\0') {
        number = get_calculations(str, i, &operator_logic, number);
        if (number > 2147483647 || number + 1 < -2147483647)
            return 0;
        i++;
    }
    if (operator_logic != 0 && operator_logic % 2 == 1)
        return number * -1;
    else
        return number;
}