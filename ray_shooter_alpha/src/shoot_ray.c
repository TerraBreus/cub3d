/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:21:55 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 18:44:38 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int	out_of_bounds(int x, int y)
{
	if (x > (LINES - 1) || x < 0)
	{
		printf("x of bounds! x:%i\n", x);
		return (1);
	}
	if (y > (LINES - 1) || y < 0)
	{
		printf("y out of bounds. y:%i\n", y);
		return (1);
	}
	return (0);
}

int	detect_wall_vert(double dir, int x, int y, t_data *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
	{
		return (mlx->map[x][y]);
	}
	else
	{
		return (mlx->map[x - 1][y]);
	}	
}

int	detect_wall_hori(double dir, int x, int y, t_data *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
	{
		return (mlx->map[x][y]);
	}
	else
	{
		return (mlx->map[x][y - 1]);
	}	
}

double	calc_ray_length(double angle_r, double x, double y, t_data *mlx)
{
	double	dx_dy[2];		//dx and dy respect. Direction of the ray in x & y dir.
	double	dsx_dsy[2];		//the length of the ray for going to the next x/y line.
	double	nxt_xy[2];		//the dist. to the next x or y line (hor/ver).
	double	result = 0;			//the total length of the ray;
	
	dx_dy[0] = cos(angle_r);
	dx_dy[1] = -sin(angle_r);

	int i = -1;
	while (++i < 20)
	{
		nxt_xy[0] = -1 * fmod(x, 1);
		if (nxt_xy[0] == 0)
		{
			nxt_xy[0] = 1;
			if (dx_dy[0] < 0)
				nxt_xy[0] = -1;
		}
		else if (dx_dy[0] > 0)
			nxt_xy[0] = nxt_xy[0] + 1;

		nxt_xy[1] = -1 * fmod(y, 1);
		if (nxt_xy[1] == 0)
		{
			nxt_xy[1] = 1;
			if (dx_dy[1] < 0)
				nxt_xy[1] = -1;
		}
		else if (dx_dy[1] > 0)
			nxt_xy[1] = nxt_xy[1] + 1;
		dsx_dsy[0] = nxt_xy[0] / dx_dy[0];
		dsx_dsy[1] = nxt_xy[1] / dx_dy[1];
		if (fabs(dsx_dsy[0]) > fabs(dsx_dsy[1]))
		{
			result += fabs(dsx_dsy[1]);
			y += nxt_xy[1];
			x += (dsx_dsy[1] * dx_dy[0]);
			if (detect_wall_hori(dx_dy[1], (int) x, (int) y, mlx))
				break ;
		}
		else
		{
			result += fabs(dsx_dsy[0]);
			x += nxt_xy[0];
			y += (dsx_dsy[0] * dx_dy[1]);
			if (detect_wall_vert(dx_dy[0], (int) x, (int) y, mlx))
				break ;
		}
	}
	return (result);
}

void	clean_rays(t_img *img)
{
	int	i;
	int	j;

	for (i = 0; i < WINDOWSIZE; i++)
	{
		for (j = 0; j < WINDOWSIZE; j++)
			my_mlx_pixel_put(img, i, j, BLACK);
	}
}

void	shoot_ray(t_img *img, double angle, int  pix_x, int pix_y, t_data *mlx)
{
	double		ray_length;
	double		cell_size;
	int			i;

	clean_rays(img);
	cell_size = (double) WINDOWSIZE / LINES;
	for (i = -45; i < 46; i++)
	{
		ray_length = calc_ray_length(((angle + i) / 180) * -M_PI, ((double) pix_x) / cell_size, ((double)  pix_y) / cell_size, mlx);
		draw_line(img, angle + i, (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
	}

	render_window(mlx, true);
}

