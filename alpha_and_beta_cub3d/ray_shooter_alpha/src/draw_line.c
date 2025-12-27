/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:12:43 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 12:15:13 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	draw_line(t_img *img, float angle_deg, int length, int start_x, int start_y, int color)
{
	float	dx;
	float	dy;
	int		x;
	int		y;
	int		i;

	dx = cos((angle_deg / 180) * M_PI);
	dy = sin((angle_deg / 180) * M_PI);

	for (i = 0; i < length; i++)
	{
		x = start_x + (i * dx);
		y = start_y + (i * dy);
		if (x >= 0 && x < WINDOWSIZE && y >= 0 && y < WINDOWSIZE)
			my_mlx_pixel_put(img, start_x + (i * dx), start_y + (i * dy), color);
	}
}

