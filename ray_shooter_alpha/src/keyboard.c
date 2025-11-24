/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:53 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 16:18:22 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int keyboard(int keycode, t_data *data)
{
	if (keycode == UP)
		data->user.pos[1] -= MOVESPEED;
	else if (keycode == DOWN)
		data->user.pos[1] += MOVESPEED;
	else if (keycode == LEFT)
		data->user.pos[0] -= MOVESPEED;
	else if (keycode == RIGHT)
		data->user.pos[0] += MOVESPEED;
	else
		printf("key:%i\n", keycode);
	render_window(data, false);
	return (0);
}
