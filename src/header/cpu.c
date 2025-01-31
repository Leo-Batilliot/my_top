/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** cpu
*/

#include "../my.h"

void calculate_cpu_usage(unsigned long prev[8], unsigned long curr[8])
{
    unsigned long diff[8];
    unsigned long total_diff = 0;

    for (int i = 0; i < 8; i++) {
        diff[i] = curr[i] - prev[i];
        total_diff += diff[i];
    }
    printw("%%Cpu(s): %5.1f us, %5.1f sy, %5.1f ni, %5.1f id, ",
        (diff[0] * 100.0) / total_diff,
        (diff[2] * 100.0) / total_diff,
        (diff[1] * 100.0) / total_diff,
        (diff[3] * 100.0) / total_diff);
    printw("%5.1f wa, %5.1f hi, %5.1f si, %5.1f st\n",
        (diff[4] * 100.0) / total_diff,
        (diff[5] * 100.0) / total_diff,
        (diff[6] * 100.0) / total_diff,
        (diff[7] * 100.0) / total_diff);
}

void read_cpu_data(unsigned long data[8])
{
    FILE *file = fopen("/proc/stat", "r");
    char buffer[256];

    if (!file) {
        perror("fopen");
        memset(data, 0, sizeof(unsigned long) * 8);
        return;
    }
    if (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
            &data[0], &data[1], &data[2], &data[3],
            &data[4], &data[5], &data[6], &data[7]);
    }
    fclose(file);
}

void print_cpu_usage(void)
{
    static unsigned long prev[8] = {0};
    unsigned long curr[8];

    read_cpu_data(curr);
    calculate_cpu_usage(prev, curr);
    memcpy(prev, curr, sizeof(unsigned long) * 8);
}
