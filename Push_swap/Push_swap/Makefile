# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/03 16:36:01 by asimone       #+#    #+#                  #
#    Updated: 2023/03/29 22:30:14 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = 	src/check.c \
		src/lst_utils.c \
		src/push_swap.c \
		src/parse.c \
		src/push.c \
		src/rotate.c \
		src/sort.c \
		src/swap.c \
		src/utils.c

HEADERFILES = 	-I./include

SRC_DIR = src
OBJ_DIR := obj_files
OBJ := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC:.c=.o))
LIBFT = libft/libft.a
EXE_PUSH_SWAP = push_swap
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(EXE_PUSH_SWAP)

$(EXE_PUSH_SWAP): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SRC) $(LIBFT) -o $(EXE_PUSH_SWAP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(HEADERFILES) -Ilibft/libft.a $(CFLAGS) -c $< -o $@
	@printf "$(GREEN) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

$(LIBFT):
	@make -C libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C libft
	@printf "$(RED) $(BOLD) Deleting... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(EXE_PUSH_SWAP)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean