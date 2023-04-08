/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:31 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/07 02:57:41 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/minilibx_macos/mlx.h"
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
# define WHITE 0xFFFFFF
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1080
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/**
	* Array with size
	*/

typedef struct{
	int	*arr;
	size_t	size;
} int_array;

/**
	* Point Struct
	*/
typedef struct{
	float	x;
	float	y;
	int	color;
} t_point;

/**
	* Map of points Struct
	*/
typedef struct {
	t_point **p;
} t_map;

/**
	* Fdf Struct
	*/
typedef struct {
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	t_map	*map;
	size_t	col;
	size_t	row;
	float	div_x;
	float	div_y;
	float zoom;
} t_fdf;

int	key_hook(int key, t_fdf *fdf);
void	rendring(t_fdf *fdf);
float	sc(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	resize_map(t_fdf *fdf);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
t_fdf *final_map(int_array **map);
void	to_Isometric(int x, int y, int z, t_point *p);
size_t	arr_len(char **arr);
int_array	*split_line(char *line);
int_array **parse_map(char **map);
char	**append_to_arr(char **map, char *line);
char	**read_map(int fd);

#endif // DEBUG
