/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:40:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/08 00:49:57 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	fill(t_pos pos, int y, int x, t_map *map)
{
	if (x >= pos.x || y >= pos.y || x < 0 || y < 0)
		return (0);
	if (map->grid[y][x] == WALL || map->grid[y][x] == PC_UP || \
		map->grid[y][x] == PC_DOWN || map->grid[y][x] == PC_LEFT || \
		map->grid[y][x] == PC_RIGHT)
		return (0);
	if (map->grid[y][x] == EMPTY_SPACE || map->grid[y][x] == COLLECTIBLE)
	{
		map->grid[y][x] = MAP_START;
		return (1);
	}
	if (map->grid[y][x] == CONE)
		map->flood.exit_reached = true;
	return (0);
}

void	flood(t_pos size, int y, int x, t_map *map)
{
	if (fill(size, y, x - 1, map))
		flood(size, y, x - 1, map);
	if (fill(size, y, x + 1, map))
		flood(size, y, x + 1, map);
	if (fill(size, y - 1, x, map))
		flood(size, y - 1, x, map);
	if (fill(size, y + 1, x, map))
		flood(size, y + 1, x, map);
}

bool	map_valid_path_checker(t_vars *vars, t_map *map)
{
	t_map	map_copy;

	map_copy.flood.exit_reached = false;
	map_copy = duplicate_map(vars->map);
	if (!map_copy.grid)
		return (false);
	flood((t_pos){map->height, map->width}, 2, 2, &map_copy);
	ft_free_matrix(map_copy.grid);
	return (map_copy.flood.exit_reached);
}
