/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/23 18:46:28 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/23 18:46:29 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_line_count(t_list *list, char *map_file)
{
	char	*line;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		error_message(list);
	}
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	list->y_line_count = line_count;
	close(fd);
}

void	read_map(t_list *list, char *map_file)
{
	char	*str;
	int		i;
	int		fd;

	map_line_count(list, map_file);
	list->map = malloc((list->y_line_count + 1) * sizeof(char *));
	if (!list->map)
		return ;
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (i < list->y_line_count)
	{
		str = get_next_line(fd);
		list->map[i] = str;
		i++;
	}
	list->map[i] = NULL;
	close(fd);
}

int	create_xpm_to_img_map(t_list *list)
{
	int	x;
	int	y;

	list->coin_img = mlx_xpm_file_to_image(list->mlx, "textures/coin.xpm", &x,
			&y);
	list->exit_img = mlx_xpm_file_to_image(list->mlx, "textures/exit.xpm", &x,
			&y);
	list->player_img = mlx_xpm_file_to_image(list->mlx, "textures/player.xpm",
			&x, &y);
	list->wall_img = mlx_xpm_file_to_image(list->mlx, "textures/wall.xpm", &x,
			&y);
	list->bg_img = mlx_xpm_file_to_image(list->mlx, "textures/background.xpm",
			&x, &y);
	if (!list->bg_img || !list->coin_img || !list->exit_img || !list->player_img
		|| !list->wall_img)
		return (1);
	return (0);
}

void	create_map_img_to_window(t_list *list, int x, int y)
{
	y = -1;
	while (list->map[++y] != NULL)
	{
		x = 0;
		while (list->map[y][x] && list->map[y][x] != '\n')
		{
			mlx_put_image_to_window(list->mlx, list->win_ptr, list->bg_img, 64
				* x, 64 * y);
			if (list->map[y][x] == 'C')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->coin_img, 64 * x, 64 * y);
			else if (list->map[y][x] == 'E')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->exit_img, 64 * x, 64 * y);
			else if (list->map[y][x] == 'P')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->player_img, 64 * (list->player_x), 64
					* (list->player_y));
			else if (list->map[y][x] == '1')
				mlx_put_image_to_window(list->mlx, list->win_ptr,
					list->wall_img, 64 * x, 64 * y);
			x++;
		}
	}
}

void	map_info(t_list *list)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (list->map[y] != NULL)
	{
		while (list->map[y][x] && list->map[y][x] != '\n')
		{
			x++;
			list->width = x;
		}
		y++;
		list->height = y;
		x = 0;
	}
	if (list->width > 41 || list->height > 22)
		error_message(list);
}
