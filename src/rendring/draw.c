/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/24 19:25:17 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
t_point	to_isometric(double x, double y, double z)
{
	t_point	p;

	p.color = WHITE;
	if (z != 0)
		p.color = RED;
	p.x = (y - x) * cos(0.50);
	p.y = (x + y) * sin(0.50) - z;
	return (p);
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

void	rendring(t_fdf fdf)
{
	size_t	i;
	size_t	j;

	j = 0;
	mlx_clear_window(fdf.mlx, fdf.mlx_win);
	if (fdf.col == 1)
		return (rendring_one_row(fdf));
	while (++j < fdf.col)
	{
		i = 0;
		while (++i < fdf.line[j].row)
		{	
			if (j + 1 == fdf.col)
				bresenham(fdf, fdf.line[j].p[i - 1], \
					fdf.line[j].p[i]);
			bresenham(fdf, fdf.line[j - 1].p[i - 1], \
					fdf.line[j - 1].p[i]);
			if (i + 1 == fdf.line[j].row)
				bresenham(fdf, fdf.line[j].p[i], \
				fdf.line[j - 1].p[i]);
			bresenham(fdf, fdf.line[j].p[i - 1], \
					fdf.line[j - 1].p[i - 1]);
		}
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img->img, 0, 0);
}

void	rendring_one_row(t_fdf fdf)
{
	size_t	i;
	size_t	j;

	j = -1;
	mlx_clear_window(fdf.mlx, fdf.mlx_win);
	while (++j < fdf.col)
	{
		i = 0;
		while (++i < fdf.line[j].row)
			bresenham(fdf, fdf.line[j].p[i - 1], \
				fdf.line[j].p[i]);
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img->img, 0, 0);
}
