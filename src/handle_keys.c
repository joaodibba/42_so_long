/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:39:05 by jalves-c          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/31 15:19:16 by jalves-c         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 20:27:10 by jalves-c         ###   ########.fr       */
>>>>>>> parent of 0520e9d... upgraded key handler
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keys(int keysym, t_vars *vars)
{
<<<<<<< HEAD
	if (key == XK_Escape)
=======
	if (keysym == ESCAPE)
>>>>>>> parent of 0520e9d... upgraded key handler
		close_window(vars);
	return (EXIT_SUCCESS);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
