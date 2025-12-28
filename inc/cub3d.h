/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:07:29 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/28 11:46:44 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define WINDOWHEIGHT 720
#define WINDOWLENGTH 1280

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_h;
	int		win_l;
}	t_mlx_data;

int		init_data(t_mlx_data *data);
