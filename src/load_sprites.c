/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 15:37:57 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_sprites(t_vars	*vars)
{
	//wall 
	vars->map.wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/WALL.xpm", &vars->map.wall.width, &vars->map.wall.height);
	vars->map.wall.addr = mlx_get_data_addr(vars->map.wall.img, &vars->map.wall.bpp, \
	&vars->map.wall.line_len, &vars->map.wall.endian);
	//pc_up
	vars->map.pc_up.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_UP.xpm", &vars->map.pc_up.width, &vars->map.pc_up.height);
	vars->map.pc_up.addr = mlx_get_data_addr(vars->map.pc_up.img, &vars->map.pc_up.bpp, \
	&vars->map.pc_up.line_len, &vars->map.pc_up.endian);
	//pc_down
	vars->map.pc_down.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_DOWN.xpm", &vars->map.pc_down.width, &vars->map.pc_down.height);
	vars->map.pc_down.addr = mlx_get_data_addr(vars->map.pc_down.img, \
	&vars->map.pc_down.bpp, &vars->map.pc_down.line_len, &vars->map.pc_down.endian);
	//pc_left
	vars->map.pc_left.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_LEFT.xpm", &vars->map.pc_left.width, &vars->map.pc_left.height);
	vars->map.pc_left.addr = mlx_get_data_addr(vars->map.pc_left.img, \
	&vars->map.pc_left.bpp, &vars->map.pc_left.line_len, &vars->map.pc_left.endian);
	//map_exit
	vars->map.map_exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/STAIRS.xpm", &vars->map.map_exit.width, &vars->map.map_exit.height);
	vars->map.map_exit.addr = mlx_get_data_addr(vars->map.map_exit.img, \
	&vars->map.map_exit.bpp, &vars->map.map_exit.line_len, &vars->map.map_exit.endian);
	//pc_right
	vars->map.pc_right.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_RIGHT.xpm", &vars->map.pc_right.width, &vars->map.pc_right.height);
	vars->map.pc_right.addr = mlx_get_data_addr(vars->map.pc_right.img, \
	&vars->map.pc_right.bpp, &vars->map.pc_right.line_len, &vars->map.pc_right.endian);
	//map_start
	vars->map.map_start.img = mlx_xpm_file_to_image(vars->mlx, \
	"2.xpm", &vars->map.map_start.width, &vars->map.map_start.height);
	vars->map.map_start.addr = mlx_get_data_addr(vars->map.map_start.img, \
	&vars->map.map_start.bpp, &vars->map.map_start.line_len, &vars->map.map_start.endian);
	//empty_space
	vars->map.empty_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/FLOOR.xpm", &vars->map.empty_space.width, \
	&vars->map.empty_space.height);
	vars->map.empty_space.addr = mlx_get_data_addr(vars->map.empty_space.img, \
	&vars->map.empty_space.bpp, &vars->map.empty_space.line_len, \
	&vars->map.empty_space.endian);
	//collectibles
	vars->map.collectible.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/DUCK.xpm", &vars->map.collectible.width, \
	&vars->map.collectible.height);
	vars->map.collectible.addr = mlx_get_data_addr(vars->map.collectible.img, \
	&vars->map.collectible.bpp, &vars->map.collectible.line_len, \
	&vars->map.collectible.endian);
	//cone
	vars->map.cone.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/CONE.xpm", &vars->map.cone.width, &vars->map.cone.height);
	vars->map.cone.addr = mlx_get_data_addr(vars->map.cone.img, &vars->map.cone.bpp, \
	&vars->map.cone.line_len, &vars->map.cone.endian);
}
