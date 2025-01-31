/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** processes_main
*/
#include "../my.h"

void get_node_content(node_t *node, linkedlist_t *list)
{
    get_user_info(node);
    read_stats(list, node);
    read_statm(list, node);
    insert_at_beginning(list, node);
}

int read_process_stat(const char *pid, int pidnb, linkedlist_t *list)
{
    char filepath[256];
    FILE *file;
    char buffer[1024];
    node_t *node = create_node(pidnb);

    snprintf(filepath, sizeof(filepath), "/proc/%s/stat", pid);
    file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open stat file");
        return -1;
    }
    if (!fgets(buffer, sizeof(buffer), file)) {
        fclose(file);
        perror("Failed to read stat file");
        return -1;
    }
    node->pid = strdup(pid);
    fclose(file);
    get_node_content(node, list);
    return 0;
}

int files_main(linkedlist_t *list)
{
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (!proc_dir) {
        perror("Failed to open /proc");
        return EXIT_FAILURE;
    }
    entry = readdir(proc_dir);
    while (entry != NULL) {
        if (isdigit(entry->d_name[0])) {
            read_process_stat(entry->d_name, atoi(entry->d_name), list);
        }
        entry = readdir(proc_dir);
    }
    closedir(proc_dir);
    print_list(list);
    return 0;
}
