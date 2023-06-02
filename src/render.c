/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/02 01:24:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (MLX_ERROR);
	render_map(vars);
	if (vars->player.move.up == true)
	{
		move(&(vars->map), &(vars->player), 0, -1);
		vars->player.move.up = 0;
	}
	if (vars->player.move.down == true)
	{
		move(&(vars->map), &(vars->player), 0, 1);
		vars->player.move.down = 0;
	}
	if (vars->player.move.left == true)
	{
		move(&(vars->map), &(vars->player), -1, 0);
		vars->player.move.left = 0;
	}
	if (vars->player.move.right == true)
	{
		move(&(vars->map), &(vars->player), 1, 0);
		vars->player.move.right = 0;
	}
	render_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->final_image.img, 0, 0);
	char *str;
	char *str2;
	str = ft_itoa(vars->player.collectible_count);
	str2 = ft_strjoin("Ducks: ", str);
	mlx_string_put(vars->mlx, vars->win, 10, 10, RED_PIXEL, str2);
	return (EXIT_SUCCESS);
}
