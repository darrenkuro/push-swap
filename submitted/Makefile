NAME=push_swap
SRC=
CC=cc
RM=/bin/rm -f
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
