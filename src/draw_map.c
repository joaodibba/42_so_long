/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:47:06 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/24 20:53:05 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_vars *vars)
{
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	
	while (pos.y < vars->window_height)
	{
		while (pos.x < vars->window_width)
		{
			if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == WALL)
				put_sprite(vars, pos, WALL);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == EMPTY_SPACE)
				put_sprite(vars, pos, EMPTY_SPACE);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == COLLECTIBLE)
				put_sprite(vars, pos, COLLECTIBLE);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == MAP_EXIT)
				put_sprite(vars, pos, MAP_EXIT);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == MAP_START)
				put_sprite(vars, pos, MAP_START);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_UP)
				put_sprite(vars, pos, PC_UP);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_DOWN)
				put_sprite(vars, pos, PC_DOWN);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_LEFT)
				put_sprite(vars, pos, PC_LEFT);
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_RIGHT)
				put_sprite(vars, pos, PC_RIGHT);
			pos.x += TILE_SIZE;
		}
		pos.x = 0;
		pos.y += TILE_SIZE;
	}	
}

void	put_sprite(t_vars *vars, t_pos pos, char c)
{
	if (c == WALL)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->wall.img, pos.x, pos.y);
	else if (c == EMPTY_SPACE)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->empty_space.img, pos.x, pos.y);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->collectible.img, pos.x, pos.y);
	else if (c == MAP_EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->map_exit.img, pos.x, pos.y);
	else if (c == MAP_START)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->map_start.img, pos.x, pos.y);
	else if (c == PC_UP)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->pc_up.img, pos.x, pos.y);
	else if (c == PC_DOWN)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->pc_down.img, pos.x, pos.y);
	else if (c == PC_LEFT)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->pc_left.img, pos.x, pos.y);
	else if (c == PC_RIGHT)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->pc_right.img, pos.x, pos.y);
}