/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 08:58:47 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/24 16:17:35 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

int	main(void)
{
	t_data	data;

	init_data(&data);
	mlx_hook(data.mlx_win, KEYPRESS, (1L<<0), keyboard, &data);
	mlx_hook(data.mlx_win, BUTTONPRESS, (1L<<2),mouse_click , &data);
	mlx_loop(data.mlx);
	return (0);
}
