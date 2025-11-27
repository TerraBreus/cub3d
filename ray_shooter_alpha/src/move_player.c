/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:43:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 17:32:35 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	move_player(float pos[2], int keycode, t_data *data)
{
	int	dx;
	int	dy;


	if (keycode == DOWN)
	{
		dx = cos((data->user.direction) * (M_PI / 180)) * MOVESPEED;
		dy = -sin((data->user.direction) * (M_PI / 180)) * MOVESPEED;
		if (wall_collision((int) pos[0] - dx, (int) pos[1] + dy - MOVESPEED, data))
			return ;
		if (wall_collision((int) pos[0] + USERSIZE - dx, (int) pos[1] + dy - MOVESPEED, data))
			return ;
		pos[1] += dy;
		pos[0] -= dx;
	}
	else if (keycode == UP)
	{
		dx = cos((data->user.direction) * (M_PI / 180)) * MOVESPEED;
		dy = -sin((data->user.direction) * (M_PI / 180)) * MOVESPEED;
		if (wall_collision(pos[0] + dx, pos[1] - dy + MOVESPEED + USERSIZE, data))
			return ;
		if (wall_collision(pos[0] + dx + USERSIZE, pos[1] - dy + MOVESPEED + USERSIZE, data))
			return ;
		pos[1] -= dy;
		pos[0] += dx;

	}
	else if (keycode == RIGHT)
	{
		dx = cos((data->user.direction + 90) * (M_PI / 180)) * MOVESPEED;
		dy = -sin((data->user.direction + 90) * (M_PI / 180)) * MOVESPEED;
		if (wall_collision(pos[0] + dx - MOVESPEED, pos[1] - dy + USERSIZE, data))
			return ;
		if (wall_collision(pos[0] - MOVESPEED + dx, pos[1] - dy, data))
			return ;
		pos[1] -= dy;
		pos[0] += dx;
	}
	else if (keycode == LEFT)
	{
		dx = cos((data->user.direction + 90) * (M_PI / 180)) * MOVESPEED;
		dy = -sin((data->user.direction + 90) * (M_PI / 180)) * MOVESPEED;
		if (wall_collision(pos[0] + MOVESPEED + USERSIZE - dx, pos[1] + dy, data))
			return ;
		if (wall_collision(pos[0] + MOVESPEED + USERSIZE - dx, pos[1] + USERSIZE + dy, data))
			return ;
		pos[1] += dy;
		pos[0] -= dx;
	}
	render_window(data, false);
}


