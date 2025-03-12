#include "so_long.h"

int	ft_exit(t_data *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
}
