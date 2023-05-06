# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:29:34 by jalves-c          #+#    #+#              #
#    Updated: 2023/05/06 03:10:08 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	@gcc
FLAGS	=	-Wall -Wextra -Werror -fsanitize=address 
LFT		=	libft/libft.a
MLX 	=	minilibx-linux/libmlx.a
INC		=	-I ./libft -I ./minilibx-linux
LIB		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
SRC		=	$(wildcard src/*.c)
OBJ		= 	$(patsubst src/%.c,obj/%.o,$(SRC))

#COLORS
RED =		\033[0;31m
GREEN =		\033[0;32m
YELLOW =	\033[0;33m
RESET =		\033[0m


all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo "$(YELLOW) [ .. ] | Compiling minilibx...$(RESET)"
			@make -s -C minilibx-linux
			@echo "$(GREEN) [ OK ] | Minilibx ready!$(RESET)"

$(LFT):		
			@echo "$(YELLOW) [ .. ] | Compiling libft...$(RESET)"
			@make -s -C libft
			@echo "$(GREEN) [ OK ] | Libft ready!$(RESET)"

obj:
			@mkdir -p obj

obj/%.o: 	src/%.c
			@mkdir -p $(dir $@)
			$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -sC libft clean
			@make -sC minilibx-linux clean
			@rm -rf $(OBJ) obj
			@echo "$(GREEN) [ OK ] | Object files removed.$(RESET)"

fclean:		clean
			@make -sC libft fclean
			@rm -rf $(NAME)
			@echo "$(GREEN) [ OK ] | binary file removed.$(RESET)"

re:			fclean all #add norm before all

norm :
			norminette src include
			@echo "$(GREEN) [ OK ] | Norminette.$(RESET)"

.PHONY:		all clean fclean re

