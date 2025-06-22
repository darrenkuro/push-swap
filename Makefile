# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 08:55:14 by dlu              ###   ########.fr        #
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
SRC		:=	$(addprefix $(SRCDIR)/,$(_SRC))
BSRC	:=	$(addprefix $(SRCDIR)/,$(_BSRC))

OBJDIR	:=	obj
_OBJ	:=	$(_SRC:.c=.o)
_BOBJ	:=	$(_BSRC:.c=.o)
OBJ		:=	$(addprefix $(OBJDIR)/,$(_OBJ))
BOBJ	:=	$(addprefix $(OBJDIR)/,$(_BOBJ))

LIBDIR	:=	libft
_LIBFT	:=	libft.a
LIBFT	:=	$(LIBDIR)/$(_LIBFT)

VISDIR	:=	visualizer
VBUILD	:=	$(VISDIR)/build
_VISBIN	:=	visualizer
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

.SILENT:

define submodule-target
.PHONY:	$1-init
$1-init:
	if git submodule status "$1" | grep -Eq '^[-+]'; then \
		printf "%-*s 🔄 Initializing submodule $1...\n" $$(PAD_WIDTH) "$$(PROJECT)"; \
		git submodule update --init --recursive $1 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $1 initialized.\n" $$(PAD_WIDTH) "$$(PROJECT)"; \
	fi

.PHONY:	$1-deinit
$1-deinit:
	if [ -f "$1/.git" ]; then \
		printf "%-*s 🧹 Deinitializing $1 submodule...\n" \
		$$(PAD_WIDTH) "$$(PROJECT)"; \
		git submodule deinit -f $1 2>&1 | sed 's/^/    - /'; \
		printf "%-*s ✅ Git submodule $1 deinitialized.\n" \
		$$(PAD_WIDTH) "$$(PROJECT)"; \
	fi
endef

$(eval $(call submodule-target,$(LIBDIR)))
$(eval $(call submodule-target,$(VISDIR)))

.PHONY:	all
all:	$(TARGET1) $(TARGET2) $(VISLINK)

.PHONY:	bonus
bonus:	$(TARGET2)

.PHONY:	$(LIBDIR)-clean
$(LIBDIR)-clean:
	if [ -f $(LIBDIR)/Makefile ]; then \
		$(MAKE) -C $(LIBDIR) clean PAD_WIDTH=$(PAD_WIDTH); \
	fi

.PHONY:	clean
clean:	$(LIBDIR)-clean
	if [ -d $(OBJDIR) ]; then \
		printf "%-*s 🧹 Removing object files..." $(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) -r $(OBJDIR); \
		echo " ✅ "; \
	fi

.PHONY:	$(LIBDIR)-fclean
$(LIBDIR)-fclean:
	if [ -f "$(LIBDIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBDIR) fclean PAD_WIDTH=$(PAD_WIDTH); \
	fi

.PHONY:	$(VISDIR)-fclean
$(VISDIR)-fclean:
	if [ -d $(VBUILD) ]; then \
		printf "%-*s 🧹 Removing build files, binary, and symlink for visualizer..." \
		$(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) -r $(VBUILD); \
		$(RM) "$(VISLINK)"; \
		echo " ✅ "; \
	fi

.PHONY:	fclean
fclean:	clean $(LIBDIR)-fclean $(VISDIR)-fclean $(LIBDIR)-deinit $(VISDIR)-deinit
	if [ -f "$(TARGET1)" ] || [ -f "$(TARGET2)" ]; then \
		printf "%-*s 🗑️ Removing binary..." $(PAD_WIDTH) "$(PROJECT)"; \
		$(RM) $(TARGET1) $(TARGET2); \
		echo " ✅ "; \
	fi

.PHONY:	re
re:	fclean all

.PHONY:	var-%
var-%:
	echo $($*)

$(OBJDIR):
	printf "%-*s 📁 Creating obj directory..." $(PAD_WIDTH) "$(PROJECT)"
	mkdir -p $@
	echo " ✅ "

$(TARGET1):	$(LIBFT) $(OBJ)
	printf "%-*s 🛠️ Building binary: $@" $(PAD_WIDTH) "$(PROJECT)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)
	echo " ✅ "

$(TARGET2):	$(LIBFT) $(BOBJ)
	printf "%-*s 🛠️ Building binary: $@" $(PAD_WIDTH) "$(PROJECT)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(BOBJ) $(LDFLAGS) $(LDLIBS)
	echo " ✅ "

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	printf "%-*s ⚙️ Compiling: $<..." $(PAD_WIDTH) "$(PROJECT)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	echo " ✅ "

$(LIBFT):	$(LIBDIR)-init
	printf "%-*s ⚙️ Building $(_LIBFT)...\n" $(PAD_WIDTH) "$(PROJECT)"
	$(MAKE) -C "$(LIBDIR)" --silent PAD_WIDTH=$(PAD_WIDTH)
	printf "%-*s ✅ $(_LIBFT) built.\n" $(PAD_WIDTH) "$(PROJECT)"

$(VISBIN):	$(VISDIR)-init
	printf "%-*s ⚙️ Building $(_VISBIN)...\n" $(PAD_WIDTH) "$(PROJECT)"
	mkdir -p "$(VBUILD)"
	cmake "$(VISDIR)" -B "$(VBUILD)" 2>&1 | sed 's/^/    /'
	$(MAKE) -C "$(VBUILD)" 2>&1 | sed 's/^/    /'
	printf "%-*s ✅ $(_VISBIN) built.\n" $(PAD_WIDTH) "$(PROJECT)"

$(VISLINK):	$(VISBIN)
	printf "%-*s 🔗 Symlinking $(_VISBIN) to $(VISLINK)..." $(PAD_WIDTH) "$(PROJECT)"
	ln -sf "$(VISBIN)" "$(VISLINK)"
	echo " ✅ "

-include $(OBJ:.o=.d)