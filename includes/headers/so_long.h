#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/get_next_line/get_next_line_bonus.h"
# include "../libraries/mlx_linux/mlx.h"

# include <math.h>
# include <limits.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define STOP 0
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

typedef struct s_power_up_dot {
    int x;
    int y;
} t_power_up_dot;

typedef struct s_ghost
{
	void	*ghost_up1;
	void	*ghost_up2;
	void	*ghost_down1;
	void	*ghost_down2;
	void	*ghost_left1;
	void	*ghost_left2;
	void	*ghost_right1;
	void	*ghost_right2;
	void	*ghost_panic1a;
	void	*ghost_panic1b;
	void	*ghost_panic2a;
	void	*ghost_panic2b;
	void	*ghost_is_eaten_right;
	void	*ghost_is_eaten_left;
	void	*ghost_is_eaten_up;
	void	*ghost_is_eaten_down;
	int		is_eaten;
	int		is_respawned;
	int		direction;
	int		pending_direction;
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		targ_x;
	int		targ_y;
	int		remainder_x;
	int		remainder_y;
}	t_ghost;

typedef struct s_player
{
	void	*pac_open_right;
	void	*pac_open_left;
	void	*pac_open_down;
	void	*pac_open_up;
	void	*pac_semi_right;
	void	*pac_semi_left;
	void	*pac_semi_down;
	void	*pac_semi_up;
	void	*pac_closed;
	void	*pac_black;
	int	direction;
	int	pending_direction;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
	int	start_x;
	int	start_y;
}	t_player;

typedef struct s_map
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	tile_size;
	void	*wall_img;
	void	*black_wall_img;
	void	*food_img;
	void	*portal_img;
	void	*logo_img;
	void	*power_up_img;
	char	**map;

	int		dots_count;
	int				power_up_dots_count;
	t_power_up_dot 	*power_up_dots_array;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			frame;
	int			frame_delay;
	int			ghost_attack_mode;
	int			ghost_attack_mode_delay;
	int			pac_attack_mode;
	int			last_pac_attack_mode;
	int 		pac_attack_mode_delay;
	int			power_up_img_delay;
	int			score;

	char		*score_str;

	t_map		*map;
	t_player	*player;
	t_ghost		*r_ghost;
	t_ghost		*o_ghost;
	t_ghost		*m_ghost;
	t_ghost		*b_ghost;
}	t_game;

int	open_map(char *filename);
int	read_map(int fd);

void	fill_map(t_map *map, int fd);
void	create_map(char *filename, t_game *game);

void	find_positions(t_game *game);

int distance_calculator(int x1, int x2, int y1, int y2);

void	draw_map(t_game *game);

int		start_game(t_game *game);

int		ft_exit(t_game *game);

int		ft_hotkey(int keycode, t_game *game);

void	free_map(t_map *map);

int		game_animation(t_game *game);

void	update_map(t_game *game, char **map, int direction);

void	*get_pac_vertical_animation(t_game *game, t_player *player);
void	*get_pac_horizontal_animation(t_game *game, t_player *player);
void	*get_pac_current_img(t_game *game, t_player *player);
void 	pac_moving(t_game *game);
void	pac_fast_moving(t_game *game);
void	update_pac_direction(t_game *game);

void	*get_red_ghost_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_red_ghost_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	red_ghost_moving(t_game *game);
void	*get_red_ghost_panic_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_red_ghost_panic_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_red_ghost_panic_flashing_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_red_ghost_panic_flashing_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_red_ghost_current_img(t_game *game, t_ghost *r_ghost);

void	*get_orange_ghost_vertical_animation(t_game *game, t_ghost *o_ghost);
void	*get_orange_ghost_horizontal_animation(t_game *game, t_ghost *o_ghost);
void	orange_ghost_moving(t_game *game);
void	*get_orange_ghost_panic_vertical_animation(t_game *game, t_ghost *o_ghost);
void	*get_orange_ghost_panic_horizontal_animation(t_game *game, t_ghost *o_ghost);
void	*get_orange_ghost_panic_flashing_vertical_animation(t_game *game, t_ghost *o_ghost);
void	*get_orange_ghost_panic_flashing_horizontal_animation(t_game *game, t_ghost *o_ghost);
void	*get_orange_ghost_current_img(t_game *game, t_ghost *o_ghost);

void	*get_magenta_ghost_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_magenta_ghost_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	magenta_ghost_moving(t_game *game);
void	*get_magenta_ghost_panic_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_magenta_ghost_panic_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_magenta_ghost_panic_flashing_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_magenta_ghost_panic_flashing_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_magenta_ghost_current_img(t_game *game, t_ghost *r_ghost);

void	*get_blue_ghost_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_blue_ghost_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	blue_ghost_moving(t_game *game);
void	*get_blue_ghost_panic_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_blue_ghost_panic_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_blue_ghost_panic_flashing_vertical_animation(t_game *game, t_ghost *r_ghost);
void	*get_blue_ghost_panic_flashing_horizontal_animation(t_game *game, t_ghost *r_ghost);
void	*get_blue_ghost_current_img(t_game *game, t_ghost *r_ghost);

void	count_sprites(t_game *game);

#endif
