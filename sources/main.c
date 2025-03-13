#include "so_long.h"

int	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("MiniLibX initialization Error\n", 1);
		return (1);
	}
	data->win = mlx_new_window(data->mlx, 1024, 1024, "PACMAN");
	if (!data->win)
	{
		ft_putstr_fd("Window creating Error\n", 1);
		return (1);
	}
	data->x = 512;
	data->y = 512;
	return (0);
}

int	main(void)
{
	t_data	data;

	if (start_game(&data) == 1)
		return (1);
	mlx_string_put(data.mlx, data.win, data.x, data.y, 0xFFFFFF, "PACMAN");
	mlx_hook(data.win, 17, 1L << 2, ft_exit, &data);
	mlx_key_hook(data.win, ft_hotkey, &data);
	mlx_loop(data.mlx);
	return (0);
}
