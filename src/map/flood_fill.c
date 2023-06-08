/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:40:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/08 20:17:00 by jalves-c         ###   ########.fr       */
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
	if (map->grid[y][x] == COLLECTIBLE)
	{
		++map->flood.collectibles_collected;
		map->grid[y][x] = MAP_START;
		return (1);
	}
	if (map->grid[y][x] == EMPTY_SPACE)
	{
		map->grid[y][x] = MAP_START;
		return (1);
	}
	if (map->grid[y][x] == MAP_EXIT || \
		map->grid[y][x] == CONE)
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
	find_in_map(vars, MAP_START);
	if (!map_copy.grid)
		return (false);
	map_copy.flood.collectibles_collected = 0;
	flood((t_pos){map->height, map->width}, vars->player.pos.y, \
	vars->player.pos.x, &map_copy);
	if (map_copy.flood.collectibles_collected != vars->map.collectible_count)
		return (false);
	ft_free_matrix(map_copy.grid);
	return (map_copy.flood.exit_reached);
}
