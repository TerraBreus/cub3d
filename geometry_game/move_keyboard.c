/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terrabuntu <terrabuntu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:39:47 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/06 17:07:52 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

int	move_keyboard(int keycode, t_mlx *mlx)
{
	printf("\n\nkeycode %i\n", keycode);
	if (keycode == UP)
		mlx->keyboard_pos[1]--;
	else if (keycode == DOWN)
		mlx->keyboard_pos[1]++;
	else if (keycode == LEFT)
		mlx->keyboard_pos[0]--;
	else if (keycode == RIGHT)
		mlx->keyboard_pos[0]++;
	
	else if (keycode == 108)
		draw_line_between_points(&(mlx->cursors), mlx->keyboard_pos, mlx->mouse_pos, mlx);
	draw_keyboard(&(mlx->cursors), mlx->keyboard_pos);
	merge_images_and_push_to_window(mlx);
	return (0);
}
