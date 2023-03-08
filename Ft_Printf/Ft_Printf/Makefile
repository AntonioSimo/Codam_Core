# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/07 10:37:55 by asimone       #+#    #+#                  #
#    Updated: 2023/03/08 17:24:23 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADERFILES = ft_printf.h
SRC = 	ft_itoh.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnnbr.c \
		ft_putstr.c

OBJ = $(SRC:.c=.o)
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADERFILES)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN) $(BOLD)Compiling... $$(basename $@) $(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	@$(RM) $(OBJ)
	@printf "$(RED) $(BOLD) Deleting... $(RESET)\n"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
