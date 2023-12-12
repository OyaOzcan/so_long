#ifndef SO_LONG_H
#define SO_LONG_H

# include "stdio.h"
# include "stdlib.h"
# include "mlx.h"
# include "fcntl.h"
# include "./get_next_line/get_next_line.h"
# include "string.h"

typedef struct s_list {
    void *mlx;
    void *win_ptr;
    void *player_img;
    void *wall_img;
    void *exit_img;
    void *coin_img;
    void *bg_img;
    char **map;
    int line_count;
    int player_x;
    int player_y;
    int exit_count;
    int coin_count;
    int player_count;
    int y_line_count;
    int x_line;
    int collected_coin;

} t_list ;

//int	read_map(t_list *list, char *map_file);
//void map_read_count(t_list *list, char *map_file);
void	wall_error(t_list *list);
void	wall_error2(int x, int y, t_list *list);
void 	create_map_img_to_window(t_list *list);
int 	create_xpm_to_img_map(t_list *list);
void 	map_line_count(t_list *list, char *map_file);
void	read_map(t_list *list, char *map_file);
void 	ber_control(char *map_file);
void 	map_char_control(t_list *list);
void 	control_exit_player_count(t_list *list);	
int	move(int keycode, t_list *list);
void	move_left(t_list *list);
void	move_right(t_list *list);
void	move_down(t_list *list);
void	move_up(t_list *list);
#endif
