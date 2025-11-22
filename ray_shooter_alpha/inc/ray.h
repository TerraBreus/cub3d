/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:18:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 12:22:34 by zivanov          ###   ########.fr       */
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

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_user {
	t_img	img;
	float	pos[2];
	float	direction;
}			t_user;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_img	grid;
	t_img	rays;
	t_user	user;
	int		map[LINES][LINES];
}			t_data;

// F U N C T I O N S
void	init_data(t_data *data);
void	my_mlx_create_image(void *mlx, t_img *img, int size);
void	draw_line(t_img *img, float angle_deg, int length, int start_x, int start_y, int color);
void	init_grid(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	fill_square(t_img *img, int x, int y, int color);
