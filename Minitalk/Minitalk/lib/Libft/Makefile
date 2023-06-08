# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asimone <asimone@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/12 14:58:37 by asimone       #+#    #+#                  #
#    Updated: 2023/03/29 16:33:57 by asimone       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
HEADER := libft.h
SRC_DIR = src
OBJ_DIR := obj
SOURCES =	$(SRC_DIR)/ft_atoi.c \
		$(SRC_DIR)/ft_bzero.c \
		$(SRC_DIR)/ft_calloc.c \
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_itoa.c \
		$(SRC_DIR)/ft_lstadd_back.c \
		$(SRC_DIR)/ft_lstadd_front.c \
		$(SRC_DIR)/ft_lstclear.c \
		$(SRC_DIR)/ft_lstiter.c \
		$(SRC_DIR)/ft_lstdelone.c \
		$(SRC_DIR)/ft_lstlast.c \
		$(SRC_DIR)/ft_lstmap.c \
		$(SRC_DIR)/ft_lstnew.c \
		$(SRC_DIR)/ft_lstsize.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_memset.c \
		$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_printf_utils.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_strlcpy.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_substr.c \
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_toupper.c \
		$(SRC_DIR)/get_next_line.c

OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o)) #you convert the .c files in .o files
GREEN = \x1b[32;01m
RED = \x1b[31;01m
BOLD = \033[1m
RESET = \x1b[0m
AR = ar
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -rcs
IFLAGS = -Iinclude
RM := /bin/rm -f

all : $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS)
	@$(AR) $(LFLAGS) $(NAME) $(OBJECTS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) $(CFLAGS) -c $^ -o $@
	@printf "$(GREEN) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"
		
clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "$(RED) $(BOLD) Deleting files... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

# $@ calling the target
# $< calling the first element in the target (prerequisite)
# $^ calling all the element in the target 
