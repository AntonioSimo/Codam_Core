# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/08 14:40:17 by asimone       #+#    #+#                  #
#    Updated: 2023/06/09 16:22:35 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

OBJ_DIR := obj
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_BONUS_SRC = $(SRC_DIR_BONUS)/server_bonus.c
CLIENT_BONUS_SRC = $(SRC_DIR_BONUS)/client_bonus.c
SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o
CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o
LIBFT_DIR := lib/Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR := src
SRC_DIR_BONUS = src_bonus
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

all: $(OBJ_DIR) $(EXE_CLIENT) $(EXE_SERVER)

$(EXE_SERVER): $(LIBFT) $(HEADER) $(SERVER_SRC)
	@$(CC) $(IFLAGS) $(SERVER_SRC) -c -o $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(EXE_SERVER)
	@printf "$(YELLOW) $(BOLD) ======= Created $(EXE_SERVER) ======= $(RESET)\n"

$(EXE_CLIENT): $(LIBFT) $(HEADER) $(CLIENT_SRC)
	@$(CC) $(IFLAGS) $(CLIENT_SRC) -c -o $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(EXE_CLIENT)
	@printf "$(YELLOW) $(BOLD) ======= Created $(EXE_CLIENT) ======= $(RESET)\n"

$(EXE_SERVER_BONUS): $(LIBFT) $(HEADER_BONUS) $(SERVER_BONUS)
	@$(CC) $(IFLAGS) $(SERVER_BONUS_SRC) -c -o $(SERVER_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(EXE_SERVER_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(EXE_SERVER_BONUS) ======= $(RESET)\n"

$(EXE_CLIENT_BONUS): $(LIBFT) $(HEADER_BONUS) $(CLIENT_BONUS)
	@$(CC) $(IFLAGS) $(CLIENT_BONUS_SRC) -c -o $(CLIENT_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(EXE_CLIENT_BONUS)
	@printf "$(BLUE) $(BOLD) ======= Created $(EXE_CLIENT_BONUS) ======= $(RESET)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

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