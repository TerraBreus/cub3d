/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:02:06 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 11:09:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	turn_player(float *dir, int keycode, t_data *data)
{
	 if (keycode == KEY_E)
		 *dir += ROT_SPEED;
	 else
		 *dir -= ROT_SPEED;
	 render_window(data, false);
}
