/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:29:55 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 10:00:27 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

static void	fill_user(t_img *img)
{
	int	i;
	int	j;
	for (i = 0; i < USERSIZE; i++)
	{
		for (j = 0; j < USERSIZE; j++)
			my_mlx_pixel_put(img, i, j, GREEN);
	}
}

void	init_user(void *mlx, t_user *u)
{
	u->pos[1] = (float) WINDOWSIZE / 2;
	u->pos[0] = (float) WINDOWSIZE / 2;
	u->direction = 90;
	my_mlx_create_image(mlx, &(u->img), USERSIZE);
	fill_user(&(u->img));
}
