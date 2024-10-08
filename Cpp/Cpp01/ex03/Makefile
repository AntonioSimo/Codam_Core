# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimone <asimone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 16:42:36 by asimone           #+#    #+#              #
#    Updated: 2024/04/03 15:14:50 by asimone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Unnecessary_violence

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := include

CMP := c++
FLAGS := -Wall -Wextra -Werror -fsanitize=address -g
IFLAGS := -I$(LIB_DIR)

SOURCES :=	$(SRC_DIR)/HumanA.cpp \
			$(SRC_DIR)/HumanB.cpp \
			$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Weapon.cpp
			
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.cpp=.o))
HEADER := 	$(LIB_DIR)/HumanA.hpp \
			$(LIB_DIR)/HumanB.hpp \
			$(LIB_DIR)/Weapon.hpp

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(HEADER) $(OBJ_DIR) $(OBJECTS) $(SOURCES)
	@$(CMP) $(FLAGS) $(IFLAGS) $(SOURCES) -o $(NAME)
	@printf "$(GREEN) $(BOLD) ========== Created program $(NAME) ========== $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CMP) $(FLAGS) $(IFLAGS) -c $< -o $@
	@printf "$(YELLOW) Compiling... $(RESET) $(notdir $<)\n"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@printf "$(RED) Deleting objects... $(RESET)\n"
	
fclean: clean
	@$(RM) -rf $(NAME)
	@printf "$(RED) Deleting $(NAME)... $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
