/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:57:38 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/28 11:36:03 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(void)
{
	t_mlx_data	mlx_data;

	if (init_data(&mlx_data) != 0)
		return (-1);
	//hook_events();
	mlx_loop(mlx_data.mlx);
	//clean_up();
	return (0);
}
