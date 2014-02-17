# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 09:59:41 by kelickel          #+#    #+#              #
#    Updated: 2014/02/17 11:39:45 by kelickel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c builtins.c ft_atoi.c ft_strcmp.c get_next_line.c ft_strsplit.c

NAME = 42sh

IFLAGS = -Wall -Wextra -Werror

CC = gcc $(IFLAGS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
