/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:25 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 19:36:49 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move(t_map *map, t_player *player, int x , int y)
{
	if (map->grid[player->pos.y + y][player->pos.x + x] == WALL || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_UP || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_DOWN || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_LEFT || \
		map->grid[player->pos.y + y][player->pos.x + x] == PC_RIGHT)
			return ;
	if (map->grid[player->pos.y + y][player->pos.x + x] == COLLECTIBLE)
		map->collectible_count--;
		player->pos.y += y;
		player->pos.x += x;
}
