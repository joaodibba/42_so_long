/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:17:37 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/23 17:26:13 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
int	window_height(void)
{
	vars();
	vars->window_height = vars->map.rows * TILE_SIZE;
	return (vars->window_height);
}

int	window_width(void)
{
	vars();
	vars->window_width = vars->map.cols * TILE_SIZE;
	return (vars->window_width);
}
*/

void	free_win(t_vars *vars)
{
	if (vars->win_ptr)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		vars->win_ptr = NULL;
	}
	if (vars->mlx_ptr)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
	}
}
