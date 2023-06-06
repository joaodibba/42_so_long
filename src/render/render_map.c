/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:47:06 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 18:05:44 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	copy_image(t_img img, t_pos pos, t_img *final_img)
{
	t_pos			point;
	int				x;
	int				y;
	unsigned int	color;

	color = 0;
	point.y = 0;
	while (point.y < TILE_SIZE)
	{
		point.x = 0;
		while (point.x < TILE_SIZE)
		{
			color = get_pixel(&img, point.x, point.y);
			if (color && color != 4278190080)
				put_pixel(final_img, (pos.x * TILE_SIZE) + point.x, \
				(pos.y * TILE_SIZE) + point.y, (int)color);
			point.x++;
		}
		point.y++;
	}
}

void	put_sprite(t_vars *vars, t_pos pos, char c)
{
	copy_image(vars->map.empty_space, pos, &vars->final_image);
	if (c == WALL)
		copy_image(vars->map.wall, pos, &vars->final_image);
	else if (c == COLLECTIBLE)
		copy_image(vars->map.collectible, pos, &vars->final_image);
	else if (c == MAP_EXIT)
		copy_image(vars->map.map_exit, pos, &vars->final_image);
	else if (c == MAP_START)
		copy_image(vars->map.empty_space, pos, &vars->final_image);
	else if (c == PC_UP)
		copy_image(vars->map.pc_up, pos, &vars->final_image);
	else if (c == PC_DOWN)
		copy_image(vars->map.pc_down, pos, &vars->final_image);
	else if (c == PC_LEFT)
		copy_image(vars->map.pc_left, pos, &vars->final_image);
	else if (c == PC_RIGHT)
		copy_image(vars->map.pc_right, pos, &vars->final_image);
	else if (c == CONE)
		copy_image(vars->map.cone, pos, &vars->final_image);
}

void	render_map(t_vars *vars)
{
	t_pos	pos;
	char	current_sprite;

	pos.y = 0;
	while ((size_t)pos.y < vars->map.height)
	{
		pos.x = 0;
		while ((size_t)pos.x < vars->map.width)
		{
			current_sprite = vars->map.grid[(int)pos.y][(int)pos.x];
			put_sprite(vars, pos, current_sprite);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}
