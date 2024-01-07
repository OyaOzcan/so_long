/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:44:05 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/23 18:44:09 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*list;

	if (ac == 2)
	{
		list = malloc(sizeof(t_list));
		if (!list)
			return (0);
		file_control(av[1], list);
		read_map(list, av[1]);
		ber_control(av[1], list);
		map_info(list);
		rectangle_control(list);
		error_control(list);
		init_map(list);
		mlx_hook(list->win_ptr, 2, 0, move, list);
		mlx_hook(list->win_ptr, 17, 0, ft_exit, list);
		mlx_loop(list->mlx);
	}
}
