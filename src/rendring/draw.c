/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:19:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/10 16:09:21 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
void	to_isometric(int x, int y, int z, t_point *p)
{
	p->color = WHITE;
	if (z != 0)
		p->color = RED;
	if (z > 2 || z < 0)
		z *= 0.1;
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
	size_t	i_col;
	size_t	i_row;

	i_row = 1;
	i_col = 0;
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	while (i_row < fdf->row)
	{
		i_col = 1;
		while (i_col < fdf->col)
		{	
			if (i_row + 1 == fdf->row)
				bresenham(fdf, *fdf->map[i_row].p[i_col - 1], *fdf->map[i_row].p[i_col]);
			bresenham(fdf, *fdf->map[i_row - 1].p[i_col - 1], *fdf->map[i_row - 1].p[i_col]);
			if (i_col + 1 == fdf->col)
				bresenham(fdf, *fdf->map[i_row].p[i_col],*fdf->map[i_row - 1].p[i_col]);
			bresenham(fdf, *fdf->map[i_row].p[i_col - 1],*fdf->map[i_row - 1].p[i_col - 1]);
			i_col++;
		}
		i_row++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img->img, 0, 0);
}
