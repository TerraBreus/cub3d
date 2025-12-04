/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfenstein_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:19:49 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/04 09:52:42 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	wolfenstein_tex(t_tex *tex, t_img *img, t_data *data, t_user *user)
{
	t_ray	ray;
	int		i;
	double	angle;
	double	dr;

	double	user_dir;
	int		user_x;
	int		user_y;

	dr = (double) FOV / WINDOWSIZE;
	for (i = 0; i < WINDOWSIZE; i++)
	{ 
		//-45 to 45 degrees (though in degree) with respect to the users original direction
		angle = (((i - ((double) WINDOWSIZE / 2)) * dr) + user->direction) * (M_PI / 180);
		//calc_ray_with_tex(&ray, angle, user_x, user_y, data);			TODO
		//draw_tex_line(&ray, img);										TODO

	}
}
