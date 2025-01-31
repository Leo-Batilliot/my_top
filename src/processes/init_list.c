/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** init_list
*/
#include "../my.h"

node_t *create_node(int pid)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        exit(EXIT_FAILURE);
    new_node->next = NULL;
    new_node->pidnb = pid;
    return new_node;
}

void insert_at_beginning(linkedlist_t *list, node_t *node)
{
    node->next = list->head;
    list->head = node;
}

linkedlist_t *create_list(void)
{
    linkedlist_t *list = malloc(sizeof(linkedlist_t));

    if (!list)
        exit(EXIT_FAILURE);
    list->s_u_c = "KMGTPE";
    list->s_u_i = 1;
    list->p_u_c = "kmgtp";
    list->p_u_i = 0;
    list->pid = 1;
    list->iterations = -1;
    list->interval = 3;
    list->username = NULL;
    list->head = NULL;
    return list;
}

void free_list(linkedlist_t *list)
{
    node_t *temp;
    node_t *current = list->head;

    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    free(list);
}
