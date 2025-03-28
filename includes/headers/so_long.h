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

typedef struct s_player
{
	void	*player_img;
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	tile_size;
	void	*wall_img;
	char	**map;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_player *player;
}	t_game;

int	open_map(char *filename);
int	read_map(int fd);

void	fill_map(t_map *map, int fd);
void	create_map(char *filename, t_game *game);

void	draw_map(t_game *game);

int	start_game(t_game *game);

int	ft_exit(t_game *game);

int	ft_hotkey(int keycode, t_game *game);

void	free_map(t_map *map);

#endif
