/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/30 01:47:51 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_map **map, t_point start, t_point end)
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

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	x = start.x;
	y = start.y;
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
		my_mlx_pixel_put(map[0]->img, x + map[0]->div_x + (WINDOW_WIDTH / 2), y + map[0]->div_y + (WINDOW_HEIGHT / 2), color);
		if (x == end.x && y == end.y)
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
			bresenham(f_map, *f_map[y - 1]->p[x - 1], *f_map[y - 1]->p[x]);
			bresenham(f_map, *f_map[y]->p[x - 1], *f_map[y]->p[x]);
			bresenham(f_map, *f_map[y - 1]->p[x], *f_map[y]->p[x]);
			bresenham(f_map, *f_map[y - 1]->p[x - 1], *f_map[y]->p[x - 1]);
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
		map[0]->div_y -= 20;
	else if (key == RIGHT_KEY)
	 map[0]->div_x += 20;
	else if (key == DOWN_KEY)
	 map[0]->div_y += 20;
	else if (key == LEFT_KEY)
		map[0]->div_x -= 20;
	
	mlx_clear_window(map[0]->mlx, map[0]->mlx_win);
	map[0]->img->img = mlx_new_image(map[0]->mlx,WINDOW_WIDTH, WINDOW_HEIGHT);
	map[0]->img->addr = mlx_get_data_addr(map[0]->img->img, &map[0]->img->bits_per_pixel, &map[0]->img->line_length, &map[0]->img->endian);
	rendring(map);

	return (0);
}
