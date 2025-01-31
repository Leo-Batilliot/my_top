/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** main
*/
#include "my.h"

void top(linkedlist_t *list)
{
    clear();
    print_local_time();
    print_uptime();
    print_logged_in_users();
    print_load_avg();
    print_tasks_info();
    print_cpu_usage();
    print_memory_info(list);
    files_main(list);
    refresh();
}

int main(int ac, char **av)
{
    int ch = 0;
    linkedlist_t *list = create_list();

    handle_argv(list, ac, av);
    initscr();
    noecho();
    curs_set(0);
    timeout(list->interval * 1000);
    keypad(stdscr, TRUE);
    for (int i = 0; list->iterations == - 1 || i < list->iterations; i++) {
        refresh_list(list);
        top(list);
        ch = getch();
        if (handle_input(list, ch) == -1)
            break;
    }
    free_list(list);
    endwin();
    return EXIT_SUCCESS;
}
