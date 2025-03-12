#include "so_long.h"

int	ft_hotkey(int keycode, t_data *data)
{
	if (keycode == W)
		data->y -= 10;
	else if (keycode == S)
        	data->y += 10;
	else if (keycode == A)
		data->x -= 10;
	else if (keycode == D)
		data->x += 10;	
	else if (keycode == 65307) // Esc
		exit(0);

    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    mlx_string_put(data->mlx_ptr, data->win_ptr, data->x, data->y, 0xFFFFFF, "C");
    return (0);
}
