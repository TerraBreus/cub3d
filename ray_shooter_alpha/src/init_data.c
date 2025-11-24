/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:43:14 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 18:29:29 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WINDOWSIZE, WINDOWSIZE, "let him cook");
	my_mlx_create_image(data->mlx, &(data->grid), WINDOWSIZE);
	my_mlx_create_image(data->mlx, &(data->rays), WINDOWSIZE);
	init_grid(data);
	init_user(data->mlx, &(data->user));
	render_window(data, false);
}
