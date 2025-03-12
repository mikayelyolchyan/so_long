#include "so_long.h"

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_putstr_fd("MiniLibX initialization Error\n", 1);
		return (1);
	}

	data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 1024, "Simple Window");
	if (!data.win_ptr)
	{
		ft_putstr_fd("Window creating Error\n", 1);
		return (1);
	}

	mlx_string_put(data.mlx_ptr, data.win_ptr, 512, 512, 0xFFFFFF, "PACMAN");
	
	mlx_hook(data.win_ptr, 17, 1L << 2, ft_exit, &data);
	mlx_key_hook(data.win_ptr, ft_hotkey, &data);
	
	mlx_loop(data.mlx_ptr);
	return (0);
}
