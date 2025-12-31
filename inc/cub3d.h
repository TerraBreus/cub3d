/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:07:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/31 12:08:52 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "structs.h"
#include "enums.h"
#include <math.h>
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
//NOTE: A specific distinction is made between the image textures
//		and the mlx metadata. See the relevant structures for more explanation.
int		init_data(t_mlx *data, t_cub3d *cub3d);

//ONLY FOR TESTING WITHOUT PARSING
//This is just for Zachaar to develop raytracing before the 
//parser is (completely) finished.
void	mock_parser(t_cub3d *cub3d);

// Events are actions a user can perform in the game. They range from
// keypresses (wasd) to mouse movement to pressing the 'x' button onscreen.
// In simple terms we connect input from the player to the
// corresponding action. (we hook events to specific functions)
void	hook_events(t_mlx *mlx_data, t_cub3d *cub3d);
