/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/21 22:18:44 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
//
t_point	to_isometric(double x, double y, double z)
{
	t_point p;

	p.color = WHITE;
	if (z != 0)
		p.color = RED;
	z *= 0.2;
	p.x = (y - x) * cos(0.45);
	p.y = (x + y) * sin(0.45) - z;
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

// void	rendring(t_fdf fdf)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = 0;
// 	mlx_clear_window(fdf.mlx, fdf.mlx_win);
// 	if (fdf.row == 1)
// 		return (rendring_one_row(fdf));
// 	while (++j < fdf.row)
// 	{
// 		i = 0;
// 		while (++i < fdf.col)
// 		{	
// 			if (j + 1 == fdf.row)
// 				bresenham(fdf, fdf.line[j].p[i - 1], \
// 					fdf.line[j].p[i]);
// 			bresenham(fdf, fdf.line[j - 1].p[i - 1], \
// 					fdf.line[j - 1].p[i]);
// 			if (i + 1 == fdf.col)
// 				bresenham(fdf, fdf.line[j].p[i], \
// 					fdf.line[j - 1].p[i]);
// 			bresenham(fdf, fdf.line[j].p[i - 1], \
// 					fdf.line[j - 1].p[i - 1]);
// 		}
// 	}
// 	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
// }

// void	rendring_one_row(t_fdf fdf)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = -1;
// 	mlx_clear_window(fdf.mlx, fdf.mlx_win);
// 	while (++j < fdf.row)
// 	{
// 		i = -1;
// 		while (++i < fdf.col)
// 		{	
// 			if (j + 1 < fdf.row)
// 				bresenham(fdf, fdf.line[j].p[i], \
// 							fdf.line[j + 1].p[i]);
// 			if (i + 1 < fdf.col)
// 			{
// 				bresenham(fdf, fdf.line[j].p[i], \
// 							fdf.line[j].p[i + 1]);
// 				if (j + 1 < fdf.row)
// 					bresenham(fdf, fdf.line[j].p[i], \
// 							fdf.line[j + 1].p[i + 1]);
// 			}
// 		}
// 	}
// 	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img.img, 0, 0);
// }

void	rendring(t_fdf fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	mlx_clear_window(fdf.mlx, fdf.mlx_win);

	if (fdf.col == 1)
		return (rendring_one_row(fdf));
	while (++i < fdf.col)
	{
		j = 0;
		while (++j < fdf.line[i].row)
		{	
			if (i + 1 == fdf.col)
				bresenham(fdf, fdf.line[i].p[j - 1], \
					fdf.line[i].p[j]);
			bresenham(fdf, fdf.line[i - 1].p[j], \
					fdf.line[i - 1].p[j]);
			if (j + 1 == fdf.line[i].row)
				bresenham(fdf, fdf.line[i].p[j], \
					fdf.line[i - 1].p[j]);
			bresenham(fdf, fdf.line[i].p[j - 1], \
					fdf.line[i - 1].p[j - 1]);
		}
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img->img, 0, 0);
}

void	rendring_one_row(t_fdf fdf)
{
	size_t	i;
	size_t	j;

	i = -1;
	mlx_clear_window(fdf.mlx, fdf.mlx_win);
	while (++i < fdf.col)
	{
		j = -1;
		while (++j < fdf.line[i].row)
		{	
			if (i + 1 < fdf.col)
				bresenham(fdf, fdf.line[i].p[j], \
							fdf.line[i + 1].p[j]);
			if (i + 1 < fdf.col)
			{
				bresenham(fdf, fdf.line[i].p[j], \
							fdf.line[i].p[j + 1]);
				if (i + 1 < fdf.line[j].row)
					bresenham(fdf, fdf.line[i].p[j], \
							fdf.line[i + 1].p[j + 1]);
			}
		}
	}
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img->img, 0, 0);
}
