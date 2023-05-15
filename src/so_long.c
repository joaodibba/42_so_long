/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 23:05:32 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	path_to_map_check(const char *path_to_map)
{
	size_t	len;

	len = ft_strlen(path_to_map);
	if (len < 5 || ft_strncmp(path_to_map + (len - 4), ".ber", 4) == 0)
		return (true);
	return (false);
}

bool	arguments_check(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf(RED "Error] ./so_long <PATH/TO/MAP.ber>.\n" RESET);
		return (false);
	}
	if (path_to_map_check(av[1]) == false)
	{
		ft_printf(RED "[Error] <%s> is not a valid <PATH/TO/MAP.ber>.\n" \
				RESET, av[1]);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (arguments_check(ac, av) != true)
		return (EXIT_FAILURE);
	read_map(av[1], &map);
	if (map_validator(&map) != true)
		return (EXIT_FAILURE);
	free_map(map.map);
	return (EXIT_SUCCESS);
}
