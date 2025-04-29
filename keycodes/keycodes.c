// cc -o to_run keycodes.c -I mlx_linux -L mlx_linux -lmlx_Linux -lXext -lX11

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	key_hook(int keycode, void *param)
{
	(void)param;
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		fprintf(stderr, "Error initializing MLX\n");
		return (1);
	}
	win = mlx_new_window(mlx, 800, 600, "Universal Keycode Viewer");
	if (!win)
	{
		fprintf(stderr, "Error creating window\n");
		return (1);
	}
	mlx_key_hook(win, key_hook, NULL);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}
