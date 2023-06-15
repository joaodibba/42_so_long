/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:40:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/15 16:44:47 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	fill(int y, int x, t_map *map)
{
	if (x >= (int)map->width || y >= (int)map->height || x < 0 || y < 0)
		return (false);
	if (map->grid[y][x] == EMPTY_SPACE)
	{
		map->grid[y][x] = WALL;
		return (true);
	}
	if (map->grid[y][x] == COLLECTIBLE)
	{
		++map->flood.collectibles_collected;
		map->grid[y][x] = WALL;
		return (true);
	}
	if (map->grid[y][x] == MAP_EXIT)
		map->flood.exit_reached = true;
	return (false);
}

void	flood(int y, int x, t_map *map)
{
	if (fill(y, x - 1, map))
		flood(y, x - 1, map);
	if (fill(y, x + 1, map))
		flood(y, x + 1, map);
	if (fill(y - 1, x, map))
		flood(y - 1, x, map);
	if (fill(y + 1, x, map))
		flood(y + 1, x, map);
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
	flood(start_pos.y, start_pos.x, &map_copy);
	if (map->collectible_count != map_copy.flood.collectibles_collected)
	{
		ft_free_matrix(map_copy.grid);
		return (false);
	}
	ft_free_matrix(map_copy.grid);
	return (map_copy.flood.exit_reached);
}
