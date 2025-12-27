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

void	create_matrix(t_mlx *mlx)
{
	int	i;
	int	j;
	for (i = 0; i < LINES; i++)
	{
		for (j = 0; j < LINES; j++)
			mlx->map[i][j] = 0;
	}
}

int	init_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOWSIZE, WINDOWSIZE, "hours of my time wasted...");
	mlx->keyboard_pos[0] = WINDOWSIZE / 2;
	mlx->keyboard_pos[1] = WINDOWSIZE / 2;
	create_matrix(mlx);
	my_mlx_create_image(mlx->mlx, &(mlx->ui));
	my_mlx_create_image(mlx->mlx, &(mlx->cursors));
	my_mlx_create_image(mlx->mlx, &(mlx->grid));
	return (0);
}

