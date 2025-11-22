/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:18:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 09:19:20 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>

#define WINDOWSIZE 1000
#define LINES 20

#define BUTTONPRESS 04
#define KEYPRESS 02

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

#define RED      0xFF0000
#define GREEN    0x00FF00
#define BLUE     0x0000FF
#define YELLOW   0xFFFF00
#define CYAN     0x00FFFF
#define MAGENTA  0xFF00FF
#define WHITE    0xFFFFFF
#define BLACK    0x000000
#define ORANGE   0xFFA500
#define PURPLE   0x800080
#define PINK     0xFFC0CB
#define BROWN    0x8B4513
#define GRAY     0x808080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_data	ui;
	t_data	grid;
	t_data	cursors;
	int		map[LINES][LINES];
	int		keyboard_pos[2];
	int		mouse_pos[2];
}			t_mlx;

// F U N C T I O N S
