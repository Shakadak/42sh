# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 09:59:41 by kelickel          #+#    #+#              #
#    Updated: 2014/03/25 16:33:59 by kelickel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	42sh

SRCS =	builtins.c ft_exec.c ft_strcat.c ft_strdup.c ft_strnew.c ft_system.c get_next_line.c path.c \
		ft_atoi.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_strsplit.c ft_unsetenv.c main.c putendl.c \
		free_double.c

IFLAGS = -Wall -Wextra -Werror -g

CC = gcc $(IFLAGS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Creation de l'executable \033[1;34m$(NAME)\033[0m"
		$(CC) -o $(NAME) $(OBJS)

%.o: srcs/%.c includes/sh.h
	$(CC) -c $<

clean:
		@echo "Remove \033[1;30m$(O)\033[0m"
		rm -f $(OBJS)

fclean:	clean
		@echo "Remove \033[1;31m$(NAME)\033[0m"
		rm -f $(NAME)

re: fclean all
