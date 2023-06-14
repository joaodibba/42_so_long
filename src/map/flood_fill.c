/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:40:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/14 16:07:30 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	fill(t_pos pos, int y, int x, t_map *map)
{
	if (x >= pos.x || y >= pos.y || x < 0 || y < 0)
		return (0);
	if (map->grid[y][x] == EMPTY_SPACE)
	{
		map->grid[y][x] = WALL;
		return (1);
	}
	if (map->grid[y][x] == COLLECTIBLE)
	{
		++map->flood.collectibles_collected;
		map->grid[y][x] = WALL;
		return (1);
	}
	if (map->grid[y][x] == MAP_EXIT)
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

bool	map_valid_path_checker(t_map *map)
{
	static t_map	map_copy;
	t_pos			start_pos;

	map_copy = *map;
	map_copy.flood.exit_reached = false;
	map_copy.grid = duplicate_map(map);
	start_pos = find_in_map(map_copy.grid, MAP_START);
	if (!map_copy.grid)
		return (false);
	flood((t_pos){map->height, map->width}, start_pos.y, \
	start_pos.x, &map_copy);
	ft_print_matrix(map_copy.grid);
	ft_free_matrix(map_copy.grid);
	return (map_copy.flood.exit_reached);
}
