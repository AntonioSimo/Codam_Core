# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/12 14:58:37 by asimone       #+#    #+#                  #
#    Updated: 2022/11/10 18:26:24 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
HEADERFILES := libft.h
SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strdup.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

BONUS =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

OBJ := $(SRC:.c=.o) #you convert the .c files in .o files
OBJ_BONUS := $(BONUS:.c=.o)
CFLAGS ?= -Wall -Wextra -Werror
RM := /bin/rm -f

ifdef	ISBONUS
OBJECT_ALL = $(OBJ) $(OBJ_BONUS)
else
OBJECT_ALL = $(OBJ)
endif

all : $(NAME)

$(NAME): $(OBJECT_ALL)
	ar rc $@ $^

bonus: 
	$(MAKE) ISBONUS=1
		
clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# $@ calling the target
# $< calling the first element in the target (prerequisite)
# $^ calling all the element in the target 
