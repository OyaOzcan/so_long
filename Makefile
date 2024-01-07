CFLAGS = -Wall -Wextra -Werror -I./minilibx -g 
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx -fsanitize=address
MLX = ./mlx/libmlx.a
PRINTF = ./ft_printf/libftprintf.a
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNLOBJS = $(GNL:.c=.o)
SRCS = map.c map2.c control.c control2.c move.c path_control.c so_long.c path_control_utils.c control3.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(PRINTF) $(NAME)

$(MLX) :
	make -sC ./mlx

$(PRINTF) :
	make -sC ./ft_printf

$(NAME) : $(OBJS) $(GNLOBJS) $(PRINTF)
	gcc $(OBJS) $(GNLOBJS) $(PRINTF) $(LFLAGS) -o $(NAME) $(MLX) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o
	make clean -C ./mlx
	make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re