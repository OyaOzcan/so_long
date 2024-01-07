/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:14:50 by oyozcan           #+#    #+#             */
/*   Updated: 2023/12/30 17:14:51 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include "fcntl.h"
# include "stdlib.h"
# include "string.h"

typedef struct s_list
{
	void	*mlx;
	void	*win_ptr;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*coin_img;
	void	*bg_img;
	char	**map;
	char	**map_tmp;
	int		line_count;
	int		player_x;
	int		player_y;
	int		exit_count;
	int		coin_count;
	int		player_count;
	int		y_line_count;
	int		collected_coin;
	int		step_count;
	int		height;
	int		width;
}			t_list;

void		wall_error(t_list *list);
void		wall_error2(int x, int y, t_list *list);
void		create_map_img_to_window(t_list *list, int x, int y);
int			create_xpm_to_img_map(t_list *list);
void		map_line_count(t_list *list, char *map_file);
void		read_map(t_list *list, char *map_file);
void		ber_control(char *map_file, t_list *list);
void		map_char_control(t_list *list);
void		map_char_control2(t_list *list, int y, int x);
void		control_exit_player_count(t_list *list);
int			move(int keycode, t_list *list);
void		move_left(t_list *list);
void		move_right(t_list *list);
void		move_down(t_list *list);
void		move_up(t_list *list);
int			open_exit(t_list *list);
void		step_count(t_list *list);
void		path_control(t_list *list);
void		path_control_coin(t_list *list);
void		try_path_exit(char **map, int y, int x);
void		try_path_coin(char **map, int y, int x);
void		map_free(char **map);
char		*ft_strdup(const char *s);
char		**map_copy(t_list *list);
void		error_message(t_list *list);
void		file_control(char *map_file, t_list *list);
int			ft_exit(t_list *list);
void		map_info(t_list *list);
void		init_map(t_list *list);
void		error_control(t_list *list);
void		rectangle_control(t_list *list);
void		file_control2(void);
#endif
