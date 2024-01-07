/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:41:55 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/23 18:41:56 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_path_exit(char **map, int y, int x)
{
	map[y][x] = '*';
	if (map[y + 1][x] != '1' && map[y + 1][x] != '*')
		try_path_exit(map, y + 1, x);
	if (map[y - 1][x] != '1' && map[y - 1][x] != '*')
		try_path_exit(map, y - 1, x);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '*')
		try_path_exit(map, y, x + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '*')
		try_path_exit(map, y, x - 1);
}

void	try_path_coin(char **map, int y, int x)
{
	map[y][x] = '.';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E' && map[y + 1][x] != '.')
		try_path_coin(map, y + 1, x);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E' && map[y - 1][x] != '.')
		try_path_coin(map, y - 1, x);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E' && map[y][x + 1] != '.')
		try_path_coin(map, y, x + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E' && map[y][x - 1] != '.')
		try_path_coin(map, y, x - 1);
}

char	**map_copy(t_list *list)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (list->y_line_count + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (list->map[i])
	{
		map[i] = ft_strdup(list->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	path_control(t_list *list)
{
	char	**map;
	int		j;
	int		i;

	map = map_copy(list);
	try_path_exit(map, list->player_y, list->player_x);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' && map[i][j] != '1'
				&& map[i][j] != '0')
			{
				map_free(map);
				error_message(list);
			}
		}
	}
	map_free(map);
}

void	path_control_coin(t_list *list)
{
	char	**map;
	int		j;
	int		i;

	map = map_copy(list);
	try_path_coin(map, list->player_y, list->player_x);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '.' && map[i][j] != '\n' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'E')
			{
				map_free(map);
				error_message(list);
			}
		}
	}
	map_free(map);
}
