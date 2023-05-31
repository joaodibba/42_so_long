/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:39:05 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/31 15:19:16 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keys(int key, t_vars *vars)
{
	if (key == XK_Escape)
		close_window(vars);
	if (key == UP || key == W)
		vars->keys.up = 1;
	if (key == DOWN || key == S)
		vars->keys.down = 1;
	if (key == LEFT || key == A)
		vars->keys.left = 1;
	if (key == RIGHT || key == D)
		vars->keys.right = 1;
	return (EXIT_SUCCESS);
}

int	handle_key_release(int key, t_vars *vars)
{
	if (key == UP || key == W)
		vars->keys.up = 0;
	if (key == DOWN || key == S)
		vars->keys.down = 0;
	if (key == LEFT || key == A)
		vars->keys.left = 0;
	if (key == RIGHT || key == D)
		vars->keys.right = 0;
	return (EXIT_SUCCESS);
}