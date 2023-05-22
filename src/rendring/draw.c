/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/05/22 19:21:39 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	int color;
	int dx;
	int dy;
	int x;
	int y;
	int sx;
	int sy;
	int err;
	int e2;

	start.x *= fdf->zoom;
	start.y *= fdf->zoom;
	end.x *= fdf->zoom;
	end.y *= fdf->zoom;
	
	color = get_vals(end, start);
	
	dx = abs((int)end.x - (int)start.x);
	dy = abs((int)end.y - (int)start.y);

	x = (int)start.x;
	y = (int)start.y;

	sx = -1;
	sy = -1;
	if (start.x < end.x)
		sx = 1;
	if (start.y < end.y)
		sy = 1;
	err = dx - dy;
	 
	while (1)
	{
		// Centring the points
		my_mlx_pixel_put(fdf->img, x + fdf->div_x + (int)(WINDOW_WIDTH / 2),
									 	y + fdf->div_y + (int)(WINDOW_HEIGHT / 2), color);
		if (x == (int)end.x && y == (int)end.y)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}

int	get_vals(t_point end, t_point start)
{
	int	color;

	color = WHITE;
	if (end.color == RED || start.color == RED)
		color = RED;
	if (end.color == RED && start.color == RED)
		color = GREEN;
	return (color);
}

void	to_isometric(int x, int y, int z, t_point *p)
{
	p->color = WHITE;
	if (z != 0)
		p->color = RED;
	p->x = (y - x) * cos(0.5);
	p->y = (x + y) * sin(0.5) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WINDOW_WIDTH)
		return ;
	if (y <= 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	rendring(t_fdf *fdf)
{
	size_t	x;
	size_t	y;

	y = 1;
	x = 0;
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	while (y < fdf->row)
	{
		x = 1;
		while (x < fdf->col)
		{
			bresenham(fdf, *fdf->map[y - 1].p[x - 1], *fdf->map[y - 1].p[x]);
			bresenham(fdf, *fdf->map[y].p[x - 1], *fdf->map[y].p[x]);
			bresenham(fdf, *fdf->map[y - 1].p[x], *fdf->map[y].p[x]);
			bresenham(fdf, *fdf->map[y - 1].p[x - 1], *fdf->map[y].p[x - 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img, 0, 0);
}
