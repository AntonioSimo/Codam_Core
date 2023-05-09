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

SRC = 	src/lst_utils.c \
		src/push_swap.c \
		src/parse.c \
		src/push.c \
		src/rotate.c \
		src/sort.c \
		src/swap.c \
		src/utils.c \
		src/get_lowest.c \
		src/radix_sort.c

HEADERFILES = 	-I./include
HEAD = ./include/push_swap.h

SRC_DIR = src
OBJ_DIR := obj_files
OBJ := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC:.c=.o))
LIBFT = Libft/libft.a
EXE_PUSH_SWAP = push_swap
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
RM = /bin/rm -f

all: $(EXE_PUSH_SWAP)

$(EXE_PUSH_SWAP): $(HEAD) $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SRC) $(LIBFT) -o $(EXE_PUSH_SWAP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(HEADERFILES) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

$(LIBFT):
	@make -C Libft

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
		
clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C Libft
	@printf "$(RED) $(BOLD) Deleting Push_Swap... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(EXE_PUSH_SWAP)
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean