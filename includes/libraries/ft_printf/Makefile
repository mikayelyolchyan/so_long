NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I../libft

AR = ar -rcs

SRCS = ft_printf.c ft_switch.c ft_print_char.c ft_print_str.c ft_print_int.c ft_print_unsigned.c \
		ft_print_hex_lower.c ft_print_hex_upper.c ft_print_ptr.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIBFT = ../libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ../libft all
	$(MAKE) -C ../libft bonus

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re
