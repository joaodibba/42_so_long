/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:43:07 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:14:27 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_map_size(t_map *map)
{
	size_t	x_size;
	size_t	y_size;

	x_size = 0;
	y_size = 0;
	if (!map || !map->grid)
		return ;
	x_size = ft_strlen(map->grid[0]);
	if (x_size == 0)
		return ;
	while (map->grid[y_size] != 0)
		y_size++;
	if (y_size == 0)
		return ;
	map->width = x_size;
	map->height = y_size;
}

bool	validate_map(t_vars *vars)
{	
	ft_printf("[ "YELLOW".."RESET \
	" ] | Validating map...\n");
	get_map_size(&(vars->map));
	if (map_is_rectangular(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" is not rectangular.\n", vars->map.map_path))
		return (false);
	if (map_content_is_valid(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" content is unknown.\n", vars->map.map_path))
		return (false);
	if (map_is_closed(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" is not closed by walls.\n", vars->map.map_path) != 0)
		return (false);
	if (map_valid_path_checker(&(vars->map)) != true && \
		ft_printf("[ " RED"!!"RESET " ] | " \
		RED"%s"RESET" has no valid path.\n", vars->map.map_path) != 0)
		return (false);
	return (true);
}
