/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:47:06 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/23 21:37:58 by jalves-c         ###   ########.fr       */
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
			
			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == EMPTY_SPACE)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == COLLECTIBLE)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == MAP_EXIT)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == MAP_START)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_UP)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_DOWN)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_LEFT)

			else if (vars->map.grid[pos.y / TILE_SIZE][pos.x / TILE_SIZE] == PC_RIGHT)
				
			pos.x += TILE_SIZE;
		}
		pos.x = 0;
		pos.y += TILE_SIZE;
	}	
}

void	put_sprite(t_vars *vars, t_pos pos, char c)
{
	if (c == WALL)
		mlx_put_image_to_window()
}