/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:46:15 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/06 03:47:41 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(char *path_to_map, t_map *map)
{
	int		fd;
	char	*line;
	char	*text;
	char	*temp;

	fd = open(path_to_map, 0, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[0;31m [Error] READING MAP <%s>.\n\033[0m", path_to_map);
		exit(EXIT_FAILURE);
	}
	map->map_path = ft_strdup(path_to_map);
	text = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(text, line);
		free(text);
		free(line);
		text = temp;
		line = get_next_line(fd);
	}
	map->map = ft_split(text, '\n');
	if(text[0] == 0 || map->map[0] == 0)
		map_error(map);
	free(text);
	close(fd);
}
