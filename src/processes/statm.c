/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** statm
*/
#include "../my.h"
void get_relevant_statm(linkedlist_t *list, node_t *node, char **stats)
{
    node->shr = mem_unit(atol(stats[2]), list, 'P') * sysconf(_SC_PAGE_SIZE);
}

void read_statm(linkedlist_t *list, node_t *node)
{
    char filepath[256];
    FILE *file;
    char buffer[1024];
    size_t bytes;

    snprintf(filepath, sizeof(filepath), "/proc/%s/statm", node->pid);
    file = fopen(filepath, "r");
    if (!file)
        return;
    bytes = fread(buffer, 1, sizeof(buffer) - 1, file);
    fclose(file);
    if (bytes <= 0)
        return;
    buffer[bytes] = '\0';
    get_relevant_statm(list, node, my_str_to_word_array(buffer));
}
