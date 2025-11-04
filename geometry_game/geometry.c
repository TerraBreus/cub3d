/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:48:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 17:35:45 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/geo.h"

int	main(void)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WINDOWSIZE, WINDOWSIZE, "waaaa");
	mlx.img = &img;
	img.img = mlx_new_image(mlx.mlx, WINDOWSIZE, WINDOWSIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_grid(&img, LINES);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_hook(mlx.mlx_win, BUTTONPRESS, (1L<<2), square_on_click, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
