/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:05:04 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/22 12:26:52 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	init_grid(t_data *data)
{
	int	i;
	int	j;

	for (i = 0; i < LINES; i++)
	{
		for (j = 0; j < LINES; j++)
		{
			if (i == 0 || j == 0 || i == LINES - 1 || j == LINES - 1)
			{
				data->map[i][j] = 1;
				fill_square(&(data->grid), i, j, MAGENTA);
			}
			else
				data->map[i][j] = 0;
		}
	}
}
