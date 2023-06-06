/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 03:40:36 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_player(t_vars *vars)
{
	copy_image(vars->player.img, vars->player.pos, &vars->final_image);
}
