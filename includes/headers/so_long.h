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
//# define W 1731
//# define A 1734
//# define S 1753
//# define D 1751
# define STOP 0
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

# define GHOST_NEUTRAL_LIMIT 131072
# define GHOST_ATTACK_LIMIT 524288
# define GAME_FRAME_LIMIT 256
# define GAME_START_LIMIT 20000
# define GHOST_EATEN_FREEZE 15000
# define DYING_FRAME_LIMIT 12500
# define GHOST_PANIC_LIMIT 128
# define GHOST_PANIC_FLASHING_LIMIT 196

typedef struct s_dist
{
	int dist_up;
    int dist_left;
    int dist_down;
    int dist_right;
	int min_dist;
	int	max_dist;
}	t_dist;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_check
{
	int	coins;
	int	power_ups;
	int	exits;
	int	portals;
	int	ghost_count;
}	t_check;

typedef struct s_portal
{
	int		x;
	int		y;
}	t_portal;

typedef struct s_font
{
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*zero;
}	t_font;

typedef struct s_power_up_dot
{
	int		x;
	int		y;
}	t_power_up_dot;

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
	void	*dying1;
	void	*dying2;
	void	*dying3;
	void	*dying4;
	void	*dying5;
	void	*dying6;
	void	*dying7;
	void	*dying8;
	void	*dying9;
	void	*dying10;
	void	*woosh;
	int		dying_frame;
	int		dying_frame_delay;
	int		direction;
	int		pending_direction;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		start_x;
	int		start_y;
	int		move_count;
	int		died_count;
	char	*move_str;
}	t_player;

typedef struct s_map
{
	int				x;
	int				y;
	int				width;
	int				height;
	int				tile_size;
	int				ghost_count;
	void			*wall_img;
	void			*black_wall_img;
	void			*white_wall_img;
	void			*red_wall_img;
	void			*food_img;
	void			*portal_img;
	void			*logo_img;
	void			*power_up_img;
	void			*exit_img;
	char			**map;
	int				dots_count;
	int				power_up_dots_count;
	t_power_up_dot	*power_up_dots_array;
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
	int			pac_attack_mode_delay;
	int			power_up_img_delay;
	int			map_flashing_frame;
	int			map_flashing_delay;
	int			map_flashing_count;
	int			game_start;
	int			game_start_delay;
	int			game_win;
	int			game_restart;
	int			score;
	char		*score_str;
	int			eated_dots;
	t_map		*map;
	t_player	*player;
	t_ghost		*r_ghost;
	t_ghost		*o_ghost;
	t_ghost		*m_ghost;
	t_ghost		*b_ghost;
	t_font		*font;
	t_portal	portal[2];
	t_check		*check;
}	t_game;

/* File validation */
int		check_extension(char *filename);

/* Map reading */
int		read_map(char *filename, t_map *map);

/* Map validation */
int		check_structure(t_map *map);
int		check_elements(t_map *map, t_point *start, t_check *total);
int		validate_map(char *filename, t_map *map);

/* Flood fill */
void	flood_fill(t_map *map, t_point pos, t_check *reached, int **visited);

/* Memory utils */
int		**create_visited(int height, int width, int i);
void	free_visited(int **visited, int height);
void	free_map(t_map *map);

void	game_over(t_game *game);
void	game_restart(t_game *game);
void	game_win(t_game *game);

void	map_flashing(t_map *map, t_game *game);
void	draw_map(t_game *game);
void	update_map(t_game *game, char **map);
void	update_ghost(t_game *game, char **map, int direction, t_ghost *ghost);
void	update_player(t_game *game, char **map, t_player *player);
void	render_power_up_dots(t_game *game);

void	find_positions(t_game *game);

void	set_portal_position(t_game *game, int x, int y);
void	set_power_up_position(t_map *map, int x, int y, int *power_up_index);
void	set_ghost_position(t_ghost *ghost, int x, int y, int tile_size);
void	set_player_position(t_game *game, int x, int y);

int		distance_calculator(int x1, int x2, int y1, int y2);

int		ft_exit(t_game *game);

int		ft_hotkey(int keycode, t_game *game);

int		game_animation(t_game *game);
void	pac_dying_and_restart(t_game *game);

void	count_sprites(t_game *game);

void	font_initialization(t_game *game);

void	display_score(t_game *game);
void	display_move(t_game *game);

void	*get_pac_vertical_animation(t_game *game, t_player *player);
void	*get_pac_horizontal_animation(t_game *game, t_player *player);
void	*get_pac_current_img(t_game *game, t_player *player);
void	update_pac_direction(t_game *game);

void	pac_move_mode(t_game *game);
void	pac_dying(t_game *game, t_player *player);
void	pac_moving(t_game *game);
void	pac_moving_up_down(t_game *game);
void	pac_moving_left_right(t_game *game);
void	pac_fast_moving(t_game *game);
void	pac_fast_moving_up_down(t_game *game);
void	pac_fast_moving_left_right(t_game *game);
void	handle_collectibles(t_game *game);
void	handle_pac_portal(t_game *game, int portal_index);

int		can_move_fast_horizontal(t_ghost *c_ghost, char **map, int direction);
int		can_move_fast_vertical(t_ghost *c_ghost, char **map, int direction);
int		can_move_horizontal(t_ghost *c_ghost, char **map, int direction);
int		can_move_vertical(t_ghost *c_ghost, char **map, int direction);

void	*get_ghost_horizontal_animation(t_game *game, t_ghost *c_ghost);
void	*get_ghost_vertical_animation(t_game *game, t_ghost *c_ghost);
void	*get_ghost_current_img(t_game *game, t_ghost *c_ghost);
void	*get_ghost_panic_animation(t_game *game, t_ghost *c_ghost);
void	*get_ghost_panic_flashing_animation(t_game *game, t_ghost *c_ghost);

void	handle_ghost_portal(t_game *game, t_ghost *c_ghost, int portal_index);

void	pacman_initializations(t_game *game, t_map *map);
void	ghost_panic_textures(t_game *game, t_map *map, t_ghost *c_ghost);
void	red_ghost_initialization(t_game *game, t_map *map);
void	orange_ghost_initialization(t_game *game, t_map *map);
void	magenta_ghost_initialization(t_game *game, t_map *map);
void	blue_ghost_initialization(t_game *game, t_map *map);
void	map_initialization(t_game *game, t_map *map);

int		start_game(t_game *game, char *argv);
int		init_map(char *argv, t_map **map);
int		init_mlx(t_game *game, t_map *map);
int		init_map_images(t_game *game, t_map *map);
int		init_player(t_game *game, t_map *map);
int		init_ghosts(t_game *game, t_map *map);
int		init_power_up_dots(t_game *game, t_map *map);
int		init_ghost_positions_textures(t_game *game, t_map *map);
int		init_font(t_game *game, t_map *map);
void	init_game_state(t_game *game, t_map *map);

void	red_ghost_moving(t_game *game);
void	red_ghost_direction(t_game *game);
void	set_red_ghost_target(t_game *game, t_ghost *ghost);
void	red_ghost_respawned(t_game *game, t_ghost *ghost);

void	blue_ghost_moving(t_game *game);
void	blue_ghost_direction(t_game *game);
void	set_blue_ghost_target(t_game *game);
void	blue_ghost_respawned(t_game *game, t_ghost *ghost);

void	magenta_ghost_moving(t_game *game);
void	magenta_ghost_direction(t_game *game);
void	set_magenta_ghost_target(t_game *game, t_ghost *ghost);
void	magenta_ghost_respawned(t_game *game, t_ghost *ghost);

void	orange_ghost_moving(t_game *game);
void	orange_ghost_direction(t_game *game);
void	set_orange_ghost_target(t_game *game, t_ghost *ghost);
void	orange_ghost_respawned(t_game *game, t_ghost *ghost);

void	calculating_to_start(t_game *game, t_dist *dist, t_ghost *ghost);
void	calculating_to_target(t_game *game, t_dist *dist, t_ghost *ghost);

void	set_dist_struct_variables(t_dist *dist);
void	ghost_move(t_game *game, t_ghost *ghost);
void	ghost_is_eaten_move(t_game *game, t_ghost *ghost);
void	set_ghost_direction(t_game *game, t_ghost *ghost);
void	handle_dead_end_turn(t_game *game, t_ghost *ghost);
void	detect_collision_with_speed(t_game *game, t_ghost *ghost, char **map);
void	when_pac_eated_ghost(t_game *game, t_ghost *ghost);
void	when_ghost_eated_pac(t_game *game, t_ghost *ghost);
void	check_ghost_attack_mode(t_game *game);
void	direction_when_ghost_eated(t_ghost *ghost, t_dist *dist);
void	ghost_direction(t_ghost *ghost, t_dist *dist);
void	direction_when_ghost_in_panic(t_ghost *ghost, t_dist *dist);

#endif
