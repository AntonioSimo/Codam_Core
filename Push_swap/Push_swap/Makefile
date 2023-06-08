# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/03 16:36:01 by asimone       #+#    #+#                  #
#    Updated: 2023/05/09 14:56:36 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = 	$(SRC_DIR)/lst_utils.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/get_lowest.c \
		$(SRC_DIR)/radix_sort.c

HEADER = ./include/push_swap.h

SRC_DIR = src
OBJ_DIR := obj_files
LIBFT_DIR := lib/Libft
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC:.c=.o))
LIBFT = $(LIBFT_DIR)/libft.a
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
IFLAGS = -Iinclude
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(HEADER) $(OBJ_DIR) $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SOURCES) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "$(GREEN) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
		
clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@printf "$(RED) $(BOLD) Deleting Push_Swap... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean