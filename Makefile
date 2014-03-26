#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 18:01:32 by mde-jesu          #+#    #+#              #
#    Updated: 2014/02/25 12:46:49 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh
SRC = main.c \
	builtins.c \
	ft_prompt.c

LIBSH = ./libsh/libsh.a
SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes -I./libsh/includes
LIB_CALL = -L./libsh -lsh

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -pedantic-errors

ifeq ($(W),)
	CC = gcc
	CFLAGS += -O3
else
	CC = clang
	CFLAGS += -ggdb3 -fstack-protector-all -Wshadow -Wunreachable-code \
			-Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
			-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes -pedantic \
			-Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement \
			-Wold-style-definition -Wmissing-field-initializers -Wfloat-equal \
			-Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common \
			-Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
			-Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer
endif

LD = $(CC)

OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(LIBSH) $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(OBJS_PREF)
	@$(LD) -o $@ $^ $(LIB_CALL) $(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(LIBSH):
	@( $(MAKE) all -C ./libsh)

clean-ft:
	@( $(MAKE) clean -C ./libsh )

fclean-ft:
	@( $(MAKE) fclean -C ./libsh )

re-ft: fclean-ft $(LIBSH)

.PHONY: clean fclean re all clean-ft fclean-ft re-ft
