/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:41 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 17:45:07 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

bool	wall_collision(int x, int y, t_data *data)
{
	int	x_map;
	int	y_map;

	x_map = ((x * LINES) / WINDOWSIZE);
	y_map = ((y * LINES) / WINDOWSIZE);

	if (x_map > LINES - 1 || y_map > LINES - 1)
		return (true);
	if (data->map[x_map][y_map] == 1)
		return (true);
	return (false);
}
