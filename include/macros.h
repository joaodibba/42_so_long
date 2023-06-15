/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:39:20 by jalves-c          #+#    #+#             */
/*   Updated: 2023/06/15 12:09:26 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// TILE SIZE
# define TILE_SIZE 64

// ERROR CODES
# define MLX_ERROR		1
# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

// KEYCODES FOR MACOS
# ifdef __APPLE__
#  define ESCAPE 53
#  define W 13
#  define S 1
#  define A 0
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
# endif

// KEYCODES FOR LINUX
# ifdef __linux__
#  define ESCAPE 65307
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
# endif

// MLX CODES
// # define KeyPress 2
// # define KeyPressMask 1L<<0
// # define KeyRelease 3
// # define KeyReleaseMask 1L<<1
// # define NoEventMask 0
// # define DestroyNotify 17

// MLX_COLORS
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define WHITE_PIXEL 0XFFFFFF
# define BLACK_PIXEL 0X000000

// PRINTF_COLORS
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"

// MAP TILE CODES
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_START 'P'
# define PC_UP 'W'
# define PC_DOWN 'X'
# define PC_LEFT 'Y'
# define PC_RIGHT 'Z'

#endif