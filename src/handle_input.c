/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** handle_input
*/
#include "my.h"

void get_previous_pid(linkedlist_t *list)
{
    node_t *current = list->head;
    node_t *previous = NULL;

    if (!list->head || current == NULL)
        return;
    while (current != NULL) {
        if (current->pidnb < list->pid) {
            previous = current;
        } else
            break;
        current = current->next;
    }
    if (previous != NULL)
        list->pid = previous->pidnb;
}

void get_next_pid(linkedlist_t *list)
{
    node_t *current = list->head;

    if (!list->head || current == NULL)
        return;
    while (current->next != NULL && current->pidnb <= list->pid) {
        current = current->next;
    }
    if (current->pidnb > list->pid)
        list->pid = current->pidnb;
}

void cycle_unit(linkedlist_t *list, char option)
{
    if (option == 'P') {
        list->p_u_i = (list->p_u_i + 1) % 5;
    }
    if (option == 'S') {
        list->s_u_i = (list->s_u_i + 1) % 6;
    }
}

int handle_input(linkedlist_t *list, int ch)
{
    node_t *tokill;

    if (ch == 'q' || ch == 'Q')
        return -1;
    if (ch == KEY_UP)
        get_previous_pid(list);
    if (ch == KEY_DOWN)
        get_next_pid(list);
    if (ch == 'k') {
        tokill = go_to_list_pid(list);
        kill(tokill->pidnb, SIGTERM);
        return 0;
    }
    if (ch == 'e')
        cycle_unit(list, 'P');
    if (ch == 'E')
        cycle_unit(list, 'S');
    return 0;
}
