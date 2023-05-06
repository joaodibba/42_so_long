/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/06 19:07:02 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	map_error(t_map *map)
{
	ft_printf("\033[0;31m [Error] <%s> IS NOT A VALID MAP.ber>.\n\033[0m", map->map_path);
	free_map(map->map);
	free(map->map_path);
	exit(EXIT_FAILURE);
}
	
void get_map_dimensions(t_map *map)
{
	size_t	x;
	size_t	y;

	if(!map->map)
	{
		map_error(map);
		return ;
	}
	map->cols = ft_strlen(map->map[0]);
	y = 0;
	while(map->map[y])
	{
		if(map->map[y] != 0)
			y++;
	}
	if(!y)
		map->cols = y;
}

bool	map_validator(t_map *map)
{
	//get_map_dimensions(map);
	ft_printf("colunas %d", map->cols);
	ft_printf("linhas %d", map->rows);
	(void)map;
	return (true);
}