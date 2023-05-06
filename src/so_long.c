/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:17:33 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	arguments_check(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf("\033[0;31m [Error] ./so_long <PATH/TO/MAP.ber>.\n\033[0m");
		return (FALSE);
	}
	else if (map_check(av[1]))
	{
		ft_printf("\033[0;31m [Error] <%s> is not a valid <PATH/TO/MAP.ber>.\n\033[0m", av[1]);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (arguments_check(ac, av) != TRUE)
		return (EXIT_FAILURE);
	if (map_validator(&map) != TRUE)
		return (EXIT_FAILURE);
	read_map(av[1], &map);
	free_map(map.map);
	free(map.map_path);
	return (EXIT_SUCCESS);
}
