/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:25:41 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/01 12:57:11 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	my_mlx_get_data_addr(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	init_tex(t_data *data)
{
	data->tex.img.img = mlx_xpm_file_to_image(data->mlx, "./textures/5x5grid.xpm", &data->tex.width, &data->tex.height);
	if (data->tex.img.img == NULL)
		printf("something went wrong with loading textures\n");
	else
	{
		my_mlx_get_data_addr(&data->tex.img);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->tex.img.img, 0, 0);
		printf("Render of texture to be used. Width: %i, Height: %i\nPress enter in terminal to continue game\n", data->tex.width, data->tex.height);
		scanf("aha");
	}
}
