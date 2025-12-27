/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:45:26 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/03 15:55:00 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

// Will draw a NxN matrix based on the dimension of the window.

void	draw_grid(t_data *img, int n)
{
	int		i;
	int		offset;

	offset = WINDOWSIZE / n;

	for (i = 1; i <= n; i++)
	{
		draw_line(img, 0, WINDOWSIZE, 0, i * offset, GRAY);
		draw_line(img, 90, WINDOWSIZE, i * offset, 0, GRAY);
	}
}

