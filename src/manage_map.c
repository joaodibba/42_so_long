/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 22:44:28 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}


void	map_error(t_map *map)
{
	ft_printf(RED "[Error] <%s> IS NOT A VALID MAP.\n" \
			RESET, map->map_path);
	free_map(map->map);
	free(map->map_path);
	exit(EXIT_FAILURE);
}

t_map	duplicate_map(t_map map)
{
	t_map	map_copy;
	size_t	i;

	map_copy.map = malloc((map.rows + 1) * sizeof(char *));
	i = 0;
	while (i < map.rows)
	{
		map_copy.map[i] = malloc(map.cols * sizeof(char));
		ft_memcpy(map_copy.map[i], map.map[i], map.cols);
		i++;
	}
	map_copy.map[i] = 0;
	return (map_copy);
}
