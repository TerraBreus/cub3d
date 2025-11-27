/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:18:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 17:32:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOWSIZE 1000
#define LINES 20
#define USERSIZE 10
#define MOVESPEED 4
#define ROT_SPEED 3
#define FOV 90

#define BUTTONPRESS 04
#define KEYPRESS 02

#define UP 119
#define DOWN 115
#define RIGHT 100
#define LEFT 97

#define KEY_R 114
#define KEY_E 101
#define KEY_Q 113
#define KEY_P 112
#define ENTER 65293

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
void	init_user(void *mlx, t_user *u);
void	render_window(t_data *data, bool ray);
void	square_on_click(int x, int y, t_data *data);
void	hook_events(t_data *data, void *mlx_win);
void	square_on_click(int x, int y, t_data *data);
int		keyboard(int keycode, t_data *data);
bool	wall_collision(int x, int y, t_data *data);
void	move_player(float pos[2], int keycode, t_data *data);
int		mouse_click(int keycode, int x, int y, t_data *data);
void	shoot_ray(t_img *img, double angle, int  pix_x, int pix_y, t_data *mlx);
void	fill_img_with(int color, t_img *img);
int	out_of_bounds(int x, int y);
double	calc_ray_length(double angle_r, double x, double y, t_data *mlx);
void	wolfenstein(t_img *img, double angle, int  pix_x, int pix_y, t_data *mlx);
void	turn_player(float *dir, int keycode, t_data *data);
void	print_user_info(t_data *data);
