/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:39:05 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/23 20:11:52 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keys(int keysym, t_vars *vars)
{
	if (keysym == ESCAPE)
		close_window(vars);
	return (EXIT_SUCCESS);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit (0);
}
