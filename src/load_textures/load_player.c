/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:28:30 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 17:48:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// static void	load_player_up(t_vars *vars)
// {
// 	vars->player.walk_up[1] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/UP/1.xpm");
// 	vars->player.walk_up[2] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/UP/2.xpm");
// 	vars->player.walk_up[3] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/UP/3.xpm");
// 	vars->player.walk_up[4] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/UP/4.xpm");
// }

// static void	load_player_down(t_vars *vars)
// {
// 	vars->player.walk_down[1] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/DOWN/1.xpm");
// 	vars->player.walk_down[2] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/DOWN/2.xpm");
// 	vars->player.walk_down[3] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/DOWN/3.xpm");
// 	vars->player.walk_down[4] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/DOWN/4.xpm");
// }

// static void	load_player_left(t_vars *vars)
// {
// 	vars->player.walk_left[1] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/LEFT/1.xpm");
// 	vars->player.walk_left[2] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/LEFT/2.xpm");
// 	vars->player.walk_left[3] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/LEFT/3.xpm");
// 	vars->player.walk_left[4] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/LEFT/4.xpm");
// }

// static void	load_player_right(t_vars *vars)
// {
// 	vars->player.walk_right[1] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/RIGHT/1.xpm");
// 	vars->player.walk_right[2] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/RIGHT/2.xpm");
// 	vars->player.walk_right[3] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/RIGHT/3.xpm");
// 	vars->player.walk_right[4] = load_texture_to_img(vars, \
// 	"textures/PLAYER/XPM/RIGHT/4.xpm");
// }

void	load_player(t_vars *vars)
{
	vars->player.img = load_texture_to_img(vars, \
	"textures/PLAYER/XPM/NORMAL/1.xpm");
	// load_player_up(vars);
	// load_player_down(vars);
	// load_player_left(vars);
	// load_player_right(vars);
}