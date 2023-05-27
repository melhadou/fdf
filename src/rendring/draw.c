/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/05/27 16:35:09 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
void	to_isometric(int x, int y, int z, t_point *p)
{
	p->color = WHITE;
	if (z != 0)
		p->color = RED;
	p->x = (y - x) * cos(0.45);
	p->y = (x + y) * sin(0.45) - z;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

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
