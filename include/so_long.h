/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:27:08 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 21:33:24 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//WINDOW SIZE
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

//ERROR CODES
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

//KEYCODES
# define ESCAPE 65307

//COLORS_FOR_MLX
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define WHITE_PIXEL 0XFFFFFF

//COLORS_FOR_PRINTF
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"

typedef struct s_map
{
	char				**map;
	char				*map_path;
	size_t				rows;
	size_t				cols;
	unsigned int		wall;
	unsigned int		pc;		
	unsigned int		collectible;
	unsigned int		empty_space;
	unsigned int		map_exit;
	unsigned int		map_start;
}			t_map;

bool	arguments_check(int ac, char **av);
bool	path_to_map_check(char *path_to_map);
void	read_map(char *path_to_map, t_map *map);
char	*read_map_content(int fd);
bool	map_validator(t_map *map);
void	free_map(char **map);
void	map_error(t_map *map);
t_map	duplicate_map(t_map map);
bool	map_size_check(t_map *map);
bool	map_is_rectangular(t_map *map);
bool	map_content_is_valid(t_map *map);
bool	map_is_closed(t_map *map);

#endif