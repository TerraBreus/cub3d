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
	int		cell_size;
	double	pos_x;

	cell_size = (WINDOWSIZE / LINES);
	pos_x = ((double) pix_x / cell_size);
	dist_vline = 1;
	nxt_vline = fmod(pos_x, dist_vline);
	if (angle > -90 && angle < 90)
		nxt_vline = dist_vline - nxt_vline;
	printf("angle %f, pos_x; %f nxt: %f\n", angle, pos_x, nxt_vline);
	(void) pix_y;
	(void) img;
}
