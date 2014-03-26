#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 16:13:36 by cheron            #+#    #+#              #
#    Updated: 2014/03/05 15:10:37 by npineau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS =
RM = @rm -rf

LIBFT_DIR = ./libft

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = 42sh

OBJ_DIR = obj
SRC_DIR = srcs

SRC =	$(addprefix squel/, \
				main.c \
				clone.c \
				ft_minishell.c \
				ft_print_error.c \
				ft_prompt.c) \
		$(addprefix builtins/, \
				ft_echo.c \
				ft_exit.c \
				ft_env.c \
				ft_cd.c \
				ft_cd2.c \
				ft_setenv.c \
				ft_unsetenv.c)

OBJ = $(SRC:.c=.o)

POBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(OBJ)))

COMPILE = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "\nCompilation of objects for "$(LIBFT)
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(COMPILE) $(LIBFT)
	@echo "\nLinking "$(NAME)""
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(POBJ) \
	-L$(LIBFT_DIR) -lft -I$(INCLUDES_DIR)
	@echo "\n\033[1;36mdone\033[0m"

clean:
	@echo "\nCleaning OBJ"
	$(RM) $(POBJ)

fclean: clean
	@echo "\nCleaning "$(NAME)""
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $(OBJ_DIR)/$(notdir $@) -I $(INCLUDES_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean
