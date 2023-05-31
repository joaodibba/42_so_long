/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:39:20 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/31 12:52:59 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//WINDOW SIZE
# define TILE_SIZE 32

//ERROR CODES
# define MLX_ERROR		1
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

//KEY CODES
# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100

// MLX MACROS
# define KeyPress 2
# define KeyRelease 3
# define KeyPressMask 1L<<0
# define KeyReleaseMask 1L<<1
# define NoEventMask 0
# define DestroyNotify 17

//MLX_COLORS
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define WHITE_PIXEL 0XFFFFFF

//PRINTF_COLORS
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"

//MAP_CHAR_CODES
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_START 'P'
# define PC_UP 'W'
# define PC_DOWN 'X'
# define PC_LEFT 'Y'
# define PC_RIGHT 'Z'
# define CONE 'V'

#endif