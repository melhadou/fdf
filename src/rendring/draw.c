/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/16 17:26:36 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void draw_line(void *mlx, void *mlx_win, int x0, int y0, int x1, int y1, int color)
{
	long dx;
	long sx;
	long dy;
	long sy;
	long error;
	long e2;

	dx = abs(x1 - x0);
	sx = -1;
	if (x0 < x1)
		sx = 1;
	dy = -abs(y1 - y0);
	sy = -1;
	if (y0 < y1)
		sy = 1;
	error = dx + dy;
	while (1)
	{
		mlx_pixel_put(mlx, mlx_win, x0 + 1040, y0 + 720, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
				break;
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break;
			error += dy;
			y0 += sy;
		}
	}
}

void to_Isometric(int x, int y, int z, t_point *p)
{
	p->x = ((x - y ) * cos(0.5)) * FAC;
	p->y = ((x + y) * sin(0.5) - z) * FAC;
}

void drawline(void *mlx, void *mlx_win, int start_x, int start_y, int end_x, int end_y)
{
	int dx = abs(end_x - start_x);
	int dy = abs(end_y - start_y);
	int x_inc = (end_x > start_x) ? 1 : -1;
	int y_inc = (end_y > start_y) ? 1 : -1;
	int x = start_x;
	int y = start_y;

	if (dx >= dy) {
			int d = 2 * dy - dx;
			while (x != end_x) {
					mlx_pixel_put(mlx, mlx_win, x + 1000, y + 720, RED);
					if (d > 0) {
							y += y_inc;
							d -= 2 * dx;
					}
					x += x_inc;
					d += 2 * dy;
			}
	} else {
			int d = 2 * dx - dy;
			while (y != end_y) {
					mlx_pixel_put(mlx, mlx_win, x + 1000, y + 720, RED);
					if (d > 0) {
							x += x_inc;
							d -= 2 * dy;
					}
					y += y_inc;
					d += 2 * dx;
			}
	}
}
