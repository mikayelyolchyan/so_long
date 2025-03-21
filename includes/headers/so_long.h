#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/get_next_line/get_next_line_bonus.h"
# include "../libraries/mlx_linux/mlx.h"

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
	int		tile_size;
	char	**map;
}	t_data;

void	create_map(char *filename, t_data *data);

int	read_map(int fd);
int	open_map(char *filename);
int	ft_exit(t_data *data);
int	ft_hotkey(int keycode, t_data *data);

#endif
