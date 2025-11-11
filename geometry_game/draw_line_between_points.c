/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_between_points.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:58:43 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/06 17:08:13 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

void	draw_line_between_points(t_data *img, int k_pos[2], int m_pos[2])
{
	float		length;
	float		dx;
	float		dy;
	float		angle;

	dx = k_pos[0] - m_pos[0];
	dy = k_pos[1] - m_pos[1];
	length = sqrt((dx * dx) + (dy * dy));
	angle = acos(dx / length) * 180 / M_PI;
	if (dy < 0)
		angle *= -1;
	draw_line(img, angle, length, m_pos[0], m_pos[1], PINK);
	printf("dx %f, dy %f, length %f, acos %f\n", dx, dy, length, angle);
	(void ) img;
}
