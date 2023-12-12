#include "so_long.h"

#include <unistd.h>

void	wall_error(t_list *list)
{
	int	x;                       
	int	y;
	//int last_line;	
								  
	x = 0;
	y = 0;
	//last_line=(list->y_line_count)-1;
	while (list->map[0][x] != '\n' && list->map[0][x])
	{
		if (list->map[0][x] != '1')
		
			write(1, "1wrong wall", 10);
		x++;
	}
	x--;
	while (list->map[y] != NULL)
	{
		if (list->map[y][x] != '1' || list->map[y][0]!='1')
			write(1, "2wrong wall",10);
		y++;
	}		
	y--;
	x = 0;
	wall_error2(x, y, list);
}

void	wall_error2(int x, int y, t_list *list)
{
	while (list->map[y][x] != '\n' && list->map[y][x])
	{
		if (list->map[y][x] != '1')
			write(1,"3wrong wall",10);
		x++;
	}
	x--;
	
}

void	ber_control(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if ((map_file[len - 1] != 'r' && map_file[len - 2] != 'e'
			&& map_file[len - 3] != 'b' && map_file[len - 4] != '.')
		|| len <= 4)
	write(1, "wrong ber", 9);
}
//map dosyası dizindeki mi değil mi kontrol et!! ve ./.ber uzantısını ele alıyor mu kontrol ett

void	map_char_control(t_list *list)
{
	// devam etme durumunu kontrol et
	int	y;
	int	x;

	y = 0;
	while (list->map[y])
	{

		while (list->map[y][x] != '\n' && list->map[y][x] != '\0')
		{
			if (list->map[y][x] == 'E')
			{
				list->exit_count++;
				x++;
			}
			else if (list->map[y][x] == 'P')
			{
				list->player_count++;
				list->player_y = y;
				list->player_x = x;
				x++;
			}
			else if (list->map[y][x] == 'C')
			{
				list->coin_count++;
				x++;
			}
			else if(list->map[y][x]=='1' || list->map[y][x]=='0')
				x++;
			else
			{
				write(1, "wrong char in map", 18);
				exit(1);
			}	
		}
		y++;
		x=0;
	}
}

void control_exit_player_count(t_list *list)
{
	if(list->exit_count!=1)
		write(1, "wrong exit count" ,16);
	if(list->player_count !=1)
		write(1, "wrong player count" ,18);
	if(list->coin_count<1)
		write(1, "there is no coin", 14);
}


/*
void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(1, "Wrong File Path", 16);
		close(fd);
		exit(1);
	}
	close(fd);
}*/

// dikdörtgen mi kontrol et
//oyuncu hareketş ekle 
//oyuncu tüm coinleri topladı mı?
//coinleri topladıktan sonra exite ulaştı mı??
//hata varsa leak olmaması için, eğer hata yoksa haritada 0 ve C olan yerleri P olarak değiştirdiğimiz için free’lememiz gerekiyor.
