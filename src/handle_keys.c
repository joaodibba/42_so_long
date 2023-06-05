/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:39:05 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/05 15:40:07 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_key(int key, t_vars *vars)
{
	if (key == ESCAPE)
	{
		ft_printf("[ " RED "XX" RESET " ] |" \
		" You exited the game before finishing :(\n");
		close_window(vars);
	}
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
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
