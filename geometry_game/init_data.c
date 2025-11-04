/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:52:23 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 21:37:06 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	init_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOWSIZE, WINDOWSIZE, "hours of my time wasted...");
	my_mlx_create_image(mlx->mlx, &(mlx->grid));
	my_mlx_create_image(mlx->mlx, &(mlx->ui));
	my_mlx_create_image(mlx->mlx, &(mlx->cursor));
	return (0);
}

