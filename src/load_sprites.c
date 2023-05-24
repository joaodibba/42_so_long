/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/24 21:48:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_sprites(t_vars	*vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/WALL.xpm", &vars->wall.w, &vars->wall.h);
	vars->pc_up.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/PC_UP.xpm", &vars->pc_up.w, &vars->pc_up.h);
	vars->pc_down.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/PC_DOWN.xpm", &vars->pc_down.w, &vars->pc_down.h);
	vars->pc_left.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/PC_LEFT.xpm", &vars->pc_left.w, &vars->pc_left.h);
	vars->map_exit.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/STAIRS.xpm", &vars->map_exit.w, &vars->map_exit.h);
	vars->pc_right.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/PC_RIGHT.xpm", &vars->pc_right.w, &vars->pc_right.h);
	vars->map_start.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/STAIRS.xpm", &vars->map_start.w, &vars->map_start.h);
	vars->empty_space.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/FLOOR.xpm", &vars->empty_space.w, &vars->empty_space.h);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, "textures/XPM/DUCK.xpm", &vars->collectible.w, &vars->collectible.h);
}