/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:42:24 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/07 17:17:10 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

unsigned int	get_pixel_color(t_img *data, int x, int y)
{
	char *dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*) dst);
}

void	draw_tex_line(t_img *img, t_tex *tex, t_ray *ray, int i)
{
	int		which_line;
	double		step_size;
	int		j;
	unsigned int	temp;
	
	which_line = ray->pos_wall_hit * tex->width;
	step_size = (double) tex->height / ray->pixel_length;

	for (j = -(ray->pixel_length / 2); j < (ray->pixel_length / 2); j++)
	{
		temp = get_pixel_color(&tex->img, which_line,(int) (j + ((double) ray->pixel_length / 2)) * step_size);
		my_mlx_pixel_put(img, i, (WINDOWSIZE / 2) + j, temp);
	}
}

