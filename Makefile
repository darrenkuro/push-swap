# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 01:00:40 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push-swap
PROJECT	:=	$$YELLOW[$(NAME)]$$RESET
TARGET1	:=	push_swap
TARGET2	:=	checker

INCDIR	:=	include

SRCDIR	:=	src
_SRC	:=	push_swap.c input.c utils.c op_exec1.c op_exec2.c op_exec3.c \
			sort.c optimize_rr.c optimize_rrr.c optimize_op.c \
			utils_calc.c utils_limit.c utils_rotate.c utils_rotate_count.c
_BSRC	:=	checker_bonus.c input.c op_exec1.c op_exec2.c op_exec3.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/, $(_SRC))
BSRC	:=	$(addprefix $(SRCDIR)/, $(_BSRC))

OBJDIR	:=	obj
_OBJ	:=	$(_SRC:.c=.o)
_BOBJ	:=	$(_BSRC:.c=.o)
OBJ		:=	$(addprefix $(OBJDIR)/, $(_OBJ))
BOBJ	:=	$(addprefix $(OBJDIR)/, $(_BOBJ))

LIBDIR	:=	libft
_LIBFT	:=	libft.a
LIBFT	:=	$(addprefix $(LIBDIR)/, $(_LIBFT))

CC			:=	cc
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror -g -MMD -MP
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

PAD_WIDTH	?=	22

.DEFAULT_GOAL	:=	all

.PHONY: all
all: $(TARGET1) $(TARGET2)

.PHONY: bonus
bonus: $(TARGET2)

.PHONY: clean
clean:
	@printf "%-*s 🧹 Removing object files..." $(PAD_WIDTH) "$(PROJECT)"
	@$(RM) -r $(OBJDIR)
	@echo " ✅ "

.PHONY: fclean
fclean: clean
	@printf "%-*s 🗑️ Removing binary..." $(PAD_WIDTH) "$(PROJECT)"
	@$(RM) $(TARGET1) $(TARGET2)
	@echo " ✅ "
	@$(MAKE) -C $(LIBDIR) $@ PAD_WIDTH=$(PAD_WIDTH)

.PHONY: re
re: fclean all

.PHONY: var-%
var-%:
	@echo $($*)

$(OBJDIR):
	@printf "%-*s 📁 Creating obj directory..." $(PAD_WIDTH) "$(PROJECT)"
	@mkdir -p $@
	@echo " ✅ "

$(TARGET1): $(LIBFT) $(OBJ)
	@printf "%-*s 🛠️ Building binary: $@" $(PAD_WIDTH) "$(PROJECT)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)
	@echo " ✅ "

$(TARGET2): $(LIBFT) $(BOBJ)
	@printf "%-*s 🛠️ Building binary: $@" $(PAD_WIDTH) "$(PROJECT)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(BOBJ) $(LDFLAGS) $(LDLIBS)
	@echo " ✅ "

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf "%-*s ⚙️ Compiling: $<..." $(PAD_WIDTH) "$(PROJECT)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@echo " ✅ "

$(LIBFT):
	@printf "$(PROJECT) 🔄 Initializing and updating git submodules..."
	@git submodule update --init --recursive
	@echo " ✅ "
	@echo "$(PROJECT) ⚙️ Building libft..."
	@$(MAKE) -C $(LIBDIR) --silent PAD_WIDTH=$(PAD_WIDTH)

-include $(OBJ:.o=.d)