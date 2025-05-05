# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 17:35:09 by abaldelo          #+#    #+#              #
#    Updated: 2025/05/05 21:21:42 by abaldelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude -g

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# Necesario para que funcione readline/readline.h y readline/history.h
LIBS 		= -lreadline

# Encuentra todos los archivos .c en src/ y subcarpetas 
# Reemplazar una vez terminado el proyecto (no está permitido 😞)
SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all:  $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo "📚 Compilando libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LIBFT_A)
	@echo "✅ Compilación completa."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️  Compilando $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "🧹 Objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🧨 Binario eliminado."

norm:
	@echo "Checking norminette..."
	@OUTPUT=$$(norminette $(SRC_DIR)/ $(INC_DIR)/ $(LIBFT_DIR)/); \
	echo "$$OUTPUT" | grep -v "OK!" || true; \
	if echo "$$OUTPUT" | grep -q "Error:"; then \
		echo "❌ Norminette found errors."; \
	else \
		echo "✅ Norma OK!"; \
	fi

re: fclean all

.PHONY: all clean fclean re
