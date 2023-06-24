/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:31 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/24 10:56:19 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// used headers
# include "mlx.h"
# include "../libs/getnextline/get_next_line.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include	<stdlib.h> 
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
# define MIN_SCALE 0
# define MAX_SCALE 2

// mlx key events
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78

typedef struct t_bresenham
{
	int	color;
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

/**
 * Iamge struct
 * b == bits per pixel
 * l == line length
 * e = endian
 * i = image
 * a = addr
 */
typedef struct t_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

/**
	* Array with size
	*/
typedef struct t_double
{
	double	*arr;
	size_t	size;
}	t_double;

/**
	* Point Struct
	*/
typedef struct t_point
{
	double	x;
	double	y;
	int		color;
}	t_point;

/**
	* Map of points Struct
	*/
typedef struct t_line
{
	t_point	*p;
	size_t	row;
}	t_line;

/**
	* Fdf Struct
	*/
typedef struct t_fdf
{
	t_data		*img;
	t_line		*line;
	size_t		col;
	float		div_x;
	float		div_y;
	float		zoom;
	void		*mlx;
	void		*mlx_win;
}	t_fdf;

// reading from map and parsing
size_t		arr_len(char **arr);
char		**append_to_arr(char **map, char *line);
char		**read_map(int fd);
t_double	*parse_map(char	**map);
t_double	**free_parsed_map(t_double	**map);
t_double	split_line(char	*line);

// mlx related functions
int			destroy_win(void);
int			key_hook(int key, t_fdf *fdf);
int			destroy_win(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
int			ft_zome(t_fdf fdf);
int			is_map_valid(char **map);
void		ft_free_string(char **str);
void		ft_free_t_double(t_double *p, size_t col);

// check_map 
void		validate_map(t_double *map, size_t col);
int			check_file_extension(char *file_name);
int			open_file(char *file_name);
int			check_map_alpha(char **map);

// drawing functions
void		rendring(t_fdf fdf);
void		rendring_one_row(t_fdf fdf);
void		bresenham(t_fdf fdf, t_point start, t_point end);
int			get_vals(t_point end, t_point start);
void		bers_two(t_bresenham *bres);
void		bers_init(t_bresenham *bres, t_point *start, t_point *end);

// fdf alloc
t_fdf		populate_fdf(t_double *map, int col);
int			diff_min_max_z(t_double *map, size_t col);
void		print_map(t_fdf fdf);
t_point		to_isometric(double x, double y, double z, int ratio);
#endif // FDF_H
