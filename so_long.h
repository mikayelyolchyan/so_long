#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx_linux/mlx.h"

# define ESC 65307
# define W   13

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	x;
	int	y;
}	t_data;

int	ft_hotkey(int keycode, t_data *data);
int	ft_exit(t_data *data);

#endif
