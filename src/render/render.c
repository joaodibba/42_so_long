/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:55:42 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:58:32 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	validate_player_move(t_vars *vars)
{
	if (vars->player.move.up == true)
	{
		move(&(vars->map), &(vars->player), 0, -1);
		vars->player.move.up = 0;
	}
	if (vars->player.move.down == true)
	{
		move(&(vars->map), &(vars->player), 0, 1);
		vars->player.move.down = 0;
	}
	if (vars->player.move.left == true)
	{
		move(&(vars->map), &(vars->player), -1, 0);
		vars->player.move.left = 0;
	}
	if (vars->player.move.right == true)
	{
		move(&(vars->map), &(vars->player), 1, 0);
		vars->player.move.right = 0;
	}
}

static void	put_steps(t_vars	*vars, t_pos pos, int steps)
{
	char	*new_str;
	char	*steps_str;

	steps_str = ft_itoa(steps);
	new_str = ft_strjoin("Steps: ", steps_str);
	mlx_string_put(vars->mlx, vars->win, pos.x, pos.y, BLACK_PIXEL, new_str);
	ft_free_multiple(2, steps_str, new_str);
}

static void	put_ducks(t_vars	*vars, t_pos pos, int total_ducks, int ducks)
{
	char	*string;
	char	*ducks_str;
	char	*total_ducks_str;

	total_ducks_str = ft_itoa(total_ducks);
	ducks_str = ft_itoa(ducks);
	string = ft_strjoin("Ducks: ", total_ducks_str);
	string = ft_strjoin(string, " / ");
	string = ft_strjoin(string, ducks_str);
	mlx_string_put(vars->mlx, vars->win, pos.x, pos.y, BLACK_PIXEL, string);
	ft_free_multiple(3, total_ducks_str, ducks_str, string);
}

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (MLX_ERROR);
	render_map(vars);
	validate_player_move(vars);
	render_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->final_image.img, 0, 0);
	put_ducks(vars, (t_pos){10, 20}, vars->map.collectible_count, \
	vars->player.collectible_count);
	put_steps(vars, (t_pos){10, 40}, vars->player.move_count);
	return (EXIT_SUCCESS);
}
