/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:21:40 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 12:33:57 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	fill_square(t_img *img, int x, int y, int color)
{
	int		dimension_square;
	int		i;

	if (x / LINES != 0 || y / LINES != 0)
		return ; 
	dimension_square = WINDOWSIZE / LINES;

	for (i = 0; i <= dimension_square; i++)
		draw_line(img, 0, dimension_square, x * dimension_square, (y * dimension_square) + i, color);
}

