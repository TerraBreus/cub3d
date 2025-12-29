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

#define WINDOWLENGTH 1920
#define WINDOWHEIGHT 1080

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

//ALL data for the executive part gets initialized here. Most of the stuff
//is mlx related and can probably use better naming.
//handles the instance of mlx, the window pointer, the image creation.
int		init_data(t_mlx *data);

//Simple map creater ONLY FOR TESTING WITHOUT PARSING READY
char	**create_square_test_map(int size);
