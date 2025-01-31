/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** header_time
*/
#include "../my.h"

int print_local_time(void)
{
    time_t current_time = time(NULL);
    struct tm *local_time;

    if (current_time == (time_t)(-1)) {
        perror("time");
        return 1;
    }
    local_time = localtime(&current_time);
    if (local_time == NULL) {
        perror("localtime");
        return 1;
    }
    printw("top - %02d:%02d:%02d ",
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec);
    return 0;
}
