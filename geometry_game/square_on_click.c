/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_on_click.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terrabuntu <terrabuntu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:33:56 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/05 22:35:20 by terrabuntu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	square_on_click(int keycode, int x, int y, t_mlx *mlx)
{
	x = x * LINES / WINDOWSIZE;
	y = y * LINES / WINDOWSIZE;
	if (keycode == 1)
	{
		if (mlx->map[x][y] == 0)
		{
			printf("filling square on map[%i][%i]\n", x, y);
			fill_square(&(mlx->grid), x, y, BLUE);
			mlx->map[x][y] = 1;
		}
		else
		{
			fill_square(&(mlx->grid), x, y, BLACK);
			mlx->map[x][y] = 0;
		}
		draw_grid(&(mlx->grid), LINES);
		merge_images_and_push_to_window(mlx);
	}
	(void) mlx;
	return (0);
}
