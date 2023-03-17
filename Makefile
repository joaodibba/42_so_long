NAME		=    fdf
CC			=    gcc
FLAGS		=    -Wall -Wextra -Werror
MLX			=    minilibx-mac-osx/Makefile.gen
LFT			=    libft/libft.a
INC			=    -I ./libft -I ./minilibx-mac-osx
LIB			=    -L ./libft -lft -L ./minilibx-mac-osx -lmlx -framework OpenGL -framework AppKit
OBJ			=    $(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=    main.c

all:        $(MLX) $(LFT) obj $(NAME)

$(NAME):    $(OBJ)
            $(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
            @echo " [ .. ] | Compiling minilibx.."
            @make -s -C minilibx-mac-osx
            @echo " [ OK ] | Minilibx ready!"

$(LFT):
            @echo " [ .. ] | Compiling libft.."
            @make -s -C libft
            @echo " [ OK ] | Libft ready!"

obj:
            @mkdir -p obj

obj/%.o:    %.c
            $(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
            @make -s $@ -C libft
            @rm -rf $(OBJ) obj
            @echo "object files removed."

fclean:        clean
            @make -s $@ -C libft
            @rm -rf $(NAME)
            @echo "binary file removed."

re:            fclean all

.PHONY:        all clean fclean re