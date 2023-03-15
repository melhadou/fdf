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

// int array struct
typedef struct{
	int *arr;
	size_t size;
} int_array;

typedef struct{
	int x;
	int y;
}t_vec;

void to_Isometric(int x, int y, int z, t_vec *u);
void draw_line(void *mlx, void *mlx_win, int x0, int y0, int x1, int y1, int color);
size_t arr_len(char **arr);
int_array *split_line(char *line);
int_array **parse_map(char **map);
char **append_to_arr(char **map, char *line);
char **read_map(int fd);
#endif // DEBUG
