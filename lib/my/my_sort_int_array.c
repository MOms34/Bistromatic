/*
** EPITECH PROJECT, 2021
** Day04
** File description:
** Task06 - MY_SORT_IN_ARRAY
*/

void my_put_nbr(int n);
void my_putchar(char ch);
int *make_comparaison(int *array, int *j);

int *make_comparaison(int *array, int *j)
{
    int temp;

    if (array[*j + 1] < array[*j]) {
        temp = array[*j];
        array[*j] = array[*j + 1];
        array[*j + 1] = temp;
    }
    return array;
}

void my_sort_int_array(int *array, int size)
{
    int j;
    int *ptr = &j;

    for (int i = 0; i < size - 1 ; i++) {
        for (j = 0; j < (size - i) - 1 ; j++)
            array = make_comparaison(array, ptr);
    }
}
