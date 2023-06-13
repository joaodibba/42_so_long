/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:57:36 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/13 14:46:02 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	map_is_rectangular(t_map *map)
{
	size_t	y;

	y = 0;
	if (!map || !map->grid || map->width == map->height)
		return (false);
	y = 0;
	while (y < map->height)
		if (map->width != ft_strlen(map->grid[y++]))
			return (false);
	return (true);
}

bool	map_content_count(t_map *map, char c)
{
	if (c == WALL)
		return (++map->wall_count);
	else if (c == PC_UP || c == PC_DOWN || c == PC_LEFT || c == PC_RIGHT)
		return (++map->pc_count);
	else if (c == COLLECTIBLE)
		return (++map->collectible_count);
	else if (c == EMPTY_SPACE)
		return (++map->empty_space_count);
	else if (c == MAP_EXIT)
		return (++map->map_exit_count);
	else if (c == MAP_START)
		return (++map->map_start_count);
	else if (c == CONE)
		return (++map->cone_count);
	return (false);
}

bool	map_content_is_valid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
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
	return (map->wall_count > 0 && map->pc_count > 0 \
			&& map->collectible_count > 0 && map->empty_space_count > 0 && \
			map->map_exit_count == 1 && map->map_start_count == 1 && \
			map->cone_count == 1);
}

bool	map_is_closed(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][x] != '1' || map->grid[y][map->width - 1] != '1')
			return (false);
		y++;
	}
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			return (false);
		x++;
	}
	return (true);
}
