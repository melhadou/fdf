/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/08 00:59:27 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	 
	color = WHITE;
	if (end.color == RED || start.color == RED)
		color = RED;
	if (end.color == RED && start.color == RED)
		color = GREEN;

	while (1)
	{
		// Centring the points
		my_mlx_pixel_put(fdf->img, x + fdf->div_x + (int)(WINDOW_WIDTH / 2), y + fdf->div_y + (int)(WINDOW_HEIGHT / 2), color);
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

void to_Isometric(int x, int y, int z, t_point *p)
{
	p->color = WHITE;
	if (z != 0)
		p->color = RED;
	p->x = ((y - x ) * cos(0.5));
	p->y = ((x + y) * sin(0.5) - z);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	// protecting cordinates to avoid overflowing from the image
	if (x <= 0 || x >= WINDOW_WIDTH)
		return;
	if (y <= 0 || y >= WINDOW_HEIGHT)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void rendring(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	size_t x;
	size_t y;

	y = 1;
	x = 0;
	
	while (y < fdf->row)
	{
		x = 1;
		while (x < fdf->col)
		{
			// dprintf(1,"%f",fdf->map[y - 1].p[x - 1]->x);
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

int key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(1);
	else if (key == UP_KEY)
		fdf->div_y -= 20;
	else if (key == RIGHT_KEY)
	 fdf->div_x += 20;
	else if (key == DOWN_KEY)
	 fdf->div_y += 20;
	else if (key == LEFT_KEY)
		fdf->div_x -= 20;
	else if (key == PLUS_KEY)
		fdf->zoom *= 1.2;
	else if (key == MINUS_KEY)
		fdf->zoom /= 1.2;

	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	fdf->img->img = mlx_new_image(fdf->mlx,WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	rendring(fdf);
	return (0);
}
