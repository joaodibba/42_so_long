/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:31:41 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/06 20:58:41 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	read_map(const char *path_to_map, t_map *map)
{
	int		fd;
	char	*text;

	fd = open(path_to_map, 0, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	map->map_path = ft_strdup(path_to_map);
	if (!map->map_path)
	{
		free(map->map_path);
		return ;
	}
	text = read_map_content(fd);
	if (!text)
	{
		free(text);
		return ;
	}
	map->grid = ft_split(text, '\n');
	if (!map->grid[0])
		map_error(map);
	free(text);
	close(fd);
}

char	*read_map_content(int fd)
{
	char	*line;
	char	*text;
	char	*temp;

	text = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(text, line);
		ft_free_multiple(2, text, line);
		text = temp;
		line = get_next_line(fd);
	}
	return (text);
}
