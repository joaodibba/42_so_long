/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/13 15:29:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_error(t_map *map)
{
	ft_printf("[ " RED"!!"RESET " ] | " \
			RED"%s"RESET" is not a valid map.\n", map->map_path);
	ft_free_matrix(map->grid);
	free(map->map_path);
	exit(EXIT_FAILURE);
}

char	**duplicate_map(t_map *map)
{
	char	**grid;
	size_t	index;

	grid = malloc((map->height + 1) * sizeof(char *));
	if (!grid)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < map->height)
	{
		grid[index] = ft_strdup(map->grid[index]);
		if (!grid[index])
		{
			ft_free_matrix(grid);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	grid[index] = 0;
	return (grid);
}

t_pos	find_in_map(char **map, char stuff)
{
	t_pos	point;

	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == stuff)
				return ((t_pos){point.x, point.y});
			point.x++;
		}
		point.y++;
	}
	return ((t_pos){0, 0});
}
