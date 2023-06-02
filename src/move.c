/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:25 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/02 01:36:43 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move(t_map *map, t_player *player, int x, int y)
{
	if (map->grid[player->pos.y + y][player->pos.x + x] == WALL || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_UP || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_DOWN || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_LEFT || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_RIGHT || \
		map->grid[player->pos.y + y][player->pos.x + x] == CONE)
		return ;
	if (map->grid[player->pos.y + y][player->pos.x + x] == COLLECTIBLE)
	{
		player->collectible_count++;
		map->grid[player->pos.y + y][player->pos.x + x] = EMPTY_SPACE;
		if (player->collectible_count == map->collectible_count)
			map->grid[map->cone_pos.y][map->cone_pos.x] = EMPTY_SPACE;
	}
	if (map->grid[player->pos.y + y][player->pos.x + x] == MAP_EXIT)
		exit(EXIT_SUCCESS);
	player->pos.y += y;
	player->pos.x += x;
}
