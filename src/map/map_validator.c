/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:43:07 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 16:55:50 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

//verificar se dá merda
bool	map_validator(t_vars *vars)
{	
	ft_printf("[ " YELLOW ".." RESET \
	" ] | Validating map...\n");
	get_map_size(&(vars->map));
	if (map_is_rectangular(&(vars->map)) != true || \
		map_content_is_valid(&(vars->map)) != true || \
		map_is_closed(&(vars->map)) != true)
		return (false);
	return (true);
}
	/*if (map_valid_path_checker(vars, &(vars->map)) != true)
		return (false);*/