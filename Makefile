##
## EPITECH PROJECT, 2024
## makefile
## File description:
## task 01
##

# Files
SRC	=	src/main.c \
		src/handle_input.c \
		src/handle_argv.c \
		src/header/uptime.c \
		src/header/time.c \
		src/header/users.c \
		src/header/tasks.c \
		src/header/cpu.c \
		src/header/memory.c \
		src/header/load_average.c \
		src/processes/processes_main.c \
		src/processes/linked_list.c \
		src/processes/user.c \
		src/processes/init_list.c \
		src/processes/stat_file.c \
		src/processes/statm.c \
		src/lib/my_str_to_word_array.c \

# Colors
RED=\033[31m
GREEN=\033[32m
WHITE=\033[37m
BOLD=\033[1m
RESET=\033[0m

# Variables
OBJ =	$(SRC:.c=.o)
FLAGS = -Wall -Wextra -g
CC = gcc -o
NAME = my_top

# PRINT COMPILATION
%.o: %.c
	@echo "$(GREEN)$(BOLD)[COMPILING]:\t$(RESET)$(GREEN)$<$(RESET)"
	@gcc $(FLAGS) -c $< -o $@

# PRINT AND THEN COMPILE
all: pre-compile $(NAME)

# PRINT INFO
pre-compile:
	@echo "$(WHITE)$(BOLD)\t$(WHITE)[COMPILATION...]$(RESET)"

# COMPILATION
$(NAME): $(OBJ)
	@$(CC) $(NAME) $(OBJ) -lncurses -lm $(FLAGS)
	@echo "$(WHITE)$(BOLD)\t[COMPILED SUCCESSFULLY]"
	@echo "[READY]:$(RESET)$(WHITE)\t$(NAME)$(RESET)"


# CLEAN OBJECT FILES
clean:
	@echo "$(WHITE)$(BOLD)\t[CLEANING OBJ...]$(RESET)"
	@for file in $(OBJ); do \
		if [ -f "$$file" ]; then \
			echo "$(RED)$(BOLD)[CLEAN]:\t$(RESET)$(RED)$$file$(RESET)"; \
			rm -f "$$file"; \
		fi; \
	done

# CLEAN EXEC / LIB
fclean:
	@echo "$(WHITE)$(BOLD)\t[CLEANING EXEC/LIB...]"
	@echo "$(RED)[CLEAN]:\t$(RESET)$(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) clean -s

# CLEAN EVERYTHING AND RE-COMPILE
re: fclean all
