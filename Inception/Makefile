# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: antoniosimone <antoniosimone@student.42      +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/20 16:42:36 by asimone       #+#    #+#                  #
#    Updated: 2025/03/16 12:36:10 by antoniosimo   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := inception

DATA_DIR := /home/asimone/data

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

COMPOSE_FILE = ./srcs/docker-compose.yml

RM = /bin/rm -rf

all: up

up: $(DATA_DIR)
	@docker-compose -f $(COMPOSE_FILE) up --build -d
	@printf "$(GREEN)$(BOLD) Container $(NAME) started successfully$(RESET)\n"

down:
	@docker-compose -f $(COMPOSE_FILE) down
	@printf "$(RED) Container $(NAME) stopped$(RESET)\n"

$(DATA_DIR):
	@mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb
	@printf "$(YELLOW)Created directory $(DATA_DIR) for persistent data$(RESET)\n"

clean: down
	@$(RM) $(DATA_DIR)
	@printf "$(RED)Persistent data removed$(RESET)\n"

fclean: clean
	@docker system prune -af
	@printf "$(RED)Docker system cleanup completed$(RESET)\n"

re: fclean all

.PHONY: all up down clean fclean re