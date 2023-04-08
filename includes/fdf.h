/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:31 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/08 15:38:17 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// used headers
# include "mlx.h"
# include "../libs/getnextline/get_next_line.h"
# include "../libs/libft/libft.h"
# include	<stdlib.h> 
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

// COLORS
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF

// Windows size
# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1080

// mlx key events
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78

typedef struct t_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/**
	* Array with size
	*/

typedef struct t_int
{
	int		*arr;
	size_t	size;
}	t_int;

/**
	* Point Struct
	*/
typedef struct t_point
{
	float	x;
	float	y;
	int		color;
}	t_point;

/**
	* Map of points Struct
	*/
typedef struct t_map
{
	t_point	**p;
}	t_map;

/**
	* Fdf Struct
	*/
typedef struct t_fdf
{
	size_t		col;
	size_t		row;
	t_data		*img;
	float		div_x;
	float		div_y;
	float		zoom;
	t_map		*map;
	void		*mlx;
	void		*mlx_win;
}	t_fdf;

// reading from map and parsing
char	**append_to_arr(char **map, char *line);
char	**read_map(int fd);
t_int	*split_line(char *line);
t_int	**parse_map(char **map);
t_fdf	*final_map(t_int **map);
size_t	arr_len(char **arr);
void	resize_map(t_fdf *fdf);

// mlx related functions
int		key_hook(int key, t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// drawing functions
void	rendring(t_fdf *fdf);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	to_Isometric(int x, int y, int z, t_point *p);

#endif // FDF_H
