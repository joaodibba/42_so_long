/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/24 21:04:00 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_sprites(t_vars	*vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/WALL.xpm", TILE_SIZE, TILE_SIZE);
	vars->pc_up.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/PC_UP.xpm", TILE_SIZE, TILE_SIZE);
	vars->pc_down.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/PC_DOWN.xpm", TILE_SIZE, TILE_SIZE);
	vars->pc_left.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/PC_LEFT.xpm", TILE_SIZE, TILE_SIZE);
	vars->map_exit.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/STAIRS.xpm", TILE_SIZE, TILE_SIZE);
	vars->pc_right.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/PC_RIGHT.xpm", TILE_SIZE, TILE_SIZE);
	vars->map_start.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/STAIRS.xpm", TILE_SIZE, TILE_SIZE);
	vars->empty_space.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/FLOOR.xpm", TILE_SIZE, TILE_SIZE);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, "/textures/XPM/DUCK.xpm", TILE_SIZE, TILE_SIZE);
}