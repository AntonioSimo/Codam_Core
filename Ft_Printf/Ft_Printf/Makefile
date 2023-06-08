# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/07 10:37:55 by asimone       #+#    #+#                  #
#    Updated: 2023/03/13 16:22:45 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRC_DIR := src
OBJ_DIR := obj
HEADER := ./include/ft_printf.h
SOURCES := 	$(SRC_DIR)/ft_itoh.c \
			$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_putchar.c \
			$(SRC_DIR)/ft_putnbr.c \
			$(SRC_DIR)/ft_putnnbr.c \
			$(SRC_DIR)/ft_putstr.c

OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))

GREEN = \x1b[32;01m
RED = \x1b[31;01m
YELLOW = \033[33;1m
BOLD = \033[1m
RESET = \x1b[0m

CC := gcc
AR := ar
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -Iinclude
LFLAGS := -rcs
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(HEADER) $(OBJ_DIR) $(OBJECTS) 
	@$(AR) $(LFLAGS) $(NAME) $(OBJECTS)
	@printf "$(GREEN) $(BOLD) ======= Creating archive... $(NAME) ======= $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "$(RED) $(BOLD) Deleting objects... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(NAME)
	@printf "$(RED) $(BOLD) Deleting $(NAME)... $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
