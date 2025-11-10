
#include "inc/geo.h"

void	draw_keyboard(t_data *img, int pos[2])
{
	int			i;
	static int	old_pos[2];

	for (i = 0; i < 10; i++)
		draw_line(img, 0, 10, old_pos[0], old_pos[1] + i, BLACK);

	for (i = 0; i < 10; i++)
		draw_line(img, 0, 10, pos[0], pos[1] + i, RED);
	old_pos[0] = pos[0];
	old_pos[1] = pos[1];
}
	
