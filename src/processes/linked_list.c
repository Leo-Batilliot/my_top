/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** linked_list
*/
#include "../my.h"

node_t *go_to_list_pid(linkedlist_t *list)
{
    node_t *current = list->head;

    if (current == NULL)
        return NULL;
    while (current != NULL && current->pidnb < list->pid)
        current = current->next;
    return current;
}

node_t *reverse_list(node_t *head)
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

static void print_mem(long int data, linkedlist_t *list)
{
    if (list->p_u_i == 0)
        printw("%12ld", data);
    else
        printw("%11ld%c", data, list->p_u_c[list->p_u_i]);
}

void print_node(node_t *node, linkedlist_t *list)
{
    if (list->username == NULL || strcmp(list->username, node->user) == 0) {
        printw("%7s", node->pid);
        printw("%9s", node->user);
        printw("%5d", node->pr);
        printw("%5d", node->ni);
        print_mem(node->virt, list);
        print_mem(node->res, list);
        print_mem(node->shr, list);
        printw(" %c ", node->state);
        printw("%2ld:%02ld.%02ld ", node->time / 6000,
            (node->time % 6000) / 100, node->time % 100);
        printw("%s", node->name);
        printw("\n");
    }
}

void print_list(linkedlist_t *list)
{
    node_t *current;

    list->head = reverse_list(list->head);
    current = go_to_list_pid(list);
    printw("\n    PID     USER   PR   NI        ");
    printw("VIRT         RES         SHR S  TIME+ COMMAND\n");
    for (int i = 7; i < LINES && current != NULL; i++) {
        print_node(current, list);
        current = current->next;
    }
}

void refresh_list(linkedlist_t *list)
{
    node_t *temp;
    node_t *current;

    if (!list->head)
        list->head = NULL;
    current = list->head;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}
