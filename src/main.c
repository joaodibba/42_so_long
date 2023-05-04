/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/04 19:41:58 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	
	i = 0;
	if(!s1 || !s2)
		return (0);
	while(s1[i] == s2[i])
		i++;
	return (i);
}

int map_check(char *path_to_map)
{
	while(*path_to_map)
	{
		if(*path_to_map == '.' && !ft_strncmp(path_to_map,".ber", 4) == 0)
			return (EXIT_SUCCESS);
		path_to_map++;
	}
	return (EXIT_FAILURE);
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
		ft_printf("\033[0;31mError: %s is not a .ber\n\033[0m", av[1]);
		return (EXIT_FAILURE);
	}
	return (0);
}



int	main(int ac, char **av)
{
	if (!arguments_check(ac, av))
		return (EXIT_FAILURE);
		
}
