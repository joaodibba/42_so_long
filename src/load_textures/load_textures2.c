/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:22:27 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 20:58:56 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_pc_up_texture(t_vars *vars)
{
	vars->map.pc_up = load_texture_to_img(vars, "textures/XPM/PC_UP.xpm");
}

void	load_pc_down_texture(t_vars *vars)
{
	vars->map.pc_down = load_texture_to_img(vars, "textures/XPM/PC_DOWN.xpm");
}

void	load_pc_left_texture(t_vars *vars)
{
	vars->map.pc_left = load_texture_to_img(vars, "textures/XPM/PC_LEFT.xpm");
}

void	load_pc_right_texture(t_vars *vars)
{
	vars->map.pc_right = load_texture_to_img(vars, "textures/XPM/PC_RIGHT.xpm");
}

void	load_player_texture(t_vars *vars)
{
	vars->player.img = load_texture_to_img(vars, \
	"textures/PLAYER/XPM/NORMAL/1.xpm");
}
