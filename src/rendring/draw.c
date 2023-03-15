/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/12 22:01:15 by melhadou         ###   ########.fr       */
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
		mlx_pixel_put(mlx, mlx_win, x0, y0, color);
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

void to_Isometric(int x, int y, int z, t_vec *u)
{
	u->x = (x - y) * cos(0.5);
	u->y = (x + y) * sin(0.5) - z;
}
