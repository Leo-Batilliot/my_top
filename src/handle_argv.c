/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** handle_argv
*/
#include "my.h"

int is_number(char *str, int s)
{
    int coma = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] > '9' || str[i] < '0') && str[i] != '.')
            exit(84);
        if (str[i] == '.' && s == 1)
            coma++;
        if (str[i] == '.' && s == 0)
            exit(84);
        if (coma > 1)
            exit(84);
    }
    return 0;
}

void handle_argv(linkedlist_t *list, int ac, char **av)
{
    if (ac == 1)
        return;
    if (ac % 2 == 0)
        exit(84);
    for (int i = 1; i < ac; i += 2) {
        if (strcmp(av[i], "-U") == 0)
            list->username = av[i + 1];
        if (strcmp(av[i], "-d") == 0 && is_number(av[i + 1], 1) == 0)
            list->interval = atof(av[i + 1]);
        if (strcmp(av[i], "-n") == 0 && is_number(av[i + 1], 0) == 0)
            list->iterations = atoi(av[i + 1]);
        if (strcmp(av[i], "-U") != 0 && strcmp(av[i], "-n") != 0 &&
            strcmp(av[i], "-d") != 0)
            exit(84);
    }
    return;
}
