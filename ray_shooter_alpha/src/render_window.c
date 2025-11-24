/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:17:14 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 18:31:21 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	render_window(t_data *data, bool ray)
{
	if (ray == true)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->rays.img, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->grid.img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->user.img.img, (int) data->user.pos[0], (int) data->user.pos[1]);
	}
}
	
