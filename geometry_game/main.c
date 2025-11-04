/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:48:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/04 21:50:27 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/geo.h"

int	main(void)
{
	t_mlx	mlx;

	init_data(&mlx);
	draw_grid(&(mlx.grid), LINES);
	//draw_keyboard(&(mlx.cursor), mlx.keyboard);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.grid.img, 0, 0);
	mlx_hook(mlx.mlx_win, BUTTONPRESS, (1L<<2), square_on_click, &mlx);
	mlx_hook(mlx.mlx_win, KEYPRESS, (1L<<0), move_keyboard, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
