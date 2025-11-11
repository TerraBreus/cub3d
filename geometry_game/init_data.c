/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terrabuntu <terrabuntu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:52:23 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/05 22:40:59 by terrabuntu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	init_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOWSIZE, WINDOWSIZE, "hours of my time wasted...");
	mlx->keyboard_pos[0] = WINDOWSIZE / 2;
	mlx->keyboard_pos[1] = WINDOWSIZE / 2;
	my_mlx_create_image(mlx->mlx, &(mlx->ui));
	my_mlx_create_image(mlx->mlx, &(mlx->cursors));
	my_mlx_create_image(mlx->mlx, &(mlx->grid));
	return (0);
}

