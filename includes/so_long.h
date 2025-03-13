#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100 

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_data;

int	ft_exit(t_data *data);
int	ft_hotkey(int keycode, t_data *data);

#endif
