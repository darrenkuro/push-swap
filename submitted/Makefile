# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2023/05/23 10:58:04 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
BONUS	:=	checker

SRCDIR	:=	srcs
_SRC	:=	push_swap.c op_print.c sort_simple.c input.c
_BSRC	:=	checker_bonus.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))
BSRC	:=	$(addprefix $(SRCDIR)/, $(_BSRC))

OBJDIR	:=	objs
_OBJ	:=	$(_SRC:.c=.o)
_BOBJ	:=	$(_BSRC:.c=.o)
OBJ		:=	$(addprefix $(OBJDIR)/, $(_OBJ))
BOBJ	:=	$(addprefix $(OBJDIR)/, $(_BOBJ))

LIBDIR	:=	libft
LIBFT	:=	libft.a

CC		:=	cc
RM		:=	/bin/rm -f
CFLAGS	:=	-Wall -Wextra -Werror

all: $(NAME) $(BONUS)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBDIR) -lft -I $(LIBDIR)

$(BONUS): libft $(BOBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBDIR) -lft -I $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIBDIR)

libft:
	@make -C $(LIBDIR) $(LIBFT) >/dev/null

bonus: $(BONUS)

clean:
	@make -C $(LIBDIR) $@ >/dev/null
	$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBDIR) $@ >/dev/null
	$(RM) $(NAME)

re: fclean all

var-%:
	@echo $($*)

.PHONY: all clean fclean re bonus libft var-%
