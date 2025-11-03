/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:48:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/03 15:02:55 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/geo.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOWSIZE, WINDOWSIZE, "waaaa");
	img.img = mlx_new_image(mlx, WINDOWSIZE, WINDOWSIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_vert_lines(&img);
	draw_hori_lines(&img);
	draw_line(&img, 180, WINDOWSIZE / 10, WINDOWSIZE / 2, 0, RED);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
