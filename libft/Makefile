#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 07:55:52 by abaldelo          #+#    #+#              #
#    Updated: 2025/05/01 17:54:29 by abaldelo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a
CC		= cc
CFLAGS  = -Wall -Werror -Wextra -Iinclude
AR		= ar rcs

SRCDIR  = src
OBJDIR  = obj

GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
BOLD	= \033[1m
RESET	= \033[0m

SRC		= src/ft_atoi.c src/ft_atoll.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c\
		src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_isspace.c src/ft_memchr.c src/ft_memcmp.c\
		src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_strchr.c src/ft_strdup.c\
		src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c src/ft_strcmp.c src/ft_strnstr.c\
		src/ft_strrchr.c src/ft_tolower.c src/ft_toupper.c src/ft_substr.c src/ft_strjoin.c\
		src/ft_strtrim.c src/ft_split.c src/ft_free_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c\
		src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/get_next_line.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)[DIR]$(RESET) Carpeta 'obj/' creada."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(BLUE)[CC]$(RESET) Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(YELLOW)[AR]$(RESET) Creando biblioteca $(NAME)..."
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[OK]$(RESET) Biblioteca $(NAME) lista."

clean:
	@rm -f $(OBJS)
	@echo "$(RED)[CLEAN]$(RESET) Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[FCLEAN]$(RESET) Biblioteca eliminada."

re: fclean all

.PHONY: all fclean clean re
