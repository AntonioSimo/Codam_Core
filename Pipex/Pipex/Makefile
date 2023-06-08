NAME := pipex
SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := lib/Libft
LIBFT := $(LIBFT_DIR)/libft.a
HEADER := ./include/pipex.h

SOURCES :=	$(SRC_DIR)/main.c

OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))

IFLAGS := -Iinclude -I$(LIBFT_DIR)/include
CFLAGS := -Wall -Wextra -Werror $(IFLAGS)

BLUE = \033[34;1m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
YELLOW = \033[33;1m
BOLD = \033[1m
RESET = \x1b[0m
RM = /bin/rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(HEADER) $(OBJ_DIR) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(SOURCES) $(LIBFT) -o $(NAME)
	@printf "$(BLUE) $(BOLD)======= Created program $(NAME) ======= $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@
	@printf "$(YELLOW) $(BOLD)Compiling... $(RESET) $(notdir $<)\n"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@printf "$(RED) $(BOLD) Deleting objects... $(RESET)\n"

fclean: clean
	@$(RM) -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@printf "$(RED) $(BOLD) Deleting $(NAME)... $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re