# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/09 11:09:38 by asimone       #+#    #+#                  #
#    Updated: 2023/05/31 19:22:45 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := fract-ol
SRC_DIR := src
OBJ_DIR := obj
MLX42_DIR := lib/MLX42
LIBFT_DIR := lib/Libft
MLX42 := $(MLX42_DIR)/build/libmlx42.a
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ./include/fractol.h
SOURCES := 	$(SRC_DIR)/colors.c \
			$(SRC_DIR)/hook.c \
			$(SRC_DIR)/julia.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/mandelbrot.c \
			$(SRC_DIR)/map.c \
			$(SRC_DIR)/parsing.c
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))

CC := gcc
LFLAGS := -lm -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
IFLAGS := -Iinclude -I$(MLX42_DIR)/include -I$(LIBFT_DIR)/include
CFLAGS := -fsanitize=address -g -Wall -Wextra -Werror $(IFLAGS) -Ofast

BLUE = \033[34;1m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
YELLOW = \033[33;1m
BOLD = \033[1m
RESET = \x1b[0m
RM = /bin/rm -f

all: $(MLX42) $(LIBFT) $(NAME)

$(MLX42):
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build -j4 --quiet

$(LIBFT):
	@make -C $(LIBFT_DIR) --quiet

$(NAME): $(MLX42) $(LIBFT) $(HEADER) $(OBJ_DIR) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(SOURCES) $(MLX42) $(LIBFT) $(LFLAGS) -o $(NAME)
	@printf "$(BLUE) $(BOLD)======= Created program $(NAME) ======= $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX42_DIR)/build -j4
	@printf "$(RED) $(BOLD) Deleting objects... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean/fast -C $(MLX42_DIR)/build -j4
	@printf "$(RED) $(BOLD) Deleting $(NAME)... $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
