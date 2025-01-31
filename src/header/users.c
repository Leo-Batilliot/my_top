/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** header_users
*/

#include "../my.h"

int get_users(void)
{
    struct utmp entry;
    int user_count = 0;
    int fd = open("/var/run/utmp", O_RDONLY);

    if (fd == -1)
        return 0;
    while (read(fd, &entry, sizeof(entry)) == sizeof(entry))
        if (entry.ut_type == USER_PROCESS)
            user_count++;
    close(fd);
    return user_count;
}

void print_logged_in_users(void)
{
    int x = get_users();

    printw("%i users, ", x);
}
