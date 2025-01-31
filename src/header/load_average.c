/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** load_average
*/

#include "../my.h"

void print_load_avg(void)
{
    double load1;
    double load5;
    double load15;
    FILE *file = fopen("/proc/loadavg", "r");

    if (!file) {
        perror("fopen");
        return;
    }
    fscanf(file, "%lf %lf %lf", &load1, &load5, &load15);
    fclose(file);
    printw("load average: %.2f, %.2f, %.2f\n", load1, load5, load15);
}
