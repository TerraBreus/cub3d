/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:10:23 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/06 15:10:40 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/geo.h"

void	draw_mouse(t_data *img, int pos[2])
{
	int			i;
	static int	old_pos[2];

	for (i = 0; i < 10; i++)
		draw_line(img, 0, 10, old_pos[0], old_pos[1] + i, BLACK);

	for (i = 0; i < 10; i++)
		draw_line(img, 0, 10, pos[0] - 5, pos[1] - 5 + i, GREEN);
	old_pos[0] = pos[0] - 5;
	old_pos[1] = pos[1] - 5;
}
