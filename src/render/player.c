/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/13 14:45:03 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_player(t_vars *vars)
{
	copy_image(vars->player.img, vars->player.pos, &vars->final_image);
}

bool	is_obstacle(char grid_value)
{
	return (grid_value == WALL || grid_value == PC_UP || \
			grid_value == PC_DOWN || grid_value == PC_LEFT || \
			grid_value == PC_RIGHT || grid_value == CONE);
}

void	move(t_map *map, t_player *player, int x, int y)
{
	map->cone_pos = find_in_map(map->grid, CONE);
	if (is_obstacle(map->grid[player->pos.y + y][player->pos.x + x]) ||
	(map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT && \
	map->collectible_count != player->collectible_count))
		return ;
	if (map->grid[player->pos.y + y][player->pos.x + x] == \
		COLLECTIBLE && ++player->collectible_count)
	{
		map->grid[player->pos.y + y][player->pos.x + x] = EMPTY_SPACE;
		if (player->collectible_count == map->collectible_count)
			map->grid[map->cone_pos.y][map->cone_pos.x] = EMPTY_SPACE;
	}
	if (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT)
	{
		ft_printf("[ "PURPLE"GG"RESET" ] | You finished the map!\n" \
			"[ "PURPLE"GG"RESET" ] | Ducks collected: %d\n[ "PURPLE"GG"RESET, \
			player->collectible_count);
		ft_printf(" ] | Total steps: %d\n", ++player->move_count);
		exit(EXIT_SUCCESS);
	}
	player->pos.y += y;
	player->pos.x += x;
	player->move_count++;
}
