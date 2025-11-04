/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_on_click.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:33:56 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 17:36:03 by zivanov          ###   ########.fr       */
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
			fill_square(mlx->img, x, y, BLUE);
			mlx->map[x][y] = 1;
		}
		else
		{
			fill_square(mlx->img, x, y, BLACK);
			mlx->map[x][y] = 0;
		}
		draw_grid(mlx->img, LINES);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	}
	(void) mlx;
	return (0);
}
