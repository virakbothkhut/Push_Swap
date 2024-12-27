NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDE = -I./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/input_checker.c $(SRC_DIR)/r_rotate.c \
      $(SRC_DIR)/set_up.c $(SRC_DIR)/stack.c $(SRC_DIR)/algorithm.c $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/sort_handler.c $(SRC_DIR)/input_handler.c  \

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))


BOLD    := \033[1m
DIM     := \033[2m
ITALIC  := \033[3m
UNDER   := \033[4m
BLINK   := \033[5m
REVERSE := \033[7m
HIDDEN  := \033[8m
PINK    := \033[35m
PURPLE 	:= \033[35m 
BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[96m
MAGENTA := \033[38;5;206m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiled with $(MAGENTA)$(BLINK)$(BOLD)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(ORANGE)$(BOLD)🔥🔥🔥Hope this project is correct this time 🥹🥹🥹 🔥🔥🔥$(RESET)"
	@echo "$(CYAN)$(BOLD)$(BLINK) HAPPY NEW YEAR 🎁🎁🎁🎁🎁$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)$(BOLD)Compiled ✅ >>>>>>>>> $(CYAN)$(UNDER)$^$(RESET)"
	@echo "$(MAGENTA)$(BLINK) LET's GO 🎅🎅🎄🎄🎄$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(BLUE) $(BOLD)$(NAME) $(RESET) Clean is finished ✅ "


re: fclean all

.PHONY: all clean fclean re
