/*
** EPITECH PROJECT, 2021
** Day07
** File description:
** Task04 - MY_STR_TO_WORD_ARRAY
*/

#include <stdlib.h>

int is_alpha(char ch);
int my_show_word_array(char * const *tab);

int count_spacers(char const *str)
{
    int i = 0;
    int compteur = 0;

    while (str[i] != '\0') {
        if (is_alpha(str[i]) == 0 && is_alpha(str[i + 1]) == 1) {
            compteur++;
        }
        i++;
    }
    return compteur + 1;
}

int *count_letter_words(char const *str, int n)
{
    int i = 0;
    int k = 0;
    int compteur = 0;
    int *tab_compteur = malloc(sizeof(int) * n);

    while (str[i] != '\0') {
        if (is_alpha(str[i]) != 0)
            compteur++;
        else if (compteur != 0) {
            tab_compteur[k] = compteur;
            k++;
            compteur = 0;
        }
        i++;
    }
    tab_compteur[k] = compteur;
    return tab_compteur;
}

int check_exception(int j, char *intermediary_tab, char const *str, int i)
{
    if (is_alpha(str[i]) == 1) {
        intermediary_tab[j] = str[i];
        j++;
    }
    return j;
}

char **make_comp(char **final_tab,int *tab_size_words, int l, char const *str)
{
    int k = 0;
    int j = 0;
    char *intermediary_tab = malloc(sizeof(char) * (tab_size_words[0] + 1));

    for (int i = l; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && is_alpha(str[i + 1]) == 1) {
            intermediary_tab[j] = '\0';
            final_tab[k] = intermediary_tab;
            k++;
            intermediary_tab = malloc(sizeof(char) * (tab_size_words[k] + 1));
            j = 0;
        } else
            j = check_exception(j, intermediary_tab, str, i);
    }
    intermediary_tab[j] = '\0';
    final_tab[k] = intermediary_tab;
    final_tab[k + 1] = NULL;
    return final_tab;
}

char **my_str_to_word_array(char const *str)
{
    char **final_tab;
    int nb_spacers = count_spacers(str);
    int *tab_size_words = count_letter_words(str, nb_spacers);
    int l = 0;

    final_tab = malloc(sizeof(char *) * (nb_spacers + 1));
    while (is_alpha(str[l]) == 0){
        l++;
    }
    final_tab = make_comp(final_tab, tab_size_words, l, str);
    return final_tab;
}
