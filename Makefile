NAME = so_long

CC = cc
C_FLAGS = -Wall -Wextra -Werror -I./$(INC_DIR) #-g3 -fsanitize=address

SRC_DIR = sources
INC_DIR = includes/headers
LIB_DIR = includes/libraries
MLX_DIR = $(LIB_DIR)/mlx_linux
LIBFT_DIR = $(LIB_DIR)/libft
FT_PRINTF_DIR = $(LIB_DIR)/ft_printf
GET_NEXT_LINE_DIR = $(LIB_DIR)/get_next_line

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/validation/check_elements_main.c \
	   $(SRC_DIR)/validation/check_elements_loop_utils1.c \
	   $(SRC_DIR)/validation/check_elements_loop_utils2.c \
	   $(SRC_DIR)/validation/flood_fill.c \
	   $(SRC_DIR)/validation/free.c \
	   $(SRC_DIR)/validation/is_space.c \
	   $(SRC_DIR)/validation/read_map.c \
	   $(SRC_DIR)/validation/read_map_store_lines.c \
	   $(SRC_DIR)/validation/validation_main_utils.c \
	   $(SRC_DIR)/validation/validation_main.c \
	   $(SRC_DIR)/validation/visitation.c \
	   $(SRC_DIR)/validation/cleanup_gnl.c \
       $(SRC_DIR)/game_over.c \
	   $(SRC_DIR)/game_restart.c \
	   $(SRC_DIR)/game_win.c \
       $(SRC_DIR)/hotkeys.c \
       $(SRC_DIR)/exit.c \
       $(SRC_DIR)/map/map_render.c \
       $(SRC_DIR)/map/map_render_utils_ghost.c \
	   $(SRC_DIR)/map/map_render_utils_pac.c \
       $(SRC_DIR)/map/map_flashing.c \
	   $(SRC_DIR)/map/render_power_dots.c \
       $(SRC_DIR)/game_animation.c \
       $(SRC_DIR)/count_sprites.c \
       $(SRC_DIR)/positions/find_positions.c \
	   $(SRC_DIR)/positions/set_positions.c \
       $(SRC_DIR)/ghosts/distance_calculator.c \
       $(SRC_DIR)/display.c \
       $(SRC_DIR)/pacman/pac_animation.c \
       $(SRC_DIR)/pacman/pac_current_img.c \
       $(SRC_DIR)/pacman/pac_fast_moving_left_right.c \
       $(SRC_DIR)/pacman/pac_fast_moving_up_down.c \
       $(SRC_DIR)/pacman/pac_fast_moving.c \
       $(SRC_DIR)/pacman/pac_moving_left_right.c \
       $(SRC_DIR)/pacman/pac_moving_up_down.c \
       $(SRC_DIR)/pacman/pac_moving.c \
       $(SRC_DIR)/pacman/pac_utils.c \
       $(SRC_DIR)/pacman/pac_dying.c \
	   $(SRC_DIR)/pacman/pac_dying_and_restart.c \
       $(SRC_DIR)/pacman/update_direction.c \
	   $(SRC_DIR)/ghosts/set_dist_struct_variables.c \
       $(SRC_DIR)/ghosts/ghost_can_move.c \
       $(SRC_DIR)/ghosts/ghost_animation.c \
       $(SRC_DIR)/ghosts/ghost_current_img.c \
       $(SRC_DIR)/ghosts/ghost_panic_animation.c \
       $(SRC_DIR)/ghosts/handle_ghost_portal.c \
	   $(SRC_DIR)/ghosts/detect_collision_with_speed.c \
	   $(SRC_DIR)/ghosts/ghost_move.c \
	   $(SRC_DIR)/ghosts/calculating_distance.c \
	   $(SRC_DIR)/ghosts/check_ghost_attack_mode.c \
	   $(SRC_DIR)/ghosts/direction_when_ghost_eated.c \
	   $(SRC_DIR)/ghosts/direction_when_ghost_in_panic.c \
	   $(SRC_DIR)/ghosts/ghost_direction.c \
	   $(SRC_DIR)/ghosts/set_ghost_direction.c \
	   $(SRC_DIR)/ghosts/when_ghost_eated_pac.c \
	   $(SRC_DIR)/ghosts/when_pac_eated_ghost.c \
	   $(SRC_DIR)/ghosts/handle_dead_end_turn.c \
	   $(SRC_DIR)/ghosts/red_ghost/red_ghost_target.c \
	   $(SRC_DIR)/ghosts/red_ghost/red_ghost_respawned.c \
       $(SRC_DIR)/ghosts/red_ghost/red_ghost_moving.c \
	   $(SRC_DIR)/ghosts/red_ghost/red_ghost_direction.c \
       $(SRC_DIR)/ghosts/blue_ghost/blue_ghost_moving.c \
	   $(SRC_DIR)/ghosts/blue_ghost/blue_ghost_direction.c \
	   $(SRC_DIR)/ghosts/blue_ghost/blue_ghost_respawned.c \
	   $(SRC_DIR)/ghosts/blue_ghost/blue_ghost_target.c \
	   $(SRC_DIR)/ghosts/orange_ghost/orange_ghost_respawned.c \
	   $(SRC_DIR)/ghosts/orange_ghost/orange_ghost_target.c \
       $(SRC_DIR)/ghosts/orange_ghost/orange_ghost_moving.c \
	   $(SRC_DIR)/ghosts/orange_ghost/orange_ghost_direction.c \
	   $(SRC_DIR)/ghosts/magenta_ghost/magenta_ghost_respawned.c \
	   $(SRC_DIR)/ghosts/magenta_ghost/magenta_ghost_target.c \
       $(SRC_DIR)/ghosts/magenta_ghost/magenta_ghost_moving.c \
	   $(SRC_DIR)/ghosts/magenta_ghost/magenta_ghost_direction.c \
	   $(SRC_DIR)/initializations/pac_initialization.c \
	   $(SRC_DIR)/initializations/ghost_panic_initialization.c \
	   $(SRC_DIR)/initializations/red_ghost_initialization.c \
	   $(SRC_DIR)/initializations/orange_ghost_initialization.c \
	   $(SRC_DIR)/initializations/blue_ghost_initialization.c \
	   $(SRC_DIR)/initializations/magenta_ghost_initialization.c \
	   $(SRC_DIR)/initializations/font_initialization.c \
	   $(SRC_DIR)/initializations/map_initialization.c \
	   $(SRC_DIR)/start_game/init_font.c \
	   $(SRC_DIR)/start_game/init_game_state.c \
	   $(SRC_DIR)/start_game/init_ghost_position_textures.c \
	   $(SRC_DIR)/start_game/init_ghosts.c \
	   $(SRC_DIR)/start_game/init_map.c \
	   $(SRC_DIR)/start_game/init_map_images.c \
	   $(SRC_DIR)/start_game/init_mlx.c \
	   $(SRC_DIR)/start_game/init_player.c \
	   $(SRC_DIR)/start_game/init_power_up_dots.c \
	   $(SRC_DIR)/start_game/start_game.c


OBJS = $(SRCS:%.c=%.o)

HEADER = $(INC_DIR)/so_long.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MLX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL = $(GET_NEXT_LINE_DIR)/libgnl.a
MLX = $(MLX_DIR)/libmlx.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf
GNL_FLAGS = -L$(GET_NEXT_LINE_DIR) -lgnl
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MLX)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS) $(INC_FLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

$(GNL):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) all

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re