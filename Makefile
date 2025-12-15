# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2023/05/26 10:50:07 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap
BONUS	:=	checker

SRCDIR	:=	srcs
_SRC	:=	push_swap.c input.c utils.c op_exec1.c op_exec2.c op_exec3.c \
			sort.c optimize_rr.c optimize_rrr.c optimize_op.c \
			utils_calc.c utils_limit.c utils_rotate.c utils_rotate_count.c
_BSRC	:=	checker_bonus.c input.c op_exec1.c op_exec2.c op_exec3.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))
BSRC	:=	$(addprefix $(SRCDIR)/, $(_BSRC))

OBJDIR	:=	objs
_OBJ	:=	$(_SRC:.c=.o)
_BOBJ	:=	$(_BSRC:.c=.o)
OBJ		:=	$(addprefix $(OBJDIR)/, $(_OBJ))
BOBJ	:=	$(addprefix $(OBJDIR)/, $(_BOBJ))

LIBDIR	:=	libft
LIBNAME	:=	libft.a
LIBFT	:=	$(addprefix $(LIBDIR)/, $(LIBNAME))

CC		:=	cc
RM		:=	/bin/rm -f
CFLAGS	:=	-Wall -Wextra -Werror -g

all: $(NAME) $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L $(LIBDIR) -lft -I $(LIBDIR)

$(BONUS): $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) -o $@ $(BOBJ) -L $(LIBDIR) -lft -I $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIBDIR)

$(LIBFT):
	@make -C $(LIBDIR) $(LIBNAME) >/dev/null

bonus: $(BONUS)

clean:
	@make -C $(LIBDIR) $@ >/dev/null
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@make -C $(LIBDIR) $@ >/dev/null
	$(RM) $(NAME) $(BONUS)

re: fclean all

var-%:
	@echo $($*)

.PHONY: all clean fclean re bonus libft var-%
