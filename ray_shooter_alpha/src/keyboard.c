/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:53 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 17:46:19 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//portable PC/laptop with docking

#include "../inc/ray.h"

int keyboard(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		move_player(data->user.pos, keycode, data);
	else
		printf("key:%i\n", keycode);
	return (0);
}
