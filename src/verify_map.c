/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:45:59 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:31:54 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_check(char *path_to_map)
{
	size_t	len;

	len = ft_strlen(path_to_map);
	if (len < 5 || ft_strcmp(path_to_map + len - 4,".ber") != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	get_map_dimensions(t_map	*map)
{
	map->rows = sizeof(map->map) / sizeof(char *);
	map->cols = ft_strlen(map->map[0]);
}

bool	map_validator(t_map *map)
{
	(void)map;
	return (true);
}

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