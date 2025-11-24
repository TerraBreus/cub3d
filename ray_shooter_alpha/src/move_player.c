/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:43:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 17:44:19 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	move_player(float pos[2], int keycode, t_data *data)
{
	if (keycode == UP)
	{
		if (!wall_collision((int) pos[0], (int) pos[1] - MOVESPEED, data))
			pos[1] -= MOVESPEED;
	}
	else if (keycode == DOWN)
	{

		if (!wall_collision(pos[0], pos[1] + MOVESPEED + USERSIZE, data))
			pos[1] += MOVESPEED;
	}
	else if (keycode == LEFT)
	{
		if (!wall_collision(pos[0] - MOVESPEED, pos[1], data))
			pos[0] -= MOVESPEED;
	}
	else if (keycode == RIGHT)
	{
		if (!wall_collision(pos[0] + MOVESPEED + USERSIZE, pos[1], data))
			pos[0] += MOVESPEED;
	}
	render_window(data, false);
}


