/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:58:03 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 13:07:42 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "inc/geo.h"

void	fill_square(t_data *img, int x, int y)
{
	int		dimension_square;
	int		i;

	if (x / LINES != 0 || y / LINES != 0)
		return ; 
	dimension_square = WINDOWSIZE / LINES;

	for (i = 0; i <= dimension_square; i++)
	{
		draw_line(img, 0, dimension_square, x * dimension_square, (y * dimension_square) + i, BLUE);
	}
}

