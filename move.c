/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:17:05 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/30 17:17:06 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_list *list)
{
	if (keycode == 13 || keycode == 119)
		move_up(list);
	else if (keycode == 0 || keycode == 97)
		move_left(list);
	else if (keycode == 1 || keycode == 115)
		move_down(list);
	else if (keycode == 2 || keycode == 100)
		move_right(list);
	else if (keycode == 53)
		ft_exit(list);
	return (0);
}

void	move_up(t_list *list)
{
	if (list->map[list->player_y - 1][list->player_x] != '1')
	{
		if (list->map[list->player_y - 1][list->player_x] == 'E'
			&& open_exit(list))
		{
			list->map[list->player_y - 1][list->player_x] = 'P';
			step_count(list);
			write(1, "you win", 7);
			exit(0);
		}
		else if (list->map[list->player_y - 1][list->player_x] != 'E')
		{
			if (list->map[list->player_y - 1][list->player_x] == 'C')
				list->collected_coin++;
			list->map[list->player_y][list->player_x] = '0';
			list->map[list->player_y - 1][list->player_x] = 'P';
			list->player_y -= 1;
			step_count(list);
		}
	}
	mlx_clear_window(list->mlx, list->win_ptr);
	create_map_img_to_window(list, 0, -1);
}

void	move_down(t_list *list)
{
	if (list->map[list->player_y + 1][list->player_x] != '1')
	{
		if (list->map[list->player_y + 1][list->player_x] == 'E'
			&& open_exit(list))
		{
			list->map[list->player_y + 1][list->player_x] = 'P';
			step_count(list);
			write(1, "you win", 7);
			exit(0);
		}
		else if (list->map[list->player_y + 1][list->player_x] != 'E')
		{
			if (list->map[list->player_y + 1][list->player_x] == 'C')
				list->collected_coin++;
			list->map[list->player_y][list->player_x] = '0';
			list->map[list->player_y + 1][list->player_x] = 'P';
			list->player_y += 1;
			step_count(list);
		}
	}
	mlx_clear_window(list->mlx, list->win_ptr);
	create_map_img_to_window(list, 0, -1);
}

void	move_right(t_list *list)
{
	if (list->map[list->player_y][list->player_x + 1] != '1')
	{
		if (list->map[list->player_y][list->player_x + 1] == 'E'
			&& open_exit(list))
		{
			list->map[list->player_y][list->player_x + 1] = 'P';
			step_count(list);
			write(1, "you win", 7);
			exit(0);
		}
		else if (list->map[list->player_y][list->player_x + 1] != 'E')
		{
			if (list->map[list->player_y][list->player_x + 1] == 'C')
				list->collected_coin++;
			list->map[list->player_y][list->player_x] = '0';
			list->map[list->player_y][list->player_x + 1] = 'P';
			list->player_x += 1;
			step_count(list);
		}
	}
	mlx_clear_window(list->mlx, list->win_ptr);
	create_map_img_to_window(list, 0, -1);
}

void	move_left(t_list *list)
{
	if (list->map[list->player_y][list->player_x - 1] != '1')
	{
		if (list->map[list->player_y][list->player_x - 1] == 'E'
			&& open_exit(list))
		{
			list->map[list->player_y][list->player_x - 1] = 'P';
			step_count(list);
			write(1, "you win", 7);
			exit(0);
		}
		else if (list->map[list->player_y][list->player_x - 1] != 'E')
		{
			if (list->map[list->player_y][list->player_x - 1] == 'C')
				list->collected_coin++;
			list->map[list->player_y][list->player_x] = '0';
			list->map[list->player_y][list->player_x - 1] = 'P';
			list->player_x -= 1;
			step_count(list);
		}
	}
	mlx_clear_window(list->mlx, list->win_ptr);
	create_map_img_to_window(list, 0, -1);
}
