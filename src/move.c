/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:25 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 15:38:32 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_player(t_vars *vars)
{
	static t_pos	pos;

	while ((size_t)pos.y < vars->map.height)
	{
		while ((size_t)pos.x < vars->map.width)
		{
			if (vars->map.grid[pos.y][pos.x] == MAP_START)
			{
				copy_image(vars->map.map_start, pos, &vars->final_image);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}	
}