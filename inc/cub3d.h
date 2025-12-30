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

typedef enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
}	t_events;

/*
 * To make the texture structure more readable
 * we use a simple enum to keep track of
 * which side of the cube we are talking about.
 * Usage would be:
 * cub3d->textures.paths[NO];
*/

typedef enum e_dir
{
	NO = 0,
	EA = 1,
	SO = 2,
	WE = 3
}	t_dir;

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
 * Metadata of the level given from the parser.
 * Should contain:
 * 		- The map.
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

/*
 * -- TEXTURE STRUCTURE --
 *  Paths will be given by parsing.
 *  Execution will create the mlx image structures.
 *  This can be considered part of the mlx structure,
 *  yet this was purposely avoided to make a
 *  distinction between the mlx instance and the mlx images.
 *
 *  This structure makes use of the t_dir enums and can be used
 *  as following: textures.paths[NO/EA/SO/WE] and
 *  similarly textures.mlx_img[NO/EA/SO/WE]
*/

typedef struct s_textures
{
	char	*paths[4];
	void	*mlx_img[4];
}	t_textures;

/*
 * -- COLOR STRUCTURE --
 *  In essence this is a simple array of three integers
 *  yet to avoid the confusion of pointers and arrays
 *  a decision was made to use a separate structure.
 *
 *  This makes parsing colors as a parameter easier and more readable.
 *  Instead of `some_func(int colors[3]);`
 *  (above can be confusing when using pointers and arrays combined)
 *  we can use `some_func(t_colors *colors);`
 *  (this is a pointer and not an array)
*/

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_colors;

/*
 * -- CUB3D STRUCTURE --
 *  A big meta structure that holds all the
 *  data needed for the cub3d program to run.
 *  Most structures have their descriptions given
 *  in the comments above.
*/

typedef struct s_cub3d
{
	t_textures	texture;
	t_colors	floor;
	t_colors	ceiling;
	t_mlx		mlx_data;
	t_level		level;
}	t_cub3d;

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

//ONLY FOR TESTING WITHOUT PARSING READY
void	mock_parser(t_cub3d *cub3d);
