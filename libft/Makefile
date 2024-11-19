CC = cc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror
# Source files
SRCS = $(wildcard *.c)
# Object files
OBJS = $(SRCS:.c=.o)
# name
NAME = libft.a
LIB = ar rcs
RM = rm -f
all: $(NAME)
$(NAME): $(OBJS)
	$(LIB) $(NAME) $(SRCS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all