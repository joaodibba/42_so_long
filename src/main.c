/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/04 20:01:42 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



int map_check(char *path_to_map)
{
	size_t len;

	len = ft_strlen(path_to_map);
	if(len < 5 || ft_strcmp(path_to_map + len - 4,".ber") != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	arguments_check(int ac, char **av)
{
	if (ac != 2)
	{
		(void)av;
		ft_printf("\033[0;31mError: ./so_long <PATH/TO/MAP.ber>\n\033[0m");
		return (EXIT_FAILURE);
	}
	else if(map_check(av[1]))
	{
		ft_printf("\033[0;31mError: <%s> is not a valid <PATH/TO/MAP.ber>\n\033[0m", av[1]);
		return (EXIT_FAILURE);
	}
	ft_printf("\033[0;32m ALL OK! \033[0m");
	return (0);
}



int	main(int ac, char **av)
{
	if (arguments_check(ac, av) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
		
}
