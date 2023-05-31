/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/31 13:08:52 by jalves-c         ###   ########.fr       */
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
		map_error(&vars.map);
	ft_printf("[ " GREEN "OK" RESET " ] | %s" \
												" is a valid map!\n", av[1]);
	vars.window_width = vars.map.width * TILE_SIZE;
	vars.window_height = vars.map.height * TILE_SIZE;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, \
				vars.window_width, vars.window_height, "LA PISCINE");
	if (!vars.win)
		exit(1);
	vars.final_image.img = mlx_new_image(vars.mlx, \
							vars.window_width, vars.window_height);
	vars.final_image.addr = mlx_get_data_addr(vars.final_image.img, \
	&vars.final_image.bpp, &vars.final_image.line_len, \
	&vars.final_image.endian);
	load_sprites(&vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keys, &vars);
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, &handle_key_release, &vars);
	mlx_hook(vars.win, DestroyNotify, KeyPressMask, &close_window, &vars);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_loop(vars.mlx);
	ft_free_matrix(vars.map.grid);
	ft_free_multiple(2, vars.map.map_path, vars.mlx);
}
