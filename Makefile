NAME = so_long

CC = cc

SRCS = main.c hotkeys.c exit.c

OBJS = $(SRCS:%.c=%.o)

HEADER = so_long.h

MLX_PATH = libs/mlx_linux/

LIBFT_PATH = libs/libft/

LIBFT = $(LIBFT_PATH)libft.a

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

all: libs $(NAME) 

libs:
	@$(MAKE) -C $(MLX_PATH)
	@$(MAKE) -C $(LIBFT_PATH) all

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libs
