/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_between_points.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:58:43 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/13 20:51:19 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

static void	remove_old_line(t_data *img, float angle, float length, int x, int y)
{
	static float	pos[4];

	if (pos[1] != 0)
		draw_line(img, pos[0], pos[1], pos[2], pos[3], BLACK);
	pos[0] = angle;
	pos[1] = length;
	pos[2] = x;
	pos[3] = y;
}

void	draw_line_between_points(t_data *img, int k_pos[2], int m_pos[2], t_mlx *mlx)
{
	float			dx;
	float			dy;
	float			angle;
	float			length;

	dx = k_pos[0] - m_pos[0];
	dy = k_pos[1] - m_pos[1];
	length = sqrt((dx * dx) + (dy * dy));
	angle = acos(dx / length) * 180 / M_PI;
	if (dy < 0)
		angle *= -1;
	remove_old_line(img, angle, length, m_pos[0], m_pos[1]);
	//draw_line(img, angle, length, m_pos[0], m_pos[1], PINK);
	cast_ray(img, angle, m_pos[0], m_pos[1], mlx);
	//printf("dx %f, dy %f, length %f, acos %f\n", dx, dy, length, angle);
	(void ) img;
}
