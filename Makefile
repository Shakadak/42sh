#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 16:13:36 by cheron            #+#    #+#              #
#    Updated: 2014/02/26 18:39:03 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -03
RM = @rm -rf

LIBFT_DIR = ./libft

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = 42sh

OBJ_DIR = obj
SRC_DIR = srcs/

SRC = 	$(addprefix squel/, \
				main.c \
				ft_cpenv.c \
				ft_minishell.c \
				ft_print_error.c \
				ft_prompt.c) \
		$(addprefix builtins/, \
				ft_builtins.c \
				ft_cd.c \
				ft_cd2.c \
				ft_setenv.c \
				ft_unsetenv.c)

OBJ = $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "\nCompilation of objects for "$(LIBFT)
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(POBJ) $(LIBFT)
	@echo "\nLinking "$(NAME)""
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $^ \
	-L$(LIBFT_DIR) -lft -I$(INCLUDES_DIR)
	@echo "\n\x1b[32;01mdone!\x1b[0m"

clean:
	@echo "\nCleaning OBJ"
	$(RM) $(POBJ)

fclean: clean
	@echo "\nCleaning "$(NAME)""
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean
