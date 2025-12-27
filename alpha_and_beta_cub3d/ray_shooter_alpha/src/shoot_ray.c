/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:21:55 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 11:14:14 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	shoot_ray(t_img *img, double angle, int  pix_x, int pix_y, t_data *mlx)
{
	double		ray_length;
	double		cell_size;
	int			i;

	fill_img_with(BLACK, img);
	cell_size = (double) WINDOWSIZE / LINES;
	for (i = -45; i < 46; i++)
	{
		ray_length = calc_ray_length(((angle + i) / 180) * -M_PI, ((double) pix_x) / cell_size, ((double)  pix_y) / cell_size, mlx);
		draw_line(img, angle + i, (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->rays.img, 0, 0);
}

