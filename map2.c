/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:29:53 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/30 16:30:12 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_list *list)
{
	list->mlx = mlx_init();
	list->win_ptr = mlx_new_window(list->mlx, 64 * list->width, 64
			* list->height, "so_long");
	create_xpm_to_img_map(list);
	create_map_img_to_window(list, 0, -1);
}

void	step_count(t_list *list)
{
	list->step_count++;
	ft_printf("step count: %d\n", list->step_count);
}

void	error_message(t_list *list)
{
	write(1, "Error\n", 6);
	free(list);
	exit(1);
}

int	ft_exit(t_list *list)
{
	(void)list;
	mlx_destroy_window(list->mlx, list->win_ptr);
	write(1, "game closed\n", 12);
	exit(1);
}

int	open_exit(t_list *list)
{
	int	coin_count;
	int	collected_coin;

	coin_count = list->coin_count;
	collected_coin = list->collected_coin;
	if (coin_count == collected_coin)
		return (1);
	return (0);
}
