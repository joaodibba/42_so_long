/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:56 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:42:41 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

//WINDOW SIZE
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

//ERROR CODES
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

//KEYCODES
# define ESCAPE 65307

//COLORS
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define WHITE_PIXEL 0XFFFFFF

typedef struct s_map
{
	char 	**map;
	char	*map_path;
}			t_map;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	*player;
	int			cur_img;
}				t_data;

#endif