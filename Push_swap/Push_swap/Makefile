# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/03 16:36:01 by asimone       #+#    #+#                  #
#    Updated: 2023/03/08 16:40:23 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap.c

OBJ_PUSH_SWAP = push_swap.o
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

$(EXE_PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIBFT)
	@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(EXE_PUSH_SWAP)
	@printf "$(GREEN) $(BOLD)Compiling... $$(basename $@) $(RESET)\n"

%.o: %.c
	@$(CC) -Iinclude -Ilibft/libft.a $(CFLAGS) -c $^ -o $@

$(LIBFT):
	@make -C libft

clean:
	@$(RM) $(OBJ_PUSH_SWAP)
	@make clean -C libft
	@printf "$(RED) $(BOLD) Deleting... $(RESET)\n"

fclean: clean
	@$(RM) $(EXE_PUSH_SWAP)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean