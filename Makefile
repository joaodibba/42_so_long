# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 16:38:57 by jalves-c          #+#    #+#              #
#    Updated: 2023/06/13 16:20:34 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long
OS    = $(shell uname)
CC    = @cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan
LFT   = include/libft/libft.a
INC   = -I./include/libft -I./include/mlx -I./include/mlx_macos
SRC   = src/load_textures/load_textures.c \
		src/load_textures/load_textures1.c \
		src/load_textures/load_textures2.c \
		src/map/read_map.c \
		src/map/flood_fill.c \
		src/map/validate_map.c \
		src/map/validations.c \
		src/render/pixel.c \
		src/render/render_map.c \
		src/render/player.c \
		src/render/render.c \
		src/helper_functions.c \
		src/helper_functions1.c \
		src/so_long.c 

OBJ   = $(patsubst src/%.c, obj/%.o, $(SRC))

ifeq ($(OS), Darwin)
    MLX = ./include/mlx_macos/libmlx.a
	INC_MLX = include/mlx_macos
    LIB = -L./include/libft -lft -L./include/mlx_macos -lmlx -framework OpenGL -framework AppKit
else
    MLX = include/mlx/libmlx.a
	INC_MLX = include/mlx
    LIB = -L./include/libft -lft -L./include/mlx -lmlx -lXext -lX11
endif

# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

all: $(MLX) $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	$(CC) $(FLAGS) -o $@ $^ $(LIB)
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

$(MLX):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling minilibx..."
	@make -sC $(INC_MLX) > /dev/null 2>&1
	@echo "[" "$(GREEN)OK$(RESET)" "] | Minilibx ready!"

$(LFT):
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling libft..."
	@make -sC include/libft
	@echo "[" "$(GREEN)OK$(RESET)" "] | Libft ready!"

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@make -sC include/libft clean
	@make -sC $(INC_MLX) clean > /dev/null
	@rm -rf $(OBJ) obj
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@make -sC include/libft fclean
	@rm -rf $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

norm:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Running Norminette...$(RESET)"
	@if norminette src include/macros.h iclude/so_long.h include/structures.h | grep -q "Error!"; then \
	    echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
	    norminette src include/macros.h iclude/so_long.h include/structures.h | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	else \
	    echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	fi

re: fclean norm all

# MAPS
bocal:
	@make re -s && ./so_long assets/maps/bocal.ber
	
bocalonsteroids:
	@make re -s && ./so_long assets/maps/bocal_on_steroids.ber

cluster1:
	@make re -s && ./so_long assets/maps/cluster1.ber

cluster1onsteroids:
	@make re -s && ./so_long assets/maps/cluster1_on_steroids.ber
	
cluster2:
	@make re -s && ./so_long assets/maps/cluster2.ber

cluster2onsteroids:
	@make re -s && ./so_long assets/maps/cluster2_on_steroids.ber

.PHONY: all