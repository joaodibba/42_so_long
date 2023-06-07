/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:40:01 by jalves-c         ###   ########.fr       */
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

t_map	duplicate_map(t_map map)
{
	t_map	map_copy;
	size_t	index;

	map_copy.grid = malloc((map.height + 1) * sizeof(char *));
	index = 0;
	while (index < map.height)
	{
		map_copy.grid[index] = malloc(map.width * sizeof(char));
		ft_memcpy(map_copy.grid[index], map.grid[index], map.width);
		index++;
	}
	map_copy.grid[index] = NULL;
	return (map_copy);
}

void	find_in_map(t_vars *vars, char stuff)
{
	t_pos	point;

	point.y = 0;
	while (vars->map.grid[point.y])
	{
		point.x = 0;
		while (vars->map.grid[point.y][point.x])
		{
			if (vars->map.grid[point.y][point.x] == stuff)
			{
				if (stuff == MAP_START)
				{
					vars->player.pos = (t_pos){point.x, point.y};
					break ;
				}
				if (stuff == CONE)
				{
					vars->map.cone_pos = (t_pos){point.x, point.y};
					break ;
				}
			}
			point.x++;
		}
		point.y++;
	}
}

void	initialize_player(t_player *player)
{
	player->collectible_count = 0;
	player->move_count = 0;
}
