#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libs/getnextline/get_next_line.h"
# include "../libs/libft/libft.h"
# include	<stdlib.h> 
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# define RED 0xFF0000
# define FAC 30
// int array struct
typedef struct{
	int *arr;
	size_t size;
} int_array;

typedef struct{
	int x;
	int y;
} t_point;

typedef struct {
	t_point **p;
	size_t col;
	size_t row;
} t_map;

void drawline(void *mlx, void *mlx_win, int start_x, int start_y, int end_x, int end_y);
t_map **final_map(int_array **map);
void to_Isometric(int x, int y, int z, t_point *p);
void draw_line(void *mlx, void *mlx_win, int x0, int y0, int x1, int y1, int color);
size_t arr_len(char **arr);
int_array *split_line(char *line);
int_array **parse_map(char **map);
char **append_to_arr(char **map, char *line);
char **read_map(int fd);
#endif // DEBUG
