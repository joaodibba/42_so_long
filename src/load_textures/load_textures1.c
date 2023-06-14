/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:38:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/14 16:12:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_map_exit_texture(t_vars *vars)
{
	vars->map.map_exit = load_texture_to_img(vars, \
	"assets/textures/XPM/STAIRS.xpm");
}

void	load_empty_space_texture(t_vars *vars)
{
	vars->map.empty_space = load_texture_to_img(vars, \
	"assets/textures/XPM/FLOOR.xpm");
}

void	load_collectibles_texture(t_vars *vars)
{
	vars->map.collectible = load_texture_to_img(vars, \
	"assets/textures/XPM/DUCK.xpm");
}

void	load_wall_texture(t_vars *vars)
{
	vars->map.wall = load_texture_to_img(vars, \
	"assets/textures/XPM/WALL.xpm");
}
