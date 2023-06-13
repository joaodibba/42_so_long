/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:03:11 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/12 12:24:38 by jalves-c         ###   ########.fr       */
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
