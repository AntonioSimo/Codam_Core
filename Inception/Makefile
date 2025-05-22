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

DATA_DIR := ${HOME}/data

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BOLD = \033[1m
RESET = \033[0m

COMPOSE_FILE = ./srcs/docker-compose.yml

RM = /bin/rm -rf

all: build up

build: 
	@docker compose -f $(COMPOSE_FILE) build
	@printf "$(GREEN)$(BOLD) Container $(NAME) build successfully$(RESET)\n"

up: 
	mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb
	@printf "$(YELLOW)Created directory $(DATA_DIR) for persistent data$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) up --no-deps --build --force-recreate
	@printf "$(GREEN)$(BOLD) Container $(NAME) started successfully$(RESET)\n"

down:
	@docker compose -f $(COMPOSE_FILE) down
	@printf "$(RED) Container $(NAME) stopped$(RESET)\n"

clean: down
	@docker stop $(shell docker ps -qa) || true
	@docker rm $(shell docker ps -qa) || true
	@docker rmi -f $(shell docker images -qa) || true
	@docker volume rm $(shell docker volume ls -q) || true
	@docker network rm $(shell docker network ls -q) 2>/dev/null || true
	@docker system prune -f || true
	@docker volume prune -f || true
	@docker network prune -f || true

fclean: clean
	@docker system prune -af
	@printf "$(RED)Docker system cleanup completed$(RESET)\n"

maria:
	docker exec -it mariadb bash

re: fclean all

delete:
	docker-compose -f $(COMPOSE_FILE) -p $(PROJECT_NAME) down --volumes --remove-orphans

rmf: delete fclean

.PHONY: all up down clean fclean re maria

