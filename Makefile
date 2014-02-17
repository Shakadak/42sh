# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 09:59:41 by kelickel          #+#    #+#              #
#    Updated: 2014/02/17 16:10:42 by croy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	42sh

SRCS =	main.c \
		builtins.c \
		ft_atoi.c \
		ft_strcmp.c \
		get_next_line.c \
		ft_strsplit.c \
		ft_putstr_fd.c \
		ft_prompt.c

IFLAGS = -Wall -Wextra -Werror -Iincludes

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
