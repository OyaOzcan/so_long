
#include "so_long.h"
#include <stdio.h>
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
		printf("%s", "error: there is no map\n");
		exit(1);
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

	map_line_count(list,map_file);
	list->map = malloc((list->y_line_count + 1) * sizeof(char *));
	if (!list->map)
		return ;
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (list->y_line_count -- > 0)
	{
		 str = get_next_line(fd);
		 list->map[i] = str;
         i++;
        //list->map[i]=get_next_line(fd);
        //i++;
	}
	list->map[i] = NULL;
	//exit_finder(t_map.map);
	close(fd);
}

//t_list->wall_count = ft_strlen(t_list->map[0]) - 1;


int create_xpm_to_img_map(t_list *list){
    void *mlx=list->mlx;
    int x;
    int y;

    list->coin_img=mlx_xpm_file_to_image(mlx, "./coin.xpm", &x ,&y);
    list->exit_img=mlx_xpm_file_to_image(mlx, "./exit.xpm", &x, &y);
    list->player_img=mlx_xpm_file_to_image(mlx, "./player.xpm", &x, &y);
    list->wall_img=mlx_xpm_file_to_image(mlx, "./wall.xpm", &x , &y);
    list->bg_img=mlx_xpm_file_to_image(mlx,"./background.xpm", &x, &y);

     if (!list->bg_img || !list->coin_img || !list->exit_img || !list->player_img || !list->wall_img)
	 	return (1);
	 return (0);
}
void create_map_img_to_window(t_list *list)
{
  int x;
  int y;
  void *mlx=list->mlx;
  void *win_ptr=list->win_ptr;

  x=0;
  y=0;

  while(list->map[y]!=NULL)
  {
    while(list->map[y][x] && list->map[y][x]!='\n')
    {
    if(list->map[y][x]=='C')
      mlx_put_image_to_window(mlx,win_ptr, list->coin_img, 64 * x, 64 * y);
    else if(list->map[y][x]=='E')
 	    mlx_put_image_to_window(mlx, win_ptr, list->exit_img,64 * x, 64 * y);
    else if(list->map[y][x]=='P')
      mlx_put_image_to_window(mlx, win_ptr, list->player_img, 64 * (list->player_x), 64 * (list->player_y));
    else if(list->map[y][x]=='1')
      mlx_put_image_to_window(mlx, win_ptr, list->wall_img, 64 * x, 64 * y);
    else if(list->map[y][x]=='0')
      mlx_put_image_to_window(mlx, win_ptr, list->bg_img, 64 * x, 64 * y);
    x++;
    }
    y++;
    x=0;
}
}

int main(int ac,char **av)
{      
       	if(ac==2)
        {
	    t_list *list;
	    list=malloc(sizeof(t_list));
	    if(!list){
		    return 0;
	    }
        
	ber_control(av[1]);		
	map_line_count(list,av[1]);
	read_map(list,av[1]);
	wall_error(list);
	map_char_control(list);
	control_exit_player_count(list);
	list->mlx = mlx_init();

		//int x=strlen(list->map[0]-1);
       void *win_ptr = mlx_new_window(list->mlx, 64 * 34 , 64 * 6, "Deneme");
       list->win_ptr=win_ptr;
		//mapin satır sayısını ve sutun sayısını vericez 64*x 64*y olark
		//x= ft_strlen(map->map_x_line)

	    
        //map_read_c(list, av[1]);
        create_xpm_to_img_map(list);
        create_map_img_to_window(list);
		mlx_hook(list->win_ptr, 2, (1L << 0), move, list);
        mlx_loop(list->mlx); 
        return (0);
       }
}
