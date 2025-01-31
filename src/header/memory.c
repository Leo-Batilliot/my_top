/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** memory
*/

#include "../my.h"

void get_memory_info(FILE *file, char label[32], double *mem,
    unsigned long value)
{
    while (fscanf(file, "%31s %lu kB", label, &value) == 2) {
        if (strcmp(label, "MemTotal:") == 0)
            mem[0] = value;
        if (strcmp(label, "MemFree:") == 0)
            mem[1] = value;
        if (strcmp(label, "Buffers:") == 0)
            mem[2] = value;
        if (strcmp(label, "SReclaimable:") == 0)
            mem[7] = value;
        if (strcmp(label, "Cached:") == 0)
            mem[3] = value;
        if (strcmp(label, "SwapTotal:") == 0)
            mem[4] = value;
        if (strcmp(label, "SwapFree:") == 0)
            mem[5] = value;
        if (strcmp(label, "MemAvailable:") == 0)
            mem[6] = value;
    }
}

double mem_unit(double mem, linkedlist_t *list, char option)
{
    if (option == 'S')
        return (mem / powf(1024.0, list->s_u_i));
    if (option == 'P')
        return (mem / powf(1024.0, list->p_u_i + 1));
    return 0;
}

void print_memory_info(linkedlist_t *list)
{
    FILE *file = fopen("/proc/meminfo", "r");
    char label[32];
    double *mem = malloc(sizeof(double) * 8);
    unsigned long value = 0;

    if (!file || !mem)
        return;
    get_memory_info(file, label, mem, value);
    for (int i = 0; i < 8; i++)
        mem[i] = mem_unit(mem[i], list, 'S');
    fclose(file);
    printw("%ciB Mem : %8.1f total, %8.1f free, %8.1f used, %8.1f buff/cache",
        list->s_u_c[list->s_u_i], mem[0], mem[1], (mem[0] - mem[6]),
            (mem[2] + mem[3] + mem[7]));
    printw("\n%ciB Swap: %8.1f total, %8.1f free, %8.1f used. %8.1f avail Mem",
        list->s_u_c[list->s_u_i], mem[4], mem[5], (mem[4] - mem[5]), mem[6]);
    printw("\n");
    free(mem);
}
