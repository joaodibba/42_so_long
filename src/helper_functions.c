/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:03:11 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:34:58 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_key(int key, t_vars *vars)
{
	if (key == ESCAPE)
		close_window(vars);
	if (key == W || key == UP)
		vars->player.move.up = 1;
	if (key == S || key == DOWN)
		vars->player.move.down = 1;
	if (key == A || key == LEFT)
		vars->player.move.left = 1;
	if (key == D || key == RIGHT)
		vars->player.move.right = 1;
	return (EXIT_SUCCESS);
}

int	close_window(t_vars *vars)
{
	ft_printf("[ " RED "XX" RESET " ] |" \
		" You exited the game before finishing :(\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	zero_map_count(t_map *map)
{
	map->wall_count = 0;
	map->pc_count = 0;
	map->collectible_count = 0;
	map->empty_space_count = 0;
	map->map_exit_count = 0;
	map->map_start_count = 0;
	map->cone_count = 0;
}