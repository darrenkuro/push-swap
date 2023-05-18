NAME=push_swap
SRC=push_swap.c op_print.c sort_simple.c input.c
LIBDIR=libft
CC=cc
RM=/bin/rm -f
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make -C $(LIBDIR) all >/dev/null
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBDIR) -lft -I $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIBDIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
