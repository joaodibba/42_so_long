/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:25:22 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/18 17:27:11 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_vars	*vars(void)
{
	static t_vars	vars;

	return (&vars);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}