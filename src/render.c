/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/23 20:17:44 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->win_ptr == NULL)
		return (MLX_ERROR);
	//render_background(vars, &vars->img, WHITE_PIXEL);
	// mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
	// 							vars->img.mlx_img, 0, 0);
	return (0);
}

void	render_background(t_vars *vars, t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->window_height)
	{
		j = 0;
		while (j < vars->window_width)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
