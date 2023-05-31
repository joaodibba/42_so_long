NAME  = so_long
OS    = $(shell uname)
CC    = @gcc
FLAGS = -g -fsanitize=address
LFT   = include/libft/libft.a
INC   = -I./include/libft -I./include/mlx -I./include/mlx_macos -I/opt/X11/include
SRC   = $(wildcard src/*.c)
OBJ   = $(patsubst src/%.c, obj/%.o, $(SRC))

ifeq ($(OS), Darwin)
    MLX = ./include/mlx_macos/libmlx.a
    LIB = -L./include/libft -lft -L./include/mlx_macos -lmlx -framework OpenGL -framework AppKit
else
    MLX = include/mlx/libmlx.a
    LIB = -L./include/libft -lft -L./include/mlx -lmlx -lXext -lX11

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
	@make -sC include/mlx_macos > /dev/null 2>&1
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
	@make -sC include/libft clean
	@make -sC include/mlx_macos clean > /dev/null
	@rm -rf $(OBJ) obj
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
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
	@make re -s && ./so_long maps/bocal.ber

cluster1:
	@make re -s && ./so_long maps/cluster1.ber

cluster2:
	@make re -s && ./so_long maps/cluster2.ber

.PHONY: all
