/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** stat_file
*/
#include "../my.h"

void name_format(node_t *node)
{
    size_t len;

    if (!node)
        return;
    len = strlen(node->name);
    if (len > 1 && node->name[0] == '(' && node->name[len - 1] == ')') {
        for (size_t i = 1; i < len - 1; i++) {
            node->name[i - 1] = node->name[i];
        }
        node->name[len - 2] = '\0';
    }
}

void get_relevant_stats(linkedlist_t *list, node_t *node, char **stats)
{
    strncpy(node->name, stats[1], sizeof(node->name) - 1);
    name_format(node);
    node->state = stats[2][0];
    node->pr = atol(stats[17]);
    node->ni = atol(stats[18]);
    node->virt = mem_unit(atol(stats[22]), list, 'P');
    node->res = mem_unit(atol(stats[23]), list, 'P') * sysconf(_SC_PAGE_SIZE);
    node->time = atol(stats[14]);
}

void read_stats(linkedlist_t *list, node_t *node)
{
    char filepath[256];
    FILE *file;
    char buffer[1024];
    size_t bytes;

    snprintf(filepath, sizeof(filepath), "/proc/%s/stat", node->pid);
    file = fopen(filepath, "r");
    if (!file)
        return;
    bytes = fread(buffer, 1, sizeof(buffer) - 1, file);
    fclose(file);
    if (bytes <= 0)
        return;
    buffer[bytes] = '\0';
    get_relevant_stats(list, node, my_str_to_word_array(buffer));
}
