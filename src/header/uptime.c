/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** uptime
*/
#include "../my.h"

void print_time_format(int days, int hours, int mins)
{
    printw("up ");
    if (days > 1)
        printw("%d days, ", days);
    if (days == 1)
        printw("%d day, ", days);
    if (hours == 0 && mins > 0)
        printw("%i min, ", mins);
    if (hours > 0)
        printw("%i:%02i, ", hours, mins);
}

void print_uptime(void)
{
    double uptime;
    int days;
    int hours;
    int minutes;
    FILE *file = fopen("/proc/uptime", "r");

    if (!file) {
        perror("fopen");
        return;
    }
    fscanf(file, "%lf", &uptime);
    fclose(file);
    days = (int)(uptime / 86400);
    hours = ((int)uptime % 86400) / 3600;
    minutes = ((int)uptime % 3600) / 60;
    print_time_format(days, hours, minutes);
}
