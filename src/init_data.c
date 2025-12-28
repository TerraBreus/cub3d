/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:09:49 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/28 11:27:18 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	init_data(t_data *data)
{

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WINDOWLENGTH, WINDOWHEIGHT, "cub3d");
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx);
		return (-1);
	}
	return (0);
}
