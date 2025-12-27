/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:57:38 by zivanov           #+#    #+#             */
/*   Updated: 2025/12/27 14:03:34 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "..//mlx/mlx.h"

int	main(void)
{
	void *ptr;
	printf("oi ya fekker\n");
	ptr = mlx_init();
	if (ptr == NULL)
		printf("ppops\n");
	return (0);
}
