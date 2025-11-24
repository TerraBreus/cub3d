/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:00 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 16:17:35 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int mouse_click(int keycode, int x, int y, t_data *data)
{
	if (keycode == 1)
		square_on_click(x, y, data);
	return (0);
}

