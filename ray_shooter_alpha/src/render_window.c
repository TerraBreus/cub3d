/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:17:14 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/04 09:26:13 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	render_window(t_data *data, bool change_ray)
{
	static bool	ray = false;

	if (change_ray == true)
	{
		if (ray == false)
			ray = true;
		else
			ray = false;
		printf("Change_ray has been switched to %b\n", change_ray);
	}
	if (ray == true)
	{
		wolfenstein(&data->rays, data->user.direction, data->user.pos[0], data->user.pos[1],  data);
		//wolfenstein_tex();
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->rays.img, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->grid.img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->user.img.img, (int) data->user.pos[0], (int) data->user.pos[1]);
	}
}
	
