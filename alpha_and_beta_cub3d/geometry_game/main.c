/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terrabuntu <terrabuntu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:48:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/06 15:16:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	main(void)
{
	t_mlx	mlx;

	init_data(&mlx);
	draw_grid(&(mlx.grid), LINES);
	draw_keyboard(&(mlx.cursors), mlx.keyboard_pos);
	merge_images_and_push_to_window(&mlx);
	mlx_hook(mlx.mlx_win, BUTTONPRESS, (1L<<2), square_on_click, &mlx);
	mlx_hook(mlx.mlx_win, KEYPRESS, (1L<<0), move_keyboard, &mlx);
	mlx_hook(mlx.mlx_win, 06, (1L << 6), move_mouse, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
