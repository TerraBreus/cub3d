/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfenstein.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:27:33 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/25 11:20:48 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	create_background(t_img *img)
{
	int	i;
	int	j;

	for (i = 0; i < (WINDOWSIZE) - 1; i++)
	{
		for (j = 0; j < (WINDOWSIZE / 2) - 1; j++)
			my_mlx_pixel_put(img, i, j, BLUE);
	}
	for (i = 0; i < (WINDOWSIZE) - 1; i++)
	{
		for (j = (WINDOWSIZE / 2) - 1; j < (WINDOWSIZE) - 1; j++)
			my_mlx_pixel_put(img, i, j, GRAY);
	}
}

static int convert_to_vert_line(double ray_length)
{
	int	some_fact;
	double	cell_size;

	cell_size = (double) WINDOWSIZE / LINES;
	some_fact = (int) 10 * (cell_size / ray_length);

	if (some_fact > (WINDOWSIZE / 2))
			some_fact = WINDOWSIZE / 2;
	return (some_fact);
}

void	wolfenstein(t_img *img, double angle, int  pix_x, int pix_y, t_data *mlx)
{
	double		dr;
	double		ray_length;
	double		cell_size;
	int			screen_length;
	int			i;

	create_background(img);
	dr = (double) (FOV) / WINDOWSIZE;
	cell_size = (double) WINDOWSIZE / LINES;
	for (i = -(WINDOWSIZE / 2); i < (WINDOWSIZE / 2) - 1; i++)
	{
		ray_length = calc_ray_length(((angle + (i * dr)) / 180) * -M_PI, ((double) pix_x) / cell_size, ((double)  pix_y) / cell_size, mlx);
		screen_length = convert_to_vert_line(ray_length);
		//draw_line(img, angle + (i * dr), (int) (ray_length * cell_size), pix_x, pix_y, ORANGE);
		draw_line(img, 90, screen_length / 2, i + (WINDOWSIZE / 2), (WINDOWSIZE / 2), WHITE);
		draw_line(img, -90, screen_length / 2, i + (WINDOWSIZE / 2), (WINDOWSIZE / 2), WHITE);
	}
}
