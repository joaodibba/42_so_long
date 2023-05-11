/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:46:15 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 19:28:59 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(char *path_to_map, t_map *map)
{
	int		fd;
	char	*text;

	fd = open(path_to_map, 0, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED "[Error] READING MAP <%s>.\n" RESET, path_to_map);
		exit(EXIT_FAILURE);
	}
	map->map_path = ft_strdup(path_to_map);
	text = read_map_content(fd);
	map->map = ft_split(text, '\n');
	if (text[0] == 0 || map->map[0] == 0)
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
		free(text);
		free(line);
		text = temp;
		line = get_next_line(fd);
	}
	return (text);
}

bool	map_validator(t_map *map)
{
	t_map	map_copy;

	if (map_size_check(map) != true || map_is_rectangular(map) != true || \
		map_content_is_valid(map) != true)
	{	
		map_error(map);
		return (false);
	}
		map_copy = duplicate_map(*map);
	if (!map_copy.map)
		return (false);
	return (true);
}
