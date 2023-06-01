/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 18:19:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <time.h>
#include <sys/time.h>

void get_fps()
{
	struct timeval time;
	static int frames;
	static int second;

	gettimeofday(&time, NULL);
	if (second != time.tv_sec)
	{
		second = time.tv_sec;
		printf("FPS: %d\n", frames);
		frames = 0;
	}
	else
		frames++;
}

int	render(t_vars *vars)
{
	get_fps();
	if (vars->win == NULL)
		return (MLX_ERROR);
	//render_map(vars);
	if (vars->player.move.right == true)
		move(&(vars->map), &(vars->player), 1, 0);
	render_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->final_image.img, 0, 0);
	return (EXIT_SUCCESS);
}
