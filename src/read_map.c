/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:46:15 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/15 01:37:01 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(const char *path_to_map, t_map *map)
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
	if (map->map_path == NULL)
		exit(EXIT_FAILURE);
	text = read_map_content(fd);
	map->map = ft_split(text, '\n');
	if (text[0] == 0 || map->map[0] == 0)
		map_error(map);
	free(map->map_path);
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
		text = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (text);
}

bool	map_validator(t_map *map)
{
	t_map	map_copy;

	if (map_size_check(map) != true || map_is_rectangular(map) != true || \
		map_content_is_valid(map) != true || map_is_closed(map) != true)
	{
		map_error(map);
		return (false);
	}
	map_copy = duplicate_map(*map);
	if (!map_copy.map)
	{
		free_map(map->map);
		free(map->map_path);
		exit(EXIT_FAILURE);
	}
	if (map_copy.map)
		free_map(map_copy.map);
	return (true);
}
