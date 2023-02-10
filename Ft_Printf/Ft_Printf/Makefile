# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/07 10:37:55 by asimone       #+#    #+#                  #
#    Updated: 2022/11/09 14:44:38 by asimone       ########   odam.nl          #
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
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

clean: 
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
