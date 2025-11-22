/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:43:14 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 12:29:48 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WINDOWSIZE, WINDOWSIZE, "let him cook");
	my_mlx_create_image(data->mlx, &(data->grid), WINDOWSIZE);
	init_grid(data);
	my_mlx_create_image(data->mlx, &(data->user.img), WINDOWSIZE / 100);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->grid.img, 0, 0);
}
