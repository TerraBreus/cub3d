/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:27:32 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/03 14:28:02 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

void	draw_vert_lines(t_data *img)
{
	int		i;
	int		j;

	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < WINDOWSIZE; j++)
		{
			my_mlx_pixel_put(img, i * WINDOWSIZE / 10, j, 0x808080);
		}
	}
}
