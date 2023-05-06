/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:43:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/05 19:53:39 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;
	if(!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	map_error(t_map *map)
{
	ft_printf("\033[0;31mError: <%s> is not a valid <PATH/TO/MAP.ber>.\n\033[0m", map->map_path);
	free_map(map->map);
	exit(EXIT_FAILURE);
}

void	read_map(char *path_to_map, t_map *map)
{
	int	fd;
	char *line;
	char *text;
	
	fd = open(path_to_map, 0 , O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[0;31mError: reading map <%s>.\n\033[0m", path_to_map);
		exit(EXIT_FAILURE);
	}
	map->map_path = ft_strdup(path_to_map);
	text = ft_strdup("");
	while((line = get_next_line(fd)) != NULL)
	{
		text = ft_strjoin(text, line);
		free(line);
	}
	map->map = ft_split(text, '\n');
	free(text);
	if(map->map[0] == 0)
		map_error(map);
	ft_printf("\033[0;32m MAP OK!\n\033[0m");
	close(fd);
}

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
		ft_printf("\033[0;31mError: ./so_long <PATH/TO/MAP.ber>.\n\033[0m");
		return (EXIT_FAILURE);
	}
	else if(map_check(av[1]))
	{
		ft_printf("\033[0;31mError: <%s> is not a valid <PATH/TO/MAP.ber>.\n\033[0m", av[1]);
		return (EXIT_FAILURE);
	}
	ft_printf("\033[0;32m ALL OK!\n\033[0m");
	return (0);
}



int	main(int ac, char **av)
{
	t_map map;

	if (arguments_check(ac, av) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	read_map(av[1], &map);
	free_map(map.map);
	free(map.map_path);
	return (EXIT_SUCCESS);
}
