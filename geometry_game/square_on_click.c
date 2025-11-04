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
	printf("keycode %i\n x %i y: %i\n", keycode, x, y);
	if (keycode == 1)
	{
		fill_square(mlx->img, x, y);
		printf("%i and %i\n", x, y);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	}
	(void) mlx;
	return (0);
}
