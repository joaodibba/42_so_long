/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/25 01:55:34 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (MLX_ERROR);
	render_map(vars);
	return (EXIT_SUCCESS);
}
