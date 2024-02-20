# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimone <asimone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 12:31:36 by asimone           #+#    #+#              #
#    Updated: 2024/02/20 18:04:48 by asimone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

SRC_DIR := src
OBJ_DIR := obj

CMP := c++
FLAGS := -Wall -Wextra -Werror

SOURCES :=  $(SRC_DIR)/megaphone.cpp
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.cpp=.o))

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(SOURCES)
	@$(CMP) $(FLAGS) $(SOURCES) -o $(NAME)
	@printf "$(GREEN) $(BOLD) ========== Created program $(NAME) ========== $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CMP) $(FLAGS) -c $< -o $@
	@printf "$(YELLOW) Compiling... $(RESET) $(notdir $<)\n"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "$(RED) Deleting objects... $(RESET)\n"
	
fclean: clean
	@$(RM) -rf $(NAME)
	@printf "$(RED) Deleting $(NAME)... $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re