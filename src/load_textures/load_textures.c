/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:24:39 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 03:39:59 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	load_texture(t_vars	*vars)
{
	load_wall_texture(vars);
	load_pc_up_texture(vars);
	load_pc_down_texture(vars);
	load_pc_left_texture(vars);
	load_pc_right_texture(vars);
	load_map_exit_texture(vars);
	load_empty_space_texture(vars);
	load_collectibles_texture(vars);
	load_cone_texture(vars);
}

t_img	load_texture_to_img(t_vars *vars, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(vars->mlx, path, &img.width, \
	&img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}