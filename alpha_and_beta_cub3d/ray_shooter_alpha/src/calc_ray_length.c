/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:06:46 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 17:34:47 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

static int	detect_wall_vert(double dir, int x, int y, t_data *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
		return (mlx->map[x][y]);
	else
		return (mlx->map[x - 1][y]);
}

static int	detect_wall_hori(double dir, int x, int y, t_data *mlx)
{
	if (out_of_bounds(x, y))
		return (0);
	if (dir > 0)
		return (mlx->map[x][y]);
	else
		return (mlx->map[x][y - 1]);
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
	while (++i < 30)
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
