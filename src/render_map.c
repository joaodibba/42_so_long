/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:47:06 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/25 19:42:13 by jalves-c         ###   ########.fr       */
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
	int x;
	int y;
	unsigned int color;

	y = 0;
	color = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			color = my_mlx_pixel_get(&img, x, y);
			if (color)
				my_mlx_pixel_put(final_img, (pos.x * TILE_SIZE) + x, (pos.y * TILE_SIZE) + y, (int)color);
			x++;
		}
		y++;
	}
}

void	put_sprite(t_vars *vars, t_pos pos, char c)
{
	if (c == WALL)
		copy_image(vars->wall, pos, &vars->final_image);
	else if (c != WALL)
		copy_image(vars->empty_space, pos, &vars->final_image);
	// else if (c == COLLECTIBLE)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->collectible.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == MAP_EXIT)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->map_exit.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == MAP_START)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->map_start.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == PC_UP)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->pc_up.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == PC_DOWN)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->pc_down.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == PC_LEFT)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->pc_left.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	// else if (c == PC_RIGHT)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 	vars->pc_right.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	if (c == CONE)
		copy_image(vars->cone, pos, &vars->final_image);
}
