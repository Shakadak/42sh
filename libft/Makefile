#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2014/02/21 14:30:07 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
NAME = libft.a
INCLUDES_DIR = includes/
RM = @rm -rf
AR = ar -crus

SRC = ft_memset.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_isascii.c \
ft_isalpha.c ft_lstmap.c \
ft_isprint.c ft_bzero.c  ft_memcpy.c ft_putchar.c ft_putnbr.c ft_putstr.c  \
ft_memset.c ft_memccpy.c ft_memmove.c ft_memcmp.c ft_strcpy.c  ft_strlen.c \
ft_strncpy.c ft_tolower.c ft_toupper.c ft_memchr.c ft_strdup.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_strstr.c ft_strnstr.c ft_strncmp.c ft_strcmp.c ft_isspace.c \
get_next_line.c ft_strfjoin.c ft_free_tab.c ft_fatal.c ft_count_char.c

OBJ = $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_DIR)/, $(OBJ))

SRC_DIR = srcs
OBJ_DIR = obj

CFLAGS = -Wall -Werror -Wextra
OFLAGS = -O3


all: $(OBJ_DIR) $(NAME)

$(NAME): $(POBJ) $(INCLUDES_DIR)libft.h
	@echo "\nCreating archive "$(NAME)
	@$(AR) $(NAME) $(POBJ)

clean:
	@echo "\nCleaning Object Files in libft"
	$(RM) $(POBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "\nCleaning "$(NAME)"\n"

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -I $(INCLUDES_DIR) -c $< -o $@
	@echo "\x1b[32;01m.\x1b[0m\c"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean
