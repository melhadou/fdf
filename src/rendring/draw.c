/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/23 03:35:41 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	bresenham(t_data *img, t_point start, t_point end, int div_x, int div_y)
{
	int dx = abs(end.x - start.x);
	int dy = abs(end.y - start.y);
	int x = start.x;
	int y = start.y;
	int sx = (start.x < end.x) ? 1 : -1;
	int sy = (start.y < end.y) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		// Centring the points
		my_mlx_pixel_put(img, x + div_x + (WINDOW_WIDTH / 2), y + div_y + (WINDOW_HEIGHT / 2), 0xFFFFFF);
		if (x == end.x && y == end.y)
			break;
		int e2 = 2 * err;
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
	p->x = ((y - x ) * cos(0.5)) * FAC;
	p->y = ((x + y) * sin(0.5) - z) * FAC;
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

void rendring(t_map **f_map)
{
	mlx_clear_window(f_map[0]->mlx, f_map[0]->mlx_win);
	size_t x;
	size_t y;

	y = 1;
	x = 0;
	
	while (y < f_map[0]->row)
	{
		x = 1;
		while (x < f_map[0]->col)
		{
			bresenham(f_map[0]->img, *f_map[y]->p[x - 1], *f_map[y]->p[x], f_map[0]->div_x, f_map[0]->div_y);
			bresenham(f_map[0]->img, *f_map[y - 1]->p[x], *f_map[y]->p[x], f_map[0]->div_x, f_map[0]->div_y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f_map[0]->mlx, f_map[0]->mlx_win, f_map[0]->img->img,0, 0);
}

int key_hook(int key, t_map **map)
{
	if (key == 53)
		exit(1);
	else if (key == UP_KEY)
		map[0]->div_y += 20;
	else if (key == RIGHT_KEY)
	 map[0]->div_x += 20;
	else if (key == DOWN_KEY)
	 map[0]->div_y -= 20;
	else if (key == LEFT_KEY)
		map[0]->div_x -= 20;
	
	mlx_clear_window(map[0]->mlx, map[0]->mlx_win);
	map[0]->img->img = mlx_new_image(map[0]->mlx,WINDOW_WIDTH, WINDOW_HEIGHT);
	map[0]->img->addr = mlx_get_data_addr(map[0]->img->img, &map[0]->img->bits_per_pixel, &map[0]->img->line_length, &map[0]->img->endian);
	rendring(map);

	return (0);
}
