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

double	calc_ray_length(float angle, double ds, double pos_x, double pos_y, int *(map[LINES][LINES]))
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
	double	new_x;
	double	new_y;

	nxt_hline = fmod(pos_y, 1);
	nxt_vline = fmod(pos_x, 1);
	if (angle > -90 && angle < 90)
	{
		nxt_vline = 1 - nxt_vline;
	}
	else
	{
		nxt_vline *= -1;
	}
	if (angle > 0 && angle < 180)
	{
		nxt_hline = 1 - nxt_hline; 
	}
	else
	{
		nxt_hline *= -1;
	}
	ds_x = fabs(nxt_vline) / cos((angle / 180) * M_PI);
	ds_y = fabs(nxt_hline) / sin((angle / 180) * M_PI);
	if (fabs(ds_x) < fabs(ds_y))
	{
		new_x = pos_x + nxt_vline; //(or -=)
		new_y = pos_y + (ds_x * sin(angle));
		ds += fabs(ds_x);
	}
	else
	{
		new_x = pos_x + ds_y * cos(angle);
		new_y = pos_y + nxt_hline;
		ds += fabs(ds_y);
	}
	if ((*map[(int)(new_x)][(int)(new_y)] == 1) || ds > 40)
		return (ds);
	else
		return (calc_ray_length(angle, ds, pos_x, pos_y, map));
}

void	cast_ray(t_data *img, float angle, int pix_x, int pix_y, int *(map[LINES][LINES]))
{
	int		cell_size;
	double	pos_x;
	double	pos_y;
	double	ray_length;

	cell_size = (WINDOWSIZE / LINES);
	pos_x = ((double) pix_x / cell_size);
	pos_y = ((double) pix_y / cell_size);
	ray_length = calc_ray_length(angle, 0, pos_x, pos_y, map);
	draw_line(img, angle, (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
}

/*
void	cast_ray(t_data *img, float angle, int pix_x, int pix_y)
{
	double	nxt_vline;
	double	dist_vline;
	double	dist_hline;
	double	nxt_hline;
	int		cell_size;
	double	pos_x;
	int		dir_x;
	double	pos_y;
	int		dir_y;

	cell_size = (WINDOWSIZE / LINES);
	pos_x = ((double) pix_x / cell_size);
	pos_y = ((double) pix_y / cell_size);
	nxt_hline = fmod(pos_y, dist_hline);
	nxt_vline = fmod(pos_x, dist_vline);
	if (angle > -90 && angle < 90)
	{
		nxt_vline = 1 - nxt_vline;
		dir_x = 0;
	}
	else
	{
		dir_x = 180;
		nxt_vline *= -1;
	}
	printf("pos_x; %f nxt: %f\n", pos_x, nxt_vline);
	if (angle > 1 && angle < 180)
	{
		nxt_hline = 1 - nxt_hline; //maybe the other way around so we know the direction (l/r) based on the sign and then caal fabs() when u want the length
		dir_y = 90;
	}
	else
	{
		dir_y = -90;
		nxt_hline *= -1;
	}
	printf("pos_y; %f nxt: %f\n", pos_y, nxt_hline);
	draw_line(img, dir_x, (int) (fabs(nxt_vline) * cell_size), pix_x, pix_y, RED);
	draw_line(img, dir_y, (int) (fabs(nxt_hline) * cell_size), pix_x, pix_y, GREEN);

	double	ds_x;
	double	ds_y;

	ds_x = fabs(nxt_vline) / cos((angle / 180) * M_PI);
	ds_y = fabs(nxt_hline) / sin((angle / 180) * M_PI);
	printf("ds_x %f, ds_y %f, bool %b\n", fabs(ds_x), fabs(ds_y), fabs(ds_x) < fabs(ds_y));

	if (fabs(ds_x) < fabs(ds_y))
	{
		printf("\ndsx:%i\n", (int) (ds_x * cell_size));
		draw_line(img, angle, (int) (fabs(ds_x) * cell_size), pix_x, pix_y, ORANGE); 
		pos_x += nxt_vline; //(or -=)
		pos_y += (ds_x * sin(angle));
	}
	else
	{
		printf("\ndsy:%i\n", (int) (ds_y * cell_size));

		draw_line(img, angle, (int) (fabs(ds_y) * cell_size), pix_x, pix_y, ORANGE); 
		pos_x += ds_y * cos(angle);
		pos_y += nxt_hline;
	}
	//Then do the whole thing over again.
	printf("\n x: %f, y: %f\n", pos_x, pos_y);
}
*/
