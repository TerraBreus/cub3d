/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_attempt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:35:15 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/13 22:13:51 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"
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

int	detect_wall_vert(double dir, int x, int y, t_mlx *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
	{
		printf("map[x: %i][y: %i] = %i\n", (int) x, (int) y, mlx->map[(int) x][(int) y]);
		return (mlx->map[x][y]);
	}
	else
	{
		printf("map[x: %i][y: %i] = %i\n", (int) x, (int) y, mlx->map[(int) x - 1][(int) y]);
		return (mlx->map[x - 1][y]);
	}	
}

int	detect_wall_hori(double dir, int x, int y, t_mlx *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
	{
		printf("map[x: %i][y: %i] = %i\n", (int) x, (int) y, mlx->map[(int) x][(int) y]);
		return (mlx->map[x][y]);
	}
	else
	{
		printf("map[x: %i][y: %i] = %i\n", (int) x, (int) y, mlx->map[(int) x][(int) y - 1]);
		return (mlx->map[x][y - 1]);
	}	
}

double	calc_ray_length(double angle_r, double x, double y, t_mlx *mlx)
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
		printf("\n\nx %f, y %f\n", x, y);
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
		
		printf("angle %f\nnxt x %f, nxt y %f\ndx: %f, dy %f\ndsx %f, dsy %f\n", angle_r, nxt_xy[0], nxt_xy[1], dx_dy[0], dx_dy[1], dsx_dsy[0], dsx_dsy[1]);
		printf("new_x %f, new y %f\n", x, y);
	}
	return (result);
}

void	cast_ray(t_data *img, double angle, int  pix_x, int pix_y, t_mlx *mlx)
{
	double		ray_length;
	double		cell_size;

	cell_size = (double) WINDOWSIZE / LINES;
	printf("pix_x %i, pix_y %i cs %f\n", pix_x, pix_y, cell_size);
	ray_length = calc_ray_length((angle / 180) * -M_PI, ((double) pix_x) / cell_size, ((double)  pix_y) / cell_size, mlx);
	draw_line(img, angle, (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
}

