/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:07:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/29 18:12:31 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// - - - - M A C R O S - - - -
// - - - - - - - - - - - - - -
// (basically constant global variables)

// Some can be changed to reconfigure certain aspects of the game.
// NOTE: This will require a rebuild.

// Dimensions of the window for the game.
#define WINDOWLENGTH 1920
#define WINDOWHEIGHT 1080

// --- --- --- E N U M S --- --- --- ---
// - - - - - - - - - - - - - - - - - - -
// (the bridge between readable
// 		and executable code)

/*
 * X11 Events with their corresponding values.
 * They are used to identify what kind of 
 * event is triggered in the mlx_hook() function.
 * (see hook_events.c)
 * for more documentation see:
 * https://harm-smits.github.io/42docs/libs/minilibx/events.html
*/

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

// --- --- --- S T R U C T U R E S --- --- ---
// - - - - - - - - - - - - - - - - - - - - - -
// (because we can't pass a hundred
// 		parameters to a function)

/*	-- MLX STRUCTURE --
 * Simple structure holding relevant data
 * for the graphical library mlx.
 * 
 * Main usage of the library is
 * the creation and maintenance 
 * of windows, events and images

 * More info on this library can be found
 * in the mlx/mlx.h header.
 *
 * The win_h and win_l parameters
 * are for future resizing of windows.
 * This is not a subject requirement,
 * but perhaps useful just in case.
*/

typedef struct s_mlx
{
	void	*instance;
	void	*window;
	int		win_h;
	int		win_l;
}	t_mlx;

/*	-- LEVEL STRUCTURE --
 * All the necessary information from parsing.
 * Should contain:
 * 		- The map.
 * 		- Texture pathnames.
 * 		- Starting position player
 * 		- Colors for Floor & ceiling
*/

typedef struct s_level
{
	char	**map;
	int		x_row;
	int		y_col;
	int		player_pos_x;
	int		player_pos_y;
	int		player_dir_deg;
}	t_level;

//--- --- --- F U N C T I O N S --- --- ---
//- - - - - - - - - - - - - - - - - - - - -
// (prototypes and descriptions of
// 		all nonstatic functions)
// 	NB: If no description is given assume
// 		its usage is considered very
// 		straightforward or the developer
// 		was too lazy...

//ALL data for the executive part gets initialized here. Most of the stuff
//is mlx related and can probably use better naming.
//handles the instance of mlx, the window pointer, the image creation.
int		init_data(t_mlx *data);

//Simple map creater ONLY FOR TESTING WITHOUT PARSING READY
char	**create_square_test_map(int size);
