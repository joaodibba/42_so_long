/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:39:05 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 18:09:27 by jalves-c         ###   ########.fr       */
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

int	handle_key_release(int key, t_vars *vars)
{
	if (key == W || key == UP)
		vars->player.move.up = 0;
	if (key == S || key == DOWN)
		vars->player.move.down = 0;
	if (key == A || key == LEFT)
		vars->player.move.left = 0;
	if (key == D || key == RIGHT)
		vars->player.move.right = 0;
	return (EXIT_SUCCESS);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
