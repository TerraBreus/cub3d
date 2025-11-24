/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_on_click.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:41:01 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 11:45:21 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	square_on_click(int x, int y, t_data *data)
{
	x = x * LINES / WINDOWSIZE;
	y = y * LINES / WINDOWSIZE;
	if (data->map[x][y] == 0)
	{
		printf("filling square on map[%i][%i]\n", x, y);
		fill_square(&(data->grid), x, y, MAGENTA);
		data->map[x][y] = 1;
	}
	else
	{
		fill_square(&(data->grid), x, y, BLACK);
		data->map[x][y] = 0;
	}
	render_window(data, false);
}
