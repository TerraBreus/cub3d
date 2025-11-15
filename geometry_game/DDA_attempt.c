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

void	cast_ray(t_data *img, float angle, int pix_x, int pix_y)
{
	double	nxt_vline;
	double	dist_vline;
	double	dist_hline;
	double	nxt_hline;
	int		cell_size;
	double	pos_x;
	double	pos_y;

	cell_size = (WINDOWSIZE / LINES);
	pos_x = ((double) pix_x / cell_size);
	pos_y = ((double) pix_y / cell_size);
	dist_vline = 1;
	dist_hline = 1;
	nxt_hline = fmod(pos_y, dist_hline);
	nxt_vline = fmod(pos_x, dist_vline);
	if (angle > -90 && angle < 90)
		nxt_vline = dist_vline - nxt_vline;
	printf("angle %f, pos_x; %f nxt: %f\n", angle, pos_x, nxt_vline);
	if (angle > 0 && angle < 180)
		nxt_hline = 1 - nxt_hline;
	printf("angle %f, pos_y; %f nxt: %f\n", angle, pos_y, nxt_hline);
	draw_line(img, 0, (int) (nxt_vline * cell_size), pix_x, pix_y, RED);
	(void) pix_y;
	(void) img;
}
