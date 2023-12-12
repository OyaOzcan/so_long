GNL = $(wildcard get_next_line/*c)
GNLOBJS = $(GNL:.c=.o)

SRCS = map.c control.c move.c
#CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -g
CFLAGS = -Wall -Wextra -Werror -I./mlx -g
#LFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lXpm -lm -lz
LFLAGS = -L./mlx -framework OpenGL -framework AppKit

#MLX = ./minilibx-linux/libmlx.a
MLX = ./mlx/libmlx.a
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
#make -sC ./minilibx-linux
	make -sC ./mlx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
#make clean -C ./minilibx-linux
	make clean -C ./mlx

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re
