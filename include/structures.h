/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/08 18:53:51 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_flood
{
	bool			exit_reached;
	unsigned int	collectibles_collected;
}	t_flood;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_map
{
	char			**grid;
	char			*map_path;
	size_t			height;
	size_t			width;
	unsigned int	wall_count;
	unsigned int	pc_count;
	unsigned int	collectible_count;
	unsigned int	empty_space_count;
	unsigned int	map_exit_count;
	unsigned int	map_start_count;
	unsigned int	cone_count;
	t_img			wall;
	t_img			empty_space;
	t_img			map_exit;
	t_img			map_start;
	t_img			pc_up;
	t_img			pc_down;
	t_img			pc_left;
	t_img			pc_right;
	t_img			collectible;
	t_img			cone;
	t_pos			cone_pos;
	t_flood			flood;
}				t_map;

typedef struct s_move
{
	int			up;		
	int			down;
	int			left;
	int			right;
}					t_move;

typedef struct s_player
{
	t_img			img;
	t_pos			pos;
	t_move			move;
	unsigned int	collectible_count;
	unsigned int	move_count;
}					t_player;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	win_height;
	unsigned int	win_width;
	t_map			map;
	t_player		player;
	t_img			final_image;
}					t_vars;

#endif