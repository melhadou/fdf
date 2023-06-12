/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/12 15:50:36 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

// normed
void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	t_bresenham	bres;

	start.x *= fdf->zoom;
	start.y *= fdf->zoom;
	end.x *= fdf->zoom;
	end.y *= fdf->zoom;
	bres.color = get_vals(end, start);
	bers_init(&bres, &start, &end);
	while (1)
	{
		my_mlx_pixel_put(fdf->img,
			bres.x + fdf->div_x + (int)(WINDOW_WIDTH / 2),
			bres.y + fdf->div_y + (int)(WINDOW_HEIGHT / 2),
			bres.color);
		if (bres.x == (int)end.x && bres.y == (int)end.y)
			break ;
		bers_two(&bres);
	}
}

void	bers_two(t_bresenham *bres)
{
	bres->e2 = 2 * bres->err;
	if (bres->e2 > -bres->dy)
	{
		bres->err -= bres->dy;
		bres->x += bres->sx;
	}
	if (bres->e2 < bres->dx)
	{
		bres->err += bres->dx;
		bres->y += bres->sy;
	}
}

void	bers_init(t_bresenham *bres, t_point *start, t_point *end)
{
	bres->dx = abs((int)end->x - (int)start->x);
	bres->dy = abs((int)end->y - (int)start->y);
	bres->x = (int)start->x;
	bres->y = (int)start->y;
	bres->sx = -1;
	bres->sy = -1;
	if (start->x < end->x)
		bres->sx = 1;
	if (start->y < end->y)
		bres->sy = 1;
	bres->err = bres->dx - bres->dy;
}

int	get_vals(t_point end, t_point start)
{
	int	color;

	color = WHITE;
	if (end.color == RED || start.color == RED)
		color = RED;
	if (end.color == RED && start.color == RED)
		color = GREEN;
	return (color);
}
