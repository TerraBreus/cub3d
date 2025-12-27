/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:44:41 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/25 09:33:17 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

bool	wall_collision(int x, int y, t_data *data)
{
	int	x_map;
	int	y_map;

	x_map = ((x * LINES) / WINDOWSIZE);
	y_map = ((y * LINES) / WINDOWSIZE);

	if (out_of_bounds(x_map, y_map))
		return (true);
	if (data->map[x_map][y_map] == 1)
		return (true);
	return (false);
}
