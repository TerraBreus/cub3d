/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:13:00 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/06 17:09:07 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	move_mouse(int x, int y, t_mlx *mlx)
{

	if (mlx->mouse_pos[0] != x || mlx->mouse_pos[1] != y)
	{
		mlx->mouse_pos[0] = x;
		mlx->mouse_pos[1] = y;
		draw_mouse(&(mlx->cursors), mlx->mouse_pos);
		merge_images_and_push_to_window(mlx);
	}
	return (0);
}
