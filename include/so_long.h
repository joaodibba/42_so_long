/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:27:08 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/01 17:12:34 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx_macos/mlx.h"
# include "../libft/libft.h"
# include "structures.h"
# include "macros.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//arguments management
bool			arguments_check(int ac, char **av);
bool			path_to_map_check(const char *path_to_map);

//map management
void			read_map(const char *path_to_map, t_map *map);
char			*read_map_content(int fd);
t_map			duplicate_map(t_map map);
void			map_error(t_map *map);
bool			map_validator(t_vars *vars);
bool			map_size_check(t_map *map);
bool			map_is_rectangular(t_map *map);
bool			map_content_is_valid(t_map *map);
bool			map_is_closed(t_map *map);
bool			map_content_count(t_map *map, char c);
void			assign_map_to_vars(t_map *map, t_vars *vars);

void			print2darray(char **arr, int rows);

//window management
int				window_width(void);
int				window_height(void);
int				handle_key(int key, t_vars *vars);
int				handle_key_release(int key, t_vars *vars);
int				close_window(t_vars *vars);
int				render(t_vars *vars);

//graphics
void			load_sprites(t_vars	*vars);
unsigned int	get_pixel(t_img *img, int x, int y);
void			put_pixel(t_img *img, int x, int y, int color);
void			render_map(t_vars *vars);
void			put_sprite(t_vars *vars, t_pos pos, char c);

//structures
t_vars			*vars(void);
t_map			*map(void);

void	render_player(t_vars *vars);
void	copy_image(t_img img, t_pos pos, t_img *final_img);
void	find_map_start(t_map *map, t_player *player);

#endif