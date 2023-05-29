/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:47:06 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/29 23:10:28 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_map(t_vars *vars)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < vars->map.height)
	{
		while (pos.x < vars->map.width)
		{
			if (vars->map.grid[pos.y][pos.x] == WALL)
				put_sprite(vars, pos, WALL);
			else if (vars->map.grid[pos.y][pos.x] == EMPTY_SPACE)
				put_sprite(vars, pos, EMPTY_SPACE);
			else if (vars->map.grid[pos.y][pos.x] == COLLECTIBLE)
				put_sprite(vars, pos, COLLECTIBLE);
			else if (vars->map.grid[pos.y][pos.x] == MAP_EXIT)
				put_sprite(vars, pos, MAP_EXIT);
			else if (vars->map.grid[pos.y][pos.x] == MAP_START)
				put_sprite(vars, pos, MAP_START);
			else if (vars->map.grid[pos.y][pos.x] == PC_UP)
				put_sprite(vars, pos, PC_UP);
			else if (vars->map.grid[pos.y][pos.x] == PC_DOWN)
				put_sprite(vars, pos, PC_DOWN);
			else if (vars->map.grid[pos.y][pos.x] == PC_LEFT)
				put_sprite(vars, pos, PC_LEFT);
			else if (vars->map.grid[pos.y][pos.x] == PC_RIGHT)
				put_sprite(vars, pos, PC_RIGHT);
			else if (vars->map.grid[pos.y][pos.x] == CONE)
				put_sprite(vars, pos, CONE);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}	
}

void	copy_image(t_img img, t_pos pos, t_img *final_img)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	color = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			color = get_pixel(&img, x, y);
			if (color && color != 4278190080)
				put_pixel(final_img, (pos.x * TILE_SIZE) + x, \
				(pos.y * TILE_SIZE) + y, (int)color);
			x++;
		}
		y++;
	}
}

void	put_sprite(t_vars *vars, t_pos pos, char c)
{
	if (c != PC_DOWN && c != PC_LEFT && c != PC_RIGHT && c != PC_UP)
		copy_image(vars->empty_space, pos, &vars->final_image);
	if (c == WALL)
		copy_image(vars->wall, pos, &vars->final_image);
	if (c == COLLECTIBLE)
		copy_image(vars->collectible, pos, &vars->final_image);
	if (c == MAP_EXIT)
		copy_image(vars->map_exit, pos, &vars->final_image);
	if (c == MAP_START)
		copy_image(vars->map_start, pos, &vars->final_image);
	if (c == PC_UP)
		copy_image(vars->pc_up, pos, &vars->final_image);
	if (c == PC_DOWN)
		copy_image(vars->pc_down, pos, &vars->final_image);
	if (c == PC_LEFT)
		copy_image(vars->pc_left, pos, &vars->final_image);
	if (c == PC_RIGHT)
		copy_image(vars->pc_right, pos, &vars->final_image);
	if (c == CONE)
		copy_image(vars->cone, pos, &vars->final_image);
}
