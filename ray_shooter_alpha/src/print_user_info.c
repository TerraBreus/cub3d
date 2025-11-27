/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:53:38 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/27 16:57:17 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

void	print_user_info(t_data *data)
{
	printf("x: %f, \
			y: %f, \
			dir: %f\n", 
			data->user.pos[0], 
			data->user.pos[1], 
			data->user.direction);
}
