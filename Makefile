# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 09:59:41 by kelickel          #+#    #+#              #
#    Updated: 2014/03/27 14:42:53 by kelickel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	42sh

SRCS =	free_double.c \
		main.c \
		builtins.c \
		ft_history.c \
		ft_unsetenv.c \
		ft_atoi.c \
		ft_putendl.c \
		ft_putstr.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strstockintab.c \
		get_next_line.c \
		ft_exec.c \
		ft_system.c \
		path.c \
		new_str.c

IFLAGS = -Wall -Wextra -Werror -Iincludes -g

CC = gcc $(IFLAGS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Creation de l'executable \033[1;34m$(NAME)\033[0m"
		$(CC) -o $(NAME) $(OBJS)

%.o: srcs/%.c includes/ft_sh.h
	$(CC) -c $^

clean:
		@echo "Remove \033[1;30m$(O)\033[0m"
		rm -f $(OBJS)

fclean:	clean
		@echo "Remove \033[1;31m$(NAME)\033[0m"
		rm -f $(NAME)

re: fclean all
