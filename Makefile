NAME = so_long

CC = cc
C_FLAGS = -Wall -Wextra -Werror  -fsanitize=address

SRC_DIR = sources
INC_DIR = includes/headers
LIB_DIR = includes/libraries
MLX_DIR = $(LIB_DIR)/mlx_linux
LIBFT_DIR = $(LIB_DIR)/libft
FT_PRINTF_DIR = $(LIB_DIR)/ft_printf
GET_NEXT_LINE_DIR = $(LIB_DIR)/get_next_line

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/hotkeys.c $(SRC_DIR)/exit.c $(SRC_DIR)/map.c \
		$(SRC_DIR)/free.c
OBJS = $(SRCS:%.c=%.o)
HEADER = $(INC_DIR)/so_long.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MLX_DIR)

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf
GNL_FLAGS = -L$(GET_NEXT_LINE_DIR) -lgnl
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: libs $(NAME)

libs:
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(FT_PRINTF_DIR) all
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) all

$(NAME): $(OBJS) libs
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS) $(INC_FLAGS) -o $(NAME)

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

.PHONY: all clean fclean re libs
