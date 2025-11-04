/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:05:20 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 17:36:21 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>

#define WINDOWSIZE 1000
#define LINES 10

#define BUTTONPRESS 04

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
	t_data	*img;
	int		map[LINES][LINES];
}			t_mlx;

// F U N C T I O N S
void	draw_hori_lines(t_data *img);
void	draw_vert_lines(t_data *img);
void	draw_line(t_data *img, float angle_deg, int length, int start_x, int start_y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_grid(t_data *img, int n);
void	fill_square(t_data *img, int x, int y, int color);
int		square_on_click(int keycode, int x, int y, t_mlx *mlx);
