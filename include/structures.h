/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:56:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/18 19:30:05 by jalves-c         ###   ########.fr       */
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
	size_t			rows;
	size_t			cols;
	unsigned int	wall;
	unsigned int	pc;
	unsigned int	collectible;
	unsigned int	empty_space;
	unsigned int	map_exit;
	unsigned int	map_start;
}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_pos			player_pos;
	t_flood			flood;
	t_img			img;
	unsigned int	window_height;
	unsigned int	window_width;
}				t_vars;

#endif