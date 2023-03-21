# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:37:19 by jalves-c          #+#    #+#              #
#    Updated: 2023/03/20 11:58:10 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFLAGS		= -Wall -Werror -Wextra -O3 -g
INCLUDE		= -I include
LIBFTDIR	= includes/libft
LIBFT		= $(LIBFTDIR)/libft.a
LFLAGS		= -L${LIBFTDIR} -lft
UNAME		:= $(shell uname)

ifeq ($(UNAME), Darwin)
		LIBMLXDIR	= includes/minilibx-mac-osx
		LIBMLX		= $(LIBMLXDIR)/libmlx.a
		CC			= gcc
		LFLAGS		+= -L$(LIBMLXDIR) -lmlx -framework OpenGL -framework AppKit
else
		LIBMLXDIR	= includes/minilibx-linux
		LIBMLX		= $(LIBMLXDIR)/libmlx.a
		CC			= gcc
		LFLAGS		+= -L$(LIBMLXDIR) -lmlx -lbsd -lXext -lX11 -lm
endif

SRC_DIR		= src
SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(SRC:%.c=%.o)

BONUS_DIR	= bonus
BONUS_SRC	= $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJ	= $(BONUS_SRC:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(LIBMLX)
			$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LFLAGS) -o $(NAME)
			@echo "\033[0;32m$(NAME) successfully compiled!\033[0;32m"

$(LIBFT):
			make -C $(LIBFTDIR)

$(LIBMLX):
			make -C $(LIBMLXDIR)

bonus:		$(BONUS_OBJ) $(LIBFT) $(LIBMLX)
			$(CC) $(CFLAGS) $(BONUS_OBJ) $(INCLUDE) $(LFLAGS) -o $(NAME)
			@echo "\033[0;32m$(NAME) bonus successfully compiled!\033[0;32m"

test:
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) maps/bigmap_bonus.ber

clean:
			@make clean -C $(LIBFTDIR)
			@make clean -C $(LIBMLXDIR)
			rm -rf $(OBJ)
			rm -rf $(BONUS_OBJ)
			rm -rf valgrind-out.txt

fclean:		clean
			rm -rf $(LIBFT)
			rm -rf $(LIBMLX)
			rm -rf $(NAME)
			@echo "\033[0;33mso_long executable, libraries, and object files successfully deleted!\033[0;33m"

re: 		fclean all

rebonus:	fclean	bonus

.PHONY: 	re all clean fclean

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC			: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"