/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/25 22:29:38 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_sprites(t_vars	*vars)
{
	//wall 
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/WALL.xpm", &vars->wall.width, &vars->wall.height);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bpp, \
	&vars->wall.line_len, &vars->wall.endian);
	//pc_up
	vars->pc_up.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_UP.xpm", &vars->pc_up.width, &vars->pc_up.height);
	vars->pc_up.addr = mlx_get_data_addr(vars->pc_up.img, &vars->pc_up.bpp, \
	&vars->pc_up.line_len, &vars->pc_up.endian);
	//pc_down
	vars->pc_down.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_DOWN.xpm", &vars->pc_down.width, &vars->pc_down.height);
	vars->pc_down.addr = mlx_get_data_addr(vars->pc_down.img, \
	&vars->pc_down.bpp, &vars->pc_down.line_len, &vars->pc_down.endian);
	//pc_left
	vars->pc_left.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_LEFT.xpm", &vars->pc_left.width, &vars->pc_left.height);
	vars->pc_left.addr = mlx_get_data_addr(vars->pc_left.img, \
	&vars->pc_left.bpp, &vars->pc_left.line_len, &vars->pc_left.endian);
	//map_exit
	vars->map_exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/STAIRS.xpm", &vars->map_exit.width, &vars->map_exit.height);
	vars->map_exit.addr = mlx_get_data_addr(vars->map_exit.img, \
	&vars->map_exit.bpp, &vars->map_exit.line_len, &vars->map_exit.endian);
	//pc_right
	vars->pc_right.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_RIGHT.xpm", &vars->pc_right.width, &vars->pc_right.height);
	vars->pc_right.addr = mlx_get_data_addr(vars->pc_right.img, \
	&vars->pc_right.bpp, &vars->pc_right.line_len, &vars->pc_right.endian);
	//map_start
	vars->map_start.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/STAIRS.xpm", &vars->map_start.width, &vars->map_start.height);
	vars->map_start.addr = mlx_get_data_addr(vars->map_start.img, \
	&vars->map_start.bpp, &vars->map_start.line_len, &vars->map_start.endian);
	//empty_space
	vars->empty_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/FLOOR.xpm", &vars->empty_space.width, \
	&vars->empty_space.height);
	vars->empty_space.addr = mlx_get_data_addr(vars->empty_space.img, \
	&vars->empty_space.bpp, &vars->empty_space.line_len, \
	&vars->empty_space.endian);
	//collectibles
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/DUCK.xpm", &vars->collectible.width, \
	&vars->collectible.height);
	vars->collectible.addr = mlx_get_data_addr(vars->collectible.img, \
	&vars->collectible.bpp, &vars->collectible.line_len, \
	&vars->collectible.endian);
	//cone
	vars->cone.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/CONE.xpm", &vars->cone.width, &vars->cone.height);
	vars->cone.addr = mlx_get_data_addr(vars->cone.img, &vars->cone.bpp, \
	&vars->cone.line_len, &vars->cone.endian);
}
