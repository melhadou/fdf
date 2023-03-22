/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:31 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/19 22:16:45 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define GREEN 0x00FF00
# define FAC 20
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void resize_map(t_map **map);
void	bresenham(t_data *img, t_point start, t_point end);
t_map **final_map(int_array **map);
void to_Isometric(int x, int y, int z, t_point *p);
size_t arr_len(char **arr);
int_array *split_line(char *line);
int_array **parse_map(char **map);
char **append_to_arr(char **map, char *line);
char **read_map(int fd);
#endif // DEBUG
