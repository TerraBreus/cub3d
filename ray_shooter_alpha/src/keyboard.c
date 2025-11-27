/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:53 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 11:08:47 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//portable PC/laptop with docking

#include "../inc/ray.h"

static void	toggle_wolfenstein(t_data *data)
{
	render_window(data, true);
}

int keyboard(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		move_player(data->user.pos, keycode, data);
	else if (keycode == KEY_R)
		shoot_ray(&data->rays, 0, data->user.pos[0], data->user.pos[1],  data);
	else if (keycode == ENTER)
		toggle_wolfenstein(data);
	else if (keycode == KEY_Q || keycode == KEY_E)
		turn_player(&data->user.direction, keycode, data);
	else
		printf("key:%i\n", keycode);
	return (0);
}
