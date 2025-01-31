/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-mytop-leo.batilliot
** File description:
** user
*/
#include "../my.h"

void get_name(node_t *node, char *name)
{
    int i = 0;

    strncpy(node->user, name, sizeof(node->user) - 1);
    for (; node->user[i] != '\0'; i++) {
        if (i > 6) {
            node->user[i] = '+';
            break;
        }
    }
    node->user[i + 1] = '\0';
}

void get_user_info(node_t *node)
{
    char filepath[256];
    FILE *file;
    char buffer[256];
    int uid;
    struct passwd *pw;

    snprintf(filepath, sizeof(filepath), "/proc/%s/status", node->pid);
    file = fopen(filepath, "r");
    if (!file)
        return;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "Uid:", 4) != 0)
            continue;
        sscanf(buffer, "Uid: %d", &uid);
        pw = getpwuid(uid);
        if (pw)
            get_name(node, pw->pw_name);
        break;
    }
    fclose(file);
}
