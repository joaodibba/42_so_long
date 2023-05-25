/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/25 04:33:13 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_flood
{
	bool	exit_reached;
	bool	collectibles_collected;
}	t_flood;

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
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			map;
	t_flood			flood;
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
	unsigned int	window_height;
	unsigned int	window_width;
}				t_vars;

#endif