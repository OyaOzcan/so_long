/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:33:04 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/30 17:33:05 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_control(t_list *list)
{
	wall_error(list);
	map_char_control(list);
	control_exit_player_count(list);
	path_control_coin(list);
	path_control(list);
}
