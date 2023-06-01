/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 13:22:39 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (MLX_ERROR);
	render_map(vars);
	render_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->final_image.img, 0, 0);
	return (EXIT_SUCCESS);
}
