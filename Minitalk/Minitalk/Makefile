# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/08 14:40:17 by asimone       #+#    #+#                  #
#    Updated: 2023/04/23 17:04:40 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER = src/server.c
CLIENT = src/client.c
SERVER_BONUS = src/server_bonus.c
CLIENT_BONUS = src/client_bonus.c
		
HEADERFILES = 	-I./include
				
SRC_DIR  = src
OBJ_DIR := obj_files
OBJ := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC:.c=.o))
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

all: $(EXE_CLIENT) $(EXE_SERVER) $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)

$(EXE_SERVER): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SERVER) $(LIBFT) -o $(EXE_SERVER)

$(EXE_CLIENT): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(CLIENT) $(LIBFT) -o $(EXE_CLIENT)

$(EXE_SERVER_BONUS): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(SERVER_BONUS) $(LIBFT) -o $(EXE_SERVER_BONUS)

$(EXE_CLIENT_BONUS): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERFILES) $(CLIENT_BONUS) $(LIBFT) -o $(EXE_CLIENT_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(HEADERFILES) -Ilibft/libft.a $(CFLAGS) -c $^ -o $@
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
	@$(RM) -rf $(EXE_SERVER) $(EXE_CLIENT) $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean