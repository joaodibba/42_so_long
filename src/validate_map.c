/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:57:36 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/18 15:25:26 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//isto não faz check do mapa e não deve ser boolean
bool	map_size_check(t_map *map)
{
	size_t	x_size;
	size_t	y_size;

	x_size = 0;
	y_size = 0;
	if (!map || !map->grid)
		return (false);
	x_size = ft_strlen(map->grid[0]);
	if (x_size == 0)
		return (false);
	while (map->grid[y_size] != 0)
		y_size++;
	if (y_size == 0)
		return (false);
	map->cols = x_size;
	map->rows = y_size;
	return (true);
}

bool	map_is_rectangular(t_map *map)
{
	size_t	y;

	y = 0;
	if (!map || !map->grid || map->cols == map->rows)
		return (false);
	y = 0;
	while (y < map->rows)
		if (map->cols != ft_strlen(map->grid[y++]))
			return (false);
	return (true);
}

bool	map_content_count(t_map *map, char c)
{
	if (c == WALL)
		return (++map->wall);
	else if (c == PC_UP || c == PC_DOWN || c == PC_LEFT || c == PC_RIGHT)
		return (++map->pc);
	else if (c == COLLECTIBLE)
		return (++map->collectible);
	else if (c == EMPTY_SPACE)
		return (++map->empty_space);
	else if (c == MAP_EXIT)
		return (++map->map_exit);
	else if (c == MAP_START)
		return (++map->map_start);
	return (false);
}

bool	map_content_is_valid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->wall = 0;
	map->pc = 0;
	map->collectible = 0;
	map->empty_space = 0;
	map->map_exit = 0;
	map->map_start = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (!map_content_count(map, map->grid[y][x]))
				return (false);
			x++;
		}
		y++;
	}
	return (map->wall > 0 && map->pc > 0 && map->collectible > 0 && \
			map->empty_space > 0 && map->map_exit == 1 && map->map_start == 1);
}

bool	map_is_closed(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->rows)
	{
		if (map->grid[y][x] != '1' || map->grid[y][map->cols - 1] != '1')
			return (false);
		y++;
	}
	while (x < map->cols)
	{
		if (map->grid[0][x] != '1' || map->grid[map->rows - 1][x] != '1')
			return (false);
		x++;
	}
	return (true);
}
