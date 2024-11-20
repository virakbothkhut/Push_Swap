NAME                = push_swap

LIBFT               = ./libft/libft.a
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/
GNL_DIR    			= getNextLine/

CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra -I$(INC) -I$(GNL_DIR)
RM                  = rm -f


all: $(LIBFT) $(NAME)
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "for example for testing 10 random numbers"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10" 

PUSH_SWAP_SRC       = $(SRC_DIR)push_swap/push_swap.c \
                      $(SRC_DIR)push_swap/radix_sort.c \
                      $(SRC_DIR)push_swap/validation.c \
                      $(SRC_DIR)push_swap/error_handling.c

UTILS_SRC           = $(GNL_DIR)get_next_line.c \
					  $(GNL_DIR)get_next_line_utils.c \
					  $(SRC_DIR)utils/handle_input.c 
                      

PUSH_STACK_SRC      = $(SRC_DIR)push_stack/push_stack.c


SRCS                = $(PUSH_SWAP_SRC) $(UTILS_SRC) $(PUSH_STACK_SRC)


OBJS = $(OBJ_DIR)push_swap/push_swap.o \
       $(OBJ_DIR)push_swap/radix_sort.o \
       $(OBJ_DIR)push_swap/validation.o \
       $(OBJ_DIR)push_swap/error_handling.o \
       $(OBJ_DIR)getNextLine/get_next_line.o \
	   $(OBJ_DIR)getNextLine/get_next_line_utils.o \
       $(OBJ_DIR)utils/handle_input.o \
       $(OBJ_DIR)push_stack/push_stack.o 


start:
					@make all

$(LIBFT):
					@make -C ./libft

$(NAME):            $(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
					@echo "Executable $(NAME) created."


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)push_swap/:
	@mkdir -p $(OBJ_DIR)push_swap

$(OBJ_DIR)push_stack/:
	@mkdir -p $(OBJ_DIR)push_stack

$(OBJ_DIR)push_swap/%.o: $(SRC_DIR)push_swap/%.c | $(OBJ_DIR)push_swap/
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)utils/%.o: $(SRC_DIR)utils/%.c | $(OBJ_DIR)utils/
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)push_stack/%.o: $(SRC_DIR)push_stack/%.c | $(OBJ_DIR)push_stack/
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)get_next_line.o: $(GNL_DIR)get_next_line.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)getNextLine/get_next_line_utils.o: $(GNL_DIR)get_next_line_utils.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean:             clean
					@$(RM) $(NAME)
					@make fclean -C ./libft


re:                 fclean all

.PHONY:             start all clean fclean
