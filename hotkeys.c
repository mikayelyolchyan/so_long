#include "so_long.h"

int	ft_hotkey(int keycode, t_data *vars)
{
	if (keycode == ESC)
		ft_exit(vars);
	return (0);
}
