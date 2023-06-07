/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:40:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:10:14 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int fill(t_pos pos, int y, int x, char **grid, t_vars *vars)
{
    if (x >= pos.x || y >= pos.y || x < 0 || y < 0)
        return 0;
    if (grid[y][x] == WALL || grid[y][x] == PC_UP || \
        grid[y][x] == PC_DOWN || grid[y][x] == PC_LEFT || \
        grid[y][x] == PC_RIGHT)
        return 0;
    if (grid[y][x] == EMPTY_SPACE || grid[y][x] == COLLECTIBLE)
    {
        grid[y][x] = MAP_START;
        return 1;
    }
    if (grid[y][x] == CONE)
        vars->flood.exit_reached = true;
    return 0;
}

void flood(t_pos size, int y, int x, char **grid, t_vars *vars)
{
    if (fill(size, y, x - 1, grid, vars))
        flood(size, y, x - 1, grid, vars);
    if (fill(size, y, x + 1, grid, vars))
        flood(size, y, x + 1, grid, vars);
    if (fill(size, y - 1, x, grid, vars))
        flood(size, y - 1, x, grid, vars);
    if (fill(size, y + 1, x, grid, vars))
        flood(size, y + 1, x, grid, vars);
}

bool map_valid_path_checker(t_vars *vars, t_map *map)
{
    t_map map_copy;
    map_copy = duplicate_map(vars->map);
    vars->flood.exit_reached = false;
    if (!map_copy.grid)
        return false;
    flood((t_pos){map->height, map->width}, 2, 2, map_copy.grid, vars);
    ft_free_matrix(map_copy.grid);
    return vars->flood.exit_reached;
}