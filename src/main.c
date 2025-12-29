/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:57:38 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/28 13:54:57 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"



int	main(void)
{
	t_mlx_data	mlx_data;
	t_input		input;

	if (init_data(&mlx_data) != 0)
		return (-1);
	//TEST MAP MUST BE REMOVED LATER ON!
	input.map = create_square_test_map(10);
	//hook_events();
	mlx_loop(mlx_data.instance);
	//clean_up();
	return (0);
}
