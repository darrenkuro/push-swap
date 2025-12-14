# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2025/06/22 09:57:22 by dlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------ Project Metadata
NAME	:=	push-swap
TARGET1	:=	push_swap
TARGET2	:=	checker

# ------------------------ Directories
SRCDIR	:=	src
OBJDIR	:=	obj
INCDIR	:=	include
LIBDIR	:=	libft
VISDIR	:=	visualizer

# ------------------------ Files
_SRC	:=	push_swap.c input.c utils.c op_exec1.c op_exec2.c op_exec3.c \
			sort.c optimize_rr.c optimize_rrr.c optimize_op.c \
			utils_calc.c utils_limit.c utils_rotate.c utils_rotate_count.c
_SRC_B	:=	checker_bonus.c input.c op_exec1.c op_exec2.c op_exec3.c utils.c
SRC		:=	$(addprefix $(SRCDIR)/,$(_SRC))
SRC_B	:=	$(addprefix $(SRCDIR)/,$(_SRC_B))
_OBJ	:=	$(_SRC:.c=.o)
_OBJ_B	:=	$(_SRC_B:.c=.o)
OBJ		:=	$(addprefix $(OBJDIR)/,$(_OBJ))
OBJ_B	:=	$(addprefix $(OBJDIR)/,$(_OBJ_B))

LIBFT_A	:=	libft.a
LIBFT	:=	$(LIBDIR)/$(LIBFT_A)

VBUILD	:=	$(VISDIR)/build
_VISBIN	:=	visualizer
VISBIN	:=	$(VBUILD)/bin/$(_VISBIN)
VISLINK	:=	run-visualizer

# ------------------------ Toolchain & Flags
CC			:=	cc
RM			:=	rm -f
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

# ------------------------ Build Settings
.DEFAULT_GOAL	:=	all

PAD		?=	11
DEBUG	?=	0
ifeq ($(DEBUG),1)
	CFLAGS	+=	-g
endif

# ------------------------ Rules & Targets
define submodule-target
.PHONY:	$1-init
$1-init:
	@if git submodule status "$1" | grep -Eq '^[-+]'; then \
		printf "%-*s 🔄 Initializing submodule $1...\n" $$(PAD) "[$$(NAME)]"; \
		set -o pipefail; git submodule update --init --recursive $1 2>&1 | \
		sed 's/^/    - /' || exit $$?; \
		printf "%-*s ✅ Git submodule $1 initialized.\n" $$(PAD) "[$$(NAME)]"; \
	fi

.PHONY:	$1-deinit
$1-deinit:
	if [ -f "$1/.git" ]; then \
		printf "%-*s 🧹 Deinitializing $1 submodule...\n" \
		$$(PAD) "[$$(NAME)]"; \
		set -o pipefail; git submodule deinit -f $1 2>&1 | \
		sed 's/^/    - /' || exit $$?; \
		printf "%-*s ✅ Git submodule $1 deinitialized.\n" \
		$$(PAD) "[$$(NAME)]"; \
	fi

.PHONY: $1-update
$1-update:
	if [ -f "$1/.git" ]; then \
		printf "%-*s ⬆️  Pulling latest commits for submodule $1...\n" \
		$$(PAD) "[$$(NAME)]"; \
		set -o pipefail; git submodule update --remote --merge $1 2>&1 | sed 's/^/    - /' || exit $$?; \
			printf "%-*s ✅ $1 submodule updated to latest commit.\n" $$(PAD) "[$$(NAME)]"; \
	else \
		printf "%-*s ⚠️ $1 submodule not initialized. Run '$1-init' first.\n" $$(PAD) "[$$(NAME)]"; \
	fi
endef

$(eval $(call submodule-target,$(LIBDIR)))	# Generate rules for libft
$(eval $(call submodule-target,$(VISDIR)))	# Generate rules for visualizer

# ------------------------ Rules & Targets
.PHONY:	all
all:	$(TARGET1) $(TARGET2) $(VISLINK)

.PHONY:	bonus
bonus:	$(TARGET2)

.PHONY:	$(LIBDIR)-clean
$(LIBDIR)-clean:
	@if [ -f $(LIBDIR)/Makefile ]; then \
		$(MAKE) -C $(LIBDIR) clean PAD=$(PAD); \
	fi

.PHONY:	clean
clean:	$(LIBDIR)-clean
	@if [ -d $(OBJDIR) ]; then \
		printf "%-*s 🧹 Removing $(OBJDIR)/..." $(PAD) "[$(NAME)]"; \
		$(RM) -r $(OBJDIR); \
		echo " ✅ "; \
	fi

.PHONY:	$(LIBDIR)-fclean
$(LIBDIR)-fclean:
	@if [ -f "$(LIBDIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBDIR) fclean PAD=$(PAD); \
	fi

.PHONY:	$(VISDIR)-fclean
$(VISDIR)-fclean:
	@if [ -d $(VBUILD) ]; then \
		printf "%-*s 🧹 Removing build files, binary, and symlink for visualizer..." \
		$(PAD) "[$(NAME)]"; \
		$(RM) -r $(VBUILD); \
		$(RM) "$(VISLINK)"; \
		echo " ✅ "; \
	fi

.PHONY:	fclean
fclean:	clean $(LIBDIR)-fclean $(VISDIR)-fclean $(LIBDIR)-deinit $(VISDIR)-deinit
	@if [ -f "$(TARGET1)" ] || [ -f "$(TARGET2)" ]; then \
		printf "%-*s 🗑️ Removing binaries..." $(PAD) "[$(NAME)]"; \
		$(RM) $(TARGET1) $(TARGET2); \
		echo " ✅ "; \
	fi

.PHONY:	re
re:	fclean all

.PHONY:	var-%
var-%:
	@echo $($*)

$(OBJDIR):
	@printf "%-*s 📁 Creating obj directory..." $(PAD) "[$(NAME)]"
	@mkdir -p $@
	@echo " ✅ "

$(TARGET1):	$(LIBFT) $(OBJ)
	@printf "%-*s 🛠️ Building binary: $@" $(PAD) "[$(NAME)]"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)
	@echo " ✅ "

$(TARGET2):	$(LIBFT) $(OBJ_B)
	@printf "%-*s 🛠️ Building binary: $@" $(PAD) "[$(NAME)]"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ_B) $(LDFLAGS) $(LDLIBS)
	@echo " ✅ "

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	@printf "%-*s ⚙️ Compiling: $<..." $(PAD) "[$(NAME)]"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@echo " ✅ "

$(LIBFT):	| $(LIBDIR)-init
	@printf "%-*s ⚙️ Building $(LIBFT_A)...\n" $(PAD) "[$(NAME)]"
	@$(MAKE) -C "$(LIBDIR)" --silent PAD=$(PAD)
	@printf "%-*s ✅ $(LIBFT_A) built.\n" $(PAD) "[$(NAME)]"

$(VISBIN):	| $(VISDIR)-init
	@printf "%-*s ⚙️ Building $(_VISBIN)...\n" $(PAD) "[$(NAME)]"
	@mkdir -p "$(VBUILD)"
	@set -o pipefail; cmake "$(VISDIR)" -B "$(VBUILD)" 2>&1 | sed 's/^/    /'
	@set -o pipefail; $(MAKE) -C "$(VBUILD)" 2>&1 | sed 's/^/    /'
	@printf "%-*s ✅ $(_VISBIN) built.\n" $(PAD) "[$(NAME)]"

$(VISLINK):	$(VISBIN)
	@printf "%-*s 🔗 Symlinking $(_VISBIN) to $(VISLINK)..." $(PAD) "[$(NAME)]"
	@ln -sf "$(VISBIN)" "$(VISLINK)"
	@echo " ✅ "

.DELETE_ON_ERROR:	# Delete target build that's imcomplete
-include $(OBJ:.o=.d)
