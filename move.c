#include "so_long.h"
#include <stdio.h>
//mlx_hook(list->win_ptr, 17, 0, close_frame, &pnc);


int	move(int keycode, t_list *list)
{

	
	if (keycode == 13 || keycode == 119)
	{
		move_up(list);
		write(1, "1111", 4);
	}
	else if (keycode == 0 || keycode == 97)
	{	
		write(1, "222",3);
		move_left(list);
	}
	else if (keycode == 1 || keycode == 115)
	{
		write(1, "3333", 4);
		move_down(list);
	}
	else if (keycode == 2 || keycode == 100)
	{
		write(1, "444", 3);
		move_right (list);
	}	
	//else if (keycode == 53)
	//	close_window(list);
	return (0);
}

void	move_up(t_list *list)
{
	int x=list->player_x;
	int y=list->player_y;
	printf("loc_x:%d, loc_y%d", x,y);
	if (list->map[y][x] == 'P')
	{
		if (list->map[y-1][x] != '1')
		{
			/*if (list->map[y-1][x] == 'E'  && open_exit(win))
			{
				list->map[y-1][x] = 'P';
				//total_steps(win);
				write(1, "win", 3);
				exit(1);
			}*/
			if (list->map[y-1][x] != 'E')
			{
				list->map[y][x] = '0';
				list->map[y-1][x] = 'P';
				list->player_y -= 1;
			}
		}
	}
	create_map_img_to_window(list);
}

void	move_down(t_list *list)
{
	int x=list->player_x;
	int y=list->player_y;
	if (list->map[y][x] == 'P')
	{
		if (list->map[y+1][x] != '1')
		{
			/*if (list->map[y+1][x] == 'E' &&
	open_exit(win))
			{
				list->map[y+1][x] = 'P';
				//total_steps(win);
				write(1, "win", 3);
				exit(1);
			}
			else*/ if (list->map[y+1][x] != 'E')
			{
				list->map[y][x] = '0';
				list->map[y+1][x] = 'P';
				list->player_y += 1;
			}
		}
	}
	//mlx_clear_window(win->mlx, win->mlx_win);
	create_map_img_to_window(list);
}

void	move_right(t_list *list)
{
	int x=list->player_x;
	int y=list->player_y;
	if (list->map[y][x] == 'P')
	{
		if (list->map[y][x+1]!= '1')
		{
			/*if (list->map[y][x+1]== 'E' &&
	open_exit(win))
			{
				list->map[y][x+1]= 'P';
				//total_steps(win);
				write(1, "win", 3);
				exit(1);
			}
			else*/ if (list->map[y][x+1]!= 'E')
			{
				list->map[y][x] = '0';
				list->map[y][x+1]= 'P';
				list->player_x += 1;
			}
		}
	}
	//mlx_clear_window(win->mlx, win->mlx_win);
	create_map_img_to_window(list);
}

void	move_left(t_list *list)
{
	int x=list->player_x;
	int y=list->player_y;
	if (list->map[y][x] == 'P')
	{
		if (list->map[y][x-1] != '1')
		{
			/*if (list->map[y][x-1] == 'E'  &&
	open_exit(win))
			{
				list->map[y][x-1] = 'P';
				//total_steps(win);
				write(1, "win", 3);
				exit(1);
			}
			else*/ if (list->map[y][x-1] != 'E')
			{
				list->map[y][x] = '0';
				list->map[y][x-1] = 'P';
				list->player_x -= 1;
			}
		}
	}
	//mlx_clear_window(win->mlx, win->mlx_win);
	create_map_img_to_window(list);
}
