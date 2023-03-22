/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/22 16:00:48 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	bresenham(t_data *img, t_point start, t_point end)
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
		my_mlx_pixel_put(img, x + (WINDOW_WIDTH / 2), y  + (WINDOW_HEIGHT / 2), 0xFFFFFF);
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
