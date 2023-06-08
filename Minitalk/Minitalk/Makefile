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

SERVER = $(SRC_DIR)/server.c
CLIENT = $(SRC_DIR)/client.c
SERVER_BONUS = $(SRC_DIR_BONUS)/server_bonus.c
CLIENT_BONUS = $(SRC_DIR_BONUS)/client_bonus.c
LIBFT_DIR := lib/Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR := src
SRC_DIR_BONUS = src_bonus
OBJ_DIR := obj
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC:.c=.o))
HEADER = ./include/minitalk.h
HEADER_BONUS = ./include/minitalk_bonus.h
				
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
IFLAGS = -Iinclude -I$(LIBFT_DIR)/include
RM = /bin/rm -f

all: $(EXE_CLIENT) $(EXE_SERVER)

$(EXE_SERVER): $(LIBFT) $(HEADER) $(SERVER) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER) $(LIBFT) -o $(EXE_SERVER)
	@printf "$(YELLOW) $(BOLD) ======= Created $(SERVER) ======= $(RESET)\n"

$(EXE_CLIENT): $(LIBFT) $(HEADER) $(CLIENT) $(OBJ_DIR) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT) $(LIBFT) -o $(EXE_CLIENT)
	@printf "$(YELLOW) $(BOLD) ======= Created $(CLIENT) ======= $(RESET)\n"

$(EXE_SERVER_BONUS): $(LIBFT) $(HEADER_BONUS) $(SERVER_BONUS) $(OBJ_DIR) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER_BONUS) $(LIBFT) -o $(EXE_SERVER_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(SERVER_BONUS) ======= $(RESET)\n"

$(EXE_CLIENT_BONUS): $(LIBFT) $(HEADER_BONUS) $(CLIENT_BONUS) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT_BONUS) $(LIBFT) -o $(EXE_CLIENT_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(CLIENT_BONUS) $(RESET)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

bonus:  $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@printf "$(RED) $(BOLD) Deleting Minitalk... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(EXE_SERVER) $(EXE_CLIENT) $(EXE_SERVER_BONUS) $(EXE_CLIENT_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean