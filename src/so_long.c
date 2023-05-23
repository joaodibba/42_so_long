/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/23 20:18:52 by jalves-c         ###   ########.fr       */
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
		ft_printf("[ " RED "!!" RESET " ] | Wrong arguments number \"./so_long " \
				RED "path/to/map.ber" RESET "\".\n");
		return (false);
	}
	if (path_to_map_check(av[1]) != true)
	{
		ft_printf("[ " RED"!!"RESET " ] | "RED"%s"RESET \
				" is not a valid map.\n", av[1]);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (arguments_check(ac, av) != true)
		return (EXIT_FAILURE);
	read_map(av[1], &vars.map);
	if (map_validator(&vars) != true)
	{
		ft_printf("[ " RED "!!" RESET " ] | %s" \
												" is not a valid map.\n", av[1]);
		return (EXIT_FAILURE);
	}
	ft_printf("[ " GREEN "OK" RESET " ] | %s" \
												" is a valid map!\n", av[1]);
	vars.window_width = vars.map.cols * TILE_SIZE * 2;
	vars.window_height = vars.map.rows * TILE_SIZE * 2;
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, \
				vars.window_width, vars.window_height, "SO LONG");
	vars.img.mlx_img = mlx_new_image(vars.mlx_ptr, \
							vars.window_width, vars.window_height);
	mlx_loop_hook(vars.mlx_ptr, &render, &vars);
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &handle_keys, &vars);
	mlx_hook(vars.win_ptr, DestroyNotify, KeyPressMask, &close_window, &vars);
	mlx_loop(vars.mlx_ptr);
	free_map(vars.map.grid);
	ft_free_multiple(2, vars.map.map_path, vars.mlx_ptr);
}
