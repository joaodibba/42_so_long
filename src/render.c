/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/24 21:49:31 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_vars *vars)
{
	 if (vars->win == NULL)
	 	return (MLX_ERROR);
	draw_map(vars);
	//mlx_put_image_to_window(vars->mlx, vars->win,vars->pc_right.img, 64, 64);
	return (EXIT_SUCCESS);
}
