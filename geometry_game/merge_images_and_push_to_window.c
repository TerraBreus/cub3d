#include "inc/geo.h"

int	merge_images_and_push_to_window(t_mlx *mlx)
{
	//merge cursor and background to ui.
	int				x;
	int				y;
	unsigned int	temp_color;

	for (x = 0; x < WINDOWSIZE; x++)
	{
		for (y = 0; y < WINDOWSIZE; y++)
		{
			temp_color = get_pixel_color(&(mlx->keyboard), x, y); 
			if (temp_color == BLACK)
			{
				temp_color = get_pixel_color(&(mlx->mouse), x, y);
				if (temp_color == BLACK)
					temp_color = get_pixel_color(&(mlx->grid), x, y);
			}
			my_mlx_pixel_put(&(mlx->ui), x, y, temp_color);
		}		
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ui.img, 0, 0);
	return (0);
}
