/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:05:20 by zivanov           #+#    #+#             */
/*   Updated: 2025/11/03 14:29:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#define WINDOWSIZE 1000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// F U N C T I O N S
void	draw_hori_lines(t_data *img);
void	draw_vert_lines(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
