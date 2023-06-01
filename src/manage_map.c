/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 17:16:08 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	size_t	i;

	map_copy.grid = malloc((map.height + 1) * sizeof(char *));
	i = 0;
	while (i < map.width)
	{
		map_copy.grid[i] = malloc(map.width * sizeof(char));
		ft_memcpy(map_copy.grid[i], map.grid[i], map.width);
		i++;
	}
	map_copy.grid[i] = 0;
	return (map_copy);
}

void	print2darray(char **arr, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows - 1)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			printf("%c ", arr[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

void find_map_start(t_map *map, t_player *player)
{
    int x;
    int y;

    x = 0;
    while (x < map->height - 1)
    {
        y = 0;
        while (y < map->width - 1)
        {
            if (map->grid[y][x] == MAP_START)
            {
                player->pos.y = y;
                player->pos.x = x;
            }
            y++;
        }
        x++;
    }
}
