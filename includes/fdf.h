/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:31 by melhadou          #+#    #+#             */
/*   Updated: 2023/12/04 15:17:40 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// used headers
# include "../libs/mlx/mlx.h"
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
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define MIN_SCALE 0
# define MAX_SCALE 2

#ifdef __linux__

enum {
ESC = 65307,
 UP_KEY = 65362,
 DOWN_KEY = 65364,
LEFT_KEY = 65361,
 RIGHT_KEY = 65363,
 PLUS_KEY = 61,
 MINUS_KEY = 45
};

#elif __APPLE__
enum {
	ESC = 53,
 UP_KEY = 126,
 DOWN_KEY = 125,
 LEFT_KEY = 123,
 RIGHT_KEY = 124,
 PLUS_KEY = 69,
 MINUS_KEY = 78
};
#endif


// mlx key events

typedef struct t_dda
{
	float	dx;
	float	dy;
	float	steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	int		color;
}	t_dda;

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
int			get_vals(t_point end, t_point start);
void		dda(t_fdf fdf, t_point start, t_point end);
t_point		to_isometric(double x, double y, double z);

// fdf alloc
t_fdf		populate_fdf(t_double *map, int col);
void		print_map(t_fdf fdf);
#endif // FDF_H
