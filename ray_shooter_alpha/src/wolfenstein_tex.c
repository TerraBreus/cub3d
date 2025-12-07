/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfenstein_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:19:49 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/07 17:18:18 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	wolfenstein_tex(t_tex *tex, t_img *img, t_data *data, t_user *user)
{
	t_ray	ray;
	int		i;
	double	angle;
	double	dr;

	//double	user_dir;
	double		user_x;
	double		user_y;
	fill_img_with(BLACK, img);


	user_x = user->pos[0] * ((double) LINES / WINDOWSIZE);
	user_y = user->pos[1] * ((double) LINES / WINDOWSIZE);
	dr = (double) FOV / WINDOWSIZE;
	for (i = 0; i < WINDOWSIZE; i++)
	{ 
		//-45 to 45 degrees (though in degree) with respect to the users original direction
		angle = (((i - ((double) WINDOWSIZE / 2)) * dr) + user->direction) * (-M_PI / 180);
		calc_ray_with_tex(&ray, angle, user_x, user_y, data);
		draw_tex_line(img, tex, &ray, i);
	}
}
