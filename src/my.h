/*
** EPITECH PROJECT, 2024
** myh
** File description:
** task 02
*/
#ifndef TEST_H
    #define TEST_H
    #include <math.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <utmp.h>
    #include <dirent.h>
    #include <ctype.h>
    #include <time.h>
    #include <pwd.h>
    #include <signal.h>
    #include <stdbool.h>

typedef struct Node {
    int pidnb;
    char *pid;
    char user[256];
    int pr;
    int ni;
    long unsigned int virt;
    long unsigned int res;
    long unsigned int time;
    long unsigned int shr;
    char state;
    double cpu;
    double mem;
    char name[256];
    FILE *file;
    struct Node* next;
} node_t;

typedef struct LinkedList {
    int pid;
    char *username;
    double interval;
    int iterations;
    char *p_u_c;
    int p_u_i;
    char *s_u_c;
    int s_u_i;
    node_t *head;
} linkedlist_t;

node_t *create_node(int);
void read_statm(linkedlist_t *list, node_t *node);
void get_user_info(node_t *node);
void refresh_list(linkedlist_t *list);
void free_list(linkedlist_t *list);
char **my_str_to_word_array(char *str);
void print_list(linkedlist_t *list);
void insert_at_beginning(linkedlist_t *list, node_t *);
void print_logged_in_users(void);
int print_local_time(void);
void print_uptime(void);
void print_load_avg(void);
void print_tasks_info(void);
void print_cpu_usage(void);
int files_main(linkedlist_t *list);
linkedlist_t *create_list(void);
void print_memory_info(linkedlist_t *list);
node_t *go_to_list_pid(linkedlist_t *list);
int handle_input(linkedlist_t *list, int ch);
void read_stats(linkedlist_t *list, node_t *node);
void handle_argv(linkedlist_t *list, int ac, char **av);
double mem_unit(double mem, linkedlist_t *list, char option);

#endif
