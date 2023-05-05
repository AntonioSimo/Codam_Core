# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/08 14:40:17 by asimone       #+#    #+#                  #
#    Updated: 2023/05/05 14:30:09 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = src/server.c
CLIENT = src/client.c
SERVER_BONUS = src_bonus/server_bonus.c
CLIENT_BONUS = src_bonus/client_bonus.c
HEADERFILES = 	-I./include
				
SRC_DIR  = src
SRC_DIR_BONUS = src_bonus
LIBFT = libft/libft.a
EXE_SERVER = server
EXE_CLIENT = client
EXE_SERVER_BONUS = server_bonus
EXE_CLIENT_BONUS = client_bonus
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(EXE_CLIENT) $(EXE_SERVER)

$(EXE_SERVER): $(LIBFT) $(SERVER)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SERVER) $(LIBFT) -o $(EXE_SERVER)
	@printf "$(GREEN) $(BOLD) create exe $(SERVER)$(RESET)\n"

$(EXE_CLIENT): $(LIBFT) $(CLIENT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(CLIENT) $(LIBFT) -o $(EXE_CLIENT)
	@printf "$(GREEN) $(BOLD) create exe $(CLIENT)$(RESET)\n"

$(EXE_SERVER_BONUS): $(LIBFT) $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SERVER_BONUS) $(LIBFT) -o $(EXE_SERVER_BONUS)
	@printf "$(GREEN) $(BOLD) create exe $(SERVER_BONUS)$(RESET)\n"

$(EXE_CLIENT_BONUS): $(LIBFT) $(CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(CLIENT_BONUS) $(LIBFT) -o $(EXE_CLIENT_BONUS)
	@printf "$(GREEN) $(BOLD) create exe $(CLIENT_BONUS)$(RESET)\n"

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