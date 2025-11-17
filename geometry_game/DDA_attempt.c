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

/*
double	calc_ray_length(float angle, double ds, double pos_x, double pos_y, t_mlx *mlx)
{
	//see whether ds_x or ds_y is bigger
	//based on that calculate the length of the ray.
	//based on the length calculate new coordinates
	//check if new coordinates are a wall
	//if not cast the function again (recursively)
	//otherwise return the length + the new extra new bit.
	double	ds_x;
	double	ds_y;
	double	nxt_vline;
	double	nxt_hline;
	int		i;

	i  = 0;
	printf("x %i, y %i map %i\n", (int) pos_x, (int) pos_y, mlx->map[(int ) pos_x][(int ) pos_y]);
	while ((mlx->map[(int ) pos_x][(int ) pos_y] == 0) && i < 30)
	{
		i++;
		nxt_hline = fmod(pos_y, 1);
		if (nxt_hline == 0)
			nxt_hline = 1;
		nxt_vline = fmod(pos_x, 1);
		if (nxt_vline == 0)
			nxt_vline = 1;
		if (angle > -90 && angle < 90)
		{
			if (nxt_vline != 1)
				nxt_vline = 1 - nxt_vline;
		}
		else
		{
			nxt_vline *= -1;
		}
		if (angle > 0 && angle < 180)
		{
			if (nxt_hline != 1)
				nxt_hline = 1 - nxt_hline; 
		}
		else
		{
			nxt_hline *= -1;
		}
		ds_x = fabs(nxt_vline) / cos(angle);
		ds_y = fabs(nxt_hline) / sin(angle );
		if (fabs(ds_x) < fabs(ds_y))
		{
			pos_x += nxt_vline; //(or -=)
			pos_y += (ds_x * sin((angle / 180) * M_PI));
			ds += fabs(ds_x);
		}
		else
		{
			pos_x += (ds_y * cos((angle / 180) * M_PI));
			pos_y += nxt_hline;
			ds += fabs(ds_y);
		}
		printf("ds %f, x %f y %f\n", ds, pos_x, pos_y);
	}
	return (ds);
}
*/
double	calc_ray_length(double angle_r, double x, double y, t_mlx *mlx)
{
	double	d_xy[2];		//dx and dy respect. Direction of the ray in x & y dir.
	double	ds_xy[2];		//the length of the ray for going to the next x/y line.
	double	nxt_xy[2];		//the dist. to the next x or y line (hor/ver).
	double	result;			//the total length of the ray;
	

}

void	cast_ray(t_data *img, double angle, int  pix_x, int pix_y y, t_mlx *mlx)
{
	double		ray_length;
	double		cell_size;

	cell_size = (double) WINDOWSIZE / LINES;
	printf("%f, %f, %f\n", (angle / 180) * M_PI, (double) (pix_x / cell_size), (double)  (pix_y / cell_size));
	ray_length = calc_ray_length((angle / 180) * M_PI, (double) (pix_x / cell_size), (double)  (pix_y / cell_size), t_mlx *mlx);
	draw_line(img, angle, (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
}

