NAME = so_long

CC = cc
C_FLAGS = -Wall -Wextra -Werror

SRC_DIR = sources
INC_DIR = includes
LIB_DIR = libraries
MLX_DIR = $(LIB_DIR)/mlx_linux
LIBFT_DIR = $(LIB_DIR)/libft

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/hotkeys.c $(SRC_DIR)/exit.c
OBJS = $(SRCS:%.c=%.o)
HEADER = $(INC_DIR)/so_long.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: libs $(NAME)

libs:
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJS) libs
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT_FLAGS) $(INC_FLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libs
