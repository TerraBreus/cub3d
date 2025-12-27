/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_with.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:21:28 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/25 09:24:41 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	fill_img_with(int color, t_img *img)
{
	int	i;
	int	j;

	for (i = 0; i < WINDOWSIZE; i++)
	{
		for (j = 0; j < WINDOWSIZE; j++)
			my_mlx_pixel_put(img, i, j, color);
	}
}
