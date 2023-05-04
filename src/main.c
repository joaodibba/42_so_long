/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/04 03:04:47 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	arguments_check(int ac, char **av)
{
	if (ac < 2)
	{
		(void)av;
		ft_printf("\033[0;31mError: ./so_long <PATH/TO/MAP>\n\033[0m");
		return (EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		(void)av;
		ft_printf("\033[0;31mError: You can choose only one map!\n\033[0m");
		return (EXIT_FAILURE);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (!arguments_check(ac, av))
		return (EXIT_FAILURE);
}
