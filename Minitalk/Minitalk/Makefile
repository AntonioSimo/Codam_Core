# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/08 14:40:17 by asimone       #+#    #+#                  #
#    Updated: 2023/03/08 18:20:38 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = server.c
CLIENT = client.c

OBJ_SERVER = server.o
OBJ_CLIENT = client.o
LIBFT = libft/libft.a
EXE_SERVER = server
EXE_CLIENT = client
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(EXE_SERVER) $(EXE_CLIENT)

$(EXE_SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(SERVER) $(LIBFT) -o $(EXE_SERVER)
	@printf "$(GREEN) $(BOLD)Compiling... $$(basename $@) $(RESET)\n"

$(EXE_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT) $(LIBFT) -o $(EXE_CLIENT)
	@printf "$(GREEN) $(BOLD)Compiling... $$(basename $@) $(RESET)\n"

%.o: %.c
	@$(CC) -Iinclude -Ilibft/libft.a $(CFLAGS) -c $^ -o $@

$(LIBFT):
	@make -C libft

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@make clean -C libft
	@printf "$(RED) $(BOLD) Deleting... $(RESET)\n"

fclean: clean
	@$(RM) $(EXE_SERVER) $(EXE_CLIENT)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean