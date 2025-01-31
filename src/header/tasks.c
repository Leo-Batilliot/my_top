/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** tasks
*/

#include "../my.h"

void read_file(FILE *file, int *total)
{
    char state;
    int pid;
    char buffer[1024];

    if (!file)
        return;
    if (fgets(buffer, sizeof(buffer), file) != NULL)
        sscanf(buffer, "%d %*s %c", &pid, &state);
    fclose(file);
    if (state == 'R')
        total[1]++;
    if (state == 'T')
        total[3]++;
    if (state == 'Z')
        total[4]++;
    if (state != 'R' && state != 'T' && state != 'Z')
        total[2]++;
    total[0]++;
}

void get_tasks(int *total)
{
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    char path[512];
    FILE *file;

    if (!dir)
        return;
    entry = readdir(dir);
    for (int i = 0; i < 5; i++)
        total[i] = 0;
    while (entry != NULL) {
        if (isdigit(entry->d_name[0])) {
            snprintf(path, 512, "/proc/%s/stat", entry->d_name);
            file = fopen(path, "r");
            read_file(file, total);
        }
        entry = readdir(dir);
    }
    closedir(dir);
}

void print_tasks_info(void)
{
    int *total = malloc(sizeof(int) * 5);

    get_tasks(total);
    printw("Tasks: %i total, %i running, %i sleeping, %i stopped, %i zombie\n",
        total[0], total[1], total[2], total[3], total[4]);
    free(total);
    return;
}
