/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/25 04:51:06 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_sprites(t_vars	*vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/WALL.xpm", &vars->wall.width, &vars->wall.height);
	vars->pc_up.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_UP.xpm", &vars->pc_up.width, &vars->pc_up.height);
	vars->pc_down.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_DOWN.xpm", &vars->pc_down.width, &vars->pc_down.height);
	vars->pc_left.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_LEFT.xpm", &vars->pc_left.width, &vars->pc_left.height);
	vars->map_exit.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/STAIRS.xpm", &vars->map_exit.width, &vars->map_exit.height);
	vars->pc_right.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/PC_RIGHT.xpm", &vars->pc_right.width, &vars->pc_right.height);
	vars->map_start.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/STAIRS.xpm", &vars->map_start.width, &vars->map_start.height);
	vars->empty_space.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/FLOOR.xpm", &vars->empty_space.width, \
	&vars->empty_space.height);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/DUCK.xpm", &vars->collectible.width, \
	&vars->collectible.height);
	vars->cone.img = mlx_xpm_file_to_image(vars->mlx, \
	"textures/XPM/CONE.xpm", &vars->cone.width, &vars->cone.height);
}
