NAME = so_long

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I./$(INC_DIR)

SRC_DIR = sources
INC_DIR = includes/headers
LIB_DIR = includes/libraries
MLX_DIR = $(LIB_DIR)/mlx_linux
LIBFT_DIR = $(LIB_DIR)/libft
FT_PRINTF_DIR = $(LIB_DIR)/ft_printf
GET_NEXT_LINE_DIR = $(LIB_DIR)/get_next_line

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/validation/validation.c \
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
       $(SRC_DIR)/find_positions.c \
	   $(SRC_DIR)/set_positions.c \
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
       $(SRC_DIR)/pacman/update_direction.c \
       $(SRC_DIR)/ghosts/ghost_can_move.c \
       $(SRC_DIR)/ghosts/ghost_animation.c \
       $(SRC_DIR)/ghosts/ghost_current_img.c \
       $(SRC_DIR)/ghosts/ghost_panic_animation.c \
       $(SRC_DIR)/ghosts/ghost_utils.c \
       $(SRC_DIR)/red_ghost/red_ghost_moving.c \
       $(SRC_DIR)/blue_ghost/blue_ghost_moving.c \
       $(SRC_DIR)/orange_ghost/orange_ghost_moving.c \
       $(SRC_DIR)/magenta_ghost/magenta_ghost_moving.c \
	   $(SRC_DIR)/initializations/pac_initialization.c \
	   $(SRC_DIR)/initializations/ghost_panic_initialization.c \
	   $(SRC_DIR)/initializations/red_ghost_initialization.c \
	   $(SRC_DIR)/initializations/orange_ghost_initialization.c \
	   $(SRC_DIR)/initializations/blue_ghost_initialization.c \
	   $(SRC_DIR)/initializations/magenta_ghost_initialization.c \
	   $(SRC_DIR)/initializations/font_initialization.c \
	   $(SRC_DIR)/initializations/map_initialization.c


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