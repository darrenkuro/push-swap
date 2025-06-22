# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 07:41:14 by dlu              ###   ########.fr        #
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
LIBFT	:=	$(LIBDIR)/$(_LIBFT)

VISDIR	:=	visualizer
VBUILD	:=	$(VISDIR)/build
_VISBIN	:=	visualzier
VISBIN	:=	$(VBUILD)/bin/$(_VISBIN)
VISLINK	:=	run-visualizer

CC			:=	cc
RM			:=	/bin/rm -f
CFLAGS		:=	-Wall -Wextra -Werror -g -MMD -MP
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

PAD_WIDTH	?=	22

.DEFAULT_GOAL	:=	all

.PHONY: all
all: $(TARGET1) $(TARGET2) $(VISLINK)

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
	@if [ -f "$(LIBDIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBDIR) $@ PAD_WIDTH=$(PAD_WIDTH); \
	fi
	@printf "%-*s 🧹 Removing visualizer build files and binary..." $(PAD_WIDTH) "$(PROJECT)"
	@$(RM) -r $(VBUILD) && $(RM) $(VISBIN) $(VISLINK)
	@echo " ✅ "
	@printf "%-*s 🧹 Removing git submodules...\n" $(PAD_WIDTH) "$(PROJECT)"
	@git submodule deinit -f --all 2>&1 | sed 's/^/    - /'
	@printf "%-*s ✅ Git submodules removed.\n" $(PAD_WIDTH) "$(PROJECT)"

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
	@if git submodule status "$(LIBDIR)" | grep -Eq '^[-+]'; then \
		printf "%-*s 🔄 Initializing submodule $(LIBDIR)...\n" $(PAD_WIDTH) "$(PROJECT)"; \
		git submodule update --init --recursive $(LIBDIR) 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $(LIBDIR) initialized.\n" $(PAD_WIDTH) "$(PROJECT)"; \
	fi
	@printf "%-*s ⚙️ Building $(_LIBFT)...\n" $(PAD_WIDTH) "$(PROJECT)"
	@$(MAKE) -C "$(LIBDIR)" --silent PAD_WIDTH=$(PAD_WIDTH)
	@printf "%-*s ✅ $(_LIBFT) built.\n" $(PAD_WIDTH) "$(PROJECT)"

$(VISBIN):
	@if git submodule status "$(VISDIR)" | grep -Eq '^[-+]'; then \
		printf "%-*s 🔄 Initializing submodule $(VISDIR)...\n" $(PAD_WIDTH) "$(PROJECT)"; \
		git submodule update --init --recursive $(VISDIR) 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $(VISDIR) initialized.\n" $(PAD_WIDTH) "$(PROJECT)"; \
	fi
	@printf "%-*s ⚙️ Building $(_VISBIN)...\n" $(PAD_WIDTH) "$(PROJECT)"
	@mkdir -p "$(VBUILD)"
	@cmake "$(VISDIR)" -B "$(VBUILD)" 2>&1 | sed 's/^/    /'
	@$(MAKE) -C "$(VBUILD)" 2>&1 | sed 's/^/    /'
	@printf "%-*s ✅ $(_VISBIN) built.\n" $(PAD_WIDTH) "$(PROJECT)"

$(VISLINK): $(VISBIN)
	@printf "%-*s 🔗 Symlinking $(_VISBIN) to $(VISLINK)..." $(PAD_WIDTH) "$(PROJECT)"
	@ln -sf "$(VISBIN)" $(VISLINK)
	@echo " ✅ "

-include $(OBJ:.o=.d)