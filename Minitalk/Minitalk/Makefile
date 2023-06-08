# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/08 14:40:17 by asimone       #+#    #+#                  #
#    Updated: 2023/05/07 18:09:44 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = src/server.c
CLIENT = src/client.c
SERVER_BONUS = src_bonus/server_bonus.c
CLIENT_BONUS = src_bonus/client_bonus.c
HEADER = ./include/minitalk.h
HEADER_BONUS = ./include/minitalk_bonus.h
				
SRC_DIR  = src
SRC_DIR_BONUS = src_bonus
LIBFT = libft/libft.a
EXE_SERVER = server
EXE_CLIENT = client
EXE_SERVER_BONUS = server_bonus
EXE_CLIENT_BONUS = client_bonus
BLUE = \033[34;1m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
YELLOW = \033[33;1m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./include
RM = /bin/rm -f

all: $(EXE_CLIENT) $(EXE_SERVER)

$(EXE_SERVER): $(LIBFT) $(HEADER) $(SERVER)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER) $(LIBFT) -o $(EXE_SERVER)
	@printf "$(YELLOW) $(BOLD) ======= Created $(SERVER) ======= $(RESET)\n"

$(EXE_CLIENT): $(LIBFT) $(HEADER) $(CLIENT)
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT) $(LIBFT) -o $(EXE_CLIENT)
	@printf "$(YELLOW) $(BOLD) ======= Created $(CLIENT) ======= $(RESET)\n"

$(EXE_SERVER_BONUS): $(LIBFT) $(HEADER_BONUS) $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER_BONUS) $(LIBFT) -o $(EXE_SERVER_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(SERVER_BONUS) ======= $(RESET)\n"

$(EXE_CLIENT_BONUS): $(LIBFT) $(HEADER_BONUS) $(CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT_BONUS) $(LIBFT) -o $(EXE_CLIENT_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(CLIENT_BONUS) $(RESET)\n"

$(LIBFT):
	@make -C libft

bonus:  $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)

clean:
	@make clean -C libft
	@printf "$(RED) $(BOLD) Deleting Minitalk... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(EXE_SERVER) $(EXE_CLIENT) $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean