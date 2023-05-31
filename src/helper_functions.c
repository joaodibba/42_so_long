/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/31 12:24:47 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
