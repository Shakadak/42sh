#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 18:01:32 by mde-jesu          #+#    #+#              #
#    Updated: 2014/02/25 12:45:15 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libsh.a
SRC_FT = ft_atoi.c \
		ft_putstr_fd.c \
		ft_strcmp.c \
		ft_strsub.c \
		ft_strsplit.c

SRC_GNL = get_next_line.c

SRC = $(SRC_FT) $(SRC_GNL)

SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes

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

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(OBJS_PREF)
	@ar rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
