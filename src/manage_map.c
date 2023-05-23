/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/18 17:46:28 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
		free(grid[i++]);
	free(grid);
}

void	map_error(t_map *map)
{
	ft_printf("[ " RED"!!"RESET " ] | " \
			"%s is not a valid map.\n", map->map_path);
	free_map(map->grid);
	free(map->map_path);
	exit(EXIT_FAILURE);
}

t_map	duplicate_map(t_map map)
{
	t_map	map_copy;
	size_t	i;

	map_copy.grid = malloc((map.rows + 1) * sizeof(char *));
	i = 0;
	while (i < map.rows)
	{
		map_copy.grid[i] = malloc(map.cols * sizeof(char));
		ft_memcpy(map_copy.grid[i], map.grid[i], map.cols);
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
