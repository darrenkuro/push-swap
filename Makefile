# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlu <dlu@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 10:49:05 by dlu               #+#    #+#              #
#    Updated: 2025/12/28 13:25:39 by dlu              ###   ########.fr        #
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
OBJ		:=	$(addprefix $(OBJDIR)/,$(_SRC:.c=.o))
OBJ_B	:=	$(addprefix $(OBJDIR)/,$(_SRC_B:.c=.o))

LIBFT_A	:=	libft.a
LIBFT	:=	$(LIBDIR)/$(LIBFT_A)

VBUILD	:=	$(VISDIR)/build
_VISBIN	:=	visualizer
VISBIN	:=	$(VBUILD)/bin/$(_VISBIN)
VISLINK	:=	run-visualizer

# ------------------------ Toolchain & Flags
SHELL 		:=	/bin/bash
CC			:=	cc
RM			:=	rm -f
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
CPPFLAGS	:=	-I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
LDFLAGS		:=	-L $(LIBDIR)
LDLIBS		:=	-lft

# ------------------------ Build Settings
.DEFAULT_GOAL	:=	all

PAD		?=	11
PAD2	:=	10
DEBUG	?=	0

ifeq ($(DEBUG),1)
CFLAGS	+=	-g
endif

# ------------------------ Colors
RESET	:=	\033[0m
RED		:=	\033[31m
GREEN 	:=	\033[32m
GRAY 	:=	\033[90m

define log
printf "%-*s %-*s %s..." $(PAD) "[$(NAME)]" $(PAD2) "$(1)" "$(2)"
endef

define sublog
printf "\n$(GRAY)"; set -o pipefail; $(1) 2>&1 | sed 's/^/  - /' || exit $$$$?; printf "$(RESET)"
endef

define logok
printf " %b\n" "$(GREEN)[OK]$(RESET)"
endef

define logfail
printf " %b\n" "$(RED)[FAIL]$(RESET)"
endef

# ------------------------ Rules & Targets
define submodule-target
.PHONY:	$1-init
$1-init:
	@if git submodule status "$1" | grep -Eq '^[-+]'; then \
		$(call log,Initing:,Submodule $1); \
		$(call sublog,git submodule update --init --recursive $1) ; \
		$(call log,Initing:,Submodule $1); \
		$(call logok); \
	fi

.PHONY:	$1-deinit
$1-deinit:
	@if [ -f "$1/.git" ]; then \
		$(call log,Deiniting:,Submodule $1); \
		$(call sublog,git submodule deinit -f $1) ; \
		$(call log,Deiniting:,Submodule $1); \
		$(call logok); \
	fi

.PHONY: $1-update
$1-update:
	@if [ -f "$1/.git" ]; then \
		$(call log,Updating:,Submodule $1); \
		$(call sublog,git submodule update --remote --merge $1) ; \
		$(call log,Updating:,Submodule $1); \
		$(call logok); \
	else \
		$(call log,Updating:,Submodule $1); \
		$(call logfail); \
		printf "  - Try running '$1-init' first.\n"; \
	fi

.PHONY: $1-clean
$1-clean:
	@if [ -f "$1/Makefile" ]; then \
		$(MAKE) -C $1 clean PAD=$(PAD); \
	fi

.PHONY:	$1-fclean
$1-fclean:
	@if [ -f "$1/Makefile" ]; then \
		$(MAKE) -C $1 fclean PAD=$(PAD); \
	elif [ -d "$(VBUILD)" ]; then \
		$(call log,Removing:,$(VBUILD)/); \
		$(RM) -r "$(VBUILD)"; \
		$(call logok); \
		$(call log,Removing:,$(VISLINK)); \
		$(RM) "$(VISLINK)"; \
		$(call logok); \
	fi
endef

$(eval $(call submodule-target,$(LIBDIR)))	# Generate rules for libft
$(eval $(call submodule-target,$(VISDIR)))	# Generate rules for visualizer

# ------------------------ Rules & Targets
.PHONY:	all
all:	$(TARGET1) $(TARGET2) $(VISLINK)

.PHONY:	bonus
bonus:	$(TARGET2)

.PHONY:	clean
clean:	$(LIBDIR)-clean
	@if [ -d "$(OBJDIR)" ]; then \
		$(call log,Removing:,$(OBJDIR)/); \
		$(RM) -r "$(OBJDIR)"; \
		$(call logok); \
	fi

.PHONY:	fclean
fclean:	clean $(LIBDIR)-fclean $(VISDIR)-fclean $(LIBDIR)-deinit $(VISDIR)-deinit
	@if [ -f "$(TARGET1)" ]; then \
		$(call log,Removing:,$(TARGET1)); \
		$(RM) "$(TARGET1)"; \
		$(call logok); \
	fi
	@if [ -f "$(TARGET2)" ]; then \
		$(call log,Removing:,$(TARGET2)); \
		$(RM) "$(TARGET2)"; \
		$(call logok); \
	fi

.PHONY:	re
re:	fclean all

.PHONY:	var-%
var-%:
	@echo $($*)

$(OBJDIR):
	@$(call log,Creating:,$@/)
	@mkdir -p $@
	@$(call logok)

$(TARGET1):	$(LIBFT) $(OBJ)
	@$(call log,Building:,$@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)
	@$(call logok)

$(TARGET2):	$(LIBFT) $(OBJ_B)
	@$(call log,Building:,$@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJ_B) $(LDFLAGS) $(LDLIBS)
	@$(call logok)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	@$(call log,Compiling:,$(notdir $<))
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<
	@$(call logok)

$(LIBFT):	| $(LIBDIR)-init
	@$(call log,Building:,$(LIBFT_A))
	@$(MAKE) -C "$(LIBDIR)" --silent PAD=$(PAD)
	@$(call log,Building:,$(LIBFT_A))
	@$(call logok)

$(VISBIN):	| $(VISDIR)-init
	@$(call log,Building:,$(_VISBIN))
	@mkdir -p "$(VBUILD)"
	@$(call sublog,cmake "$(VISDIR)" -B "$(VBUILD)")
	@$(call sublog,$(MAKE) -C "$(VBUILD)")
	@$(call log,Building:,$(_VISBIN))
	@$(call logok)

$(VISLINK):	$(VISBIN)
	@$(call log,Symlinking:,$(_VISBIN) to $(VISLINK))
	@ln -sf "$(VISBIN)" "$(VISLINK)"
	@$(call logok)

.DELETE_ON_ERROR:	# Delete target build that's imcomplete
-include $(OBJ:.o=.d)
