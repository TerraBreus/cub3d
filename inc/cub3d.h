/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:07:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/28 11:57:40 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define WINDOWHEIGHT 1080
#define WINDOWLENGTH 1920

/*
 * Simple structure for mlx data.
 * The win_h and win_l parameters
 * are for future resizing of windows.
 * This is not a subject requirement,
 * but perhaps useful just in case.
*/

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_h;
	int		win_l;
}	t_mlx_data;

/*
 * All the necessary information from parsing.
 * Should contain:
 * 		- The map.
 * 		- Texture pathnames.
 * 		- Starting position player
 * 		- Colors for Floor & ceiling
*/

typedef struct s_input
{
	char	**map;
}	t_input;

int		init_data(t_mlx_data *data);
