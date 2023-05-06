/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/06 19:08:21 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	path_to_map_check(char *path_to_map)
{
	size_t	len;

	len = ft_strlen(path_to_map);
	if (len < 5 || ft_strcmp(path_to_map + len - 4,".ber") != 0)
		return (false);
	return (true);
}

bool	arguments_check(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf("\033[0;31m [Error] ./so_long <PATH/TO/MAP.ber>.\n\033[0m");
		return (false);
	}
	else if (path_to_map_check(av[1]) != true)
	{
		ft_printf("\033[0;31m [Error] <%s> is not a valid <PATH/TO/MAP.ber>.\n\033[0m", av[1]);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (arguments_check(ac, av) != true)
		return (EXIT_FAILURE);
	if (map_validator(&map) != true)
		return (EXIT_FAILURE);
	read_map(av[1], &map);
	free_map(map.map);
	free(map.map_path);
	return (EXIT_SUCCESS);
}
