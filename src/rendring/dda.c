/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/25 12:11:49 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	dda(t_fdf fdf, t_point start, t_point end)
{
	t_dda	dda;

	start.x *= fdf.zoom;
	start.y *= fdf.zoom;
	end.x *= fdf.zoom;
	end.y *= fdf.zoom;
	dda.color = get_vals(end, start);
	dda.dx = end.x - start.x;
	dda.dy = end.y - start.y;
	dda.steps = fmaxf(fabsf(dda.dx), fabsf(dda.dy));
	dda.x_inc = dda.dx / dda.steps;
	dda.y_inc = dda.dy / dda.steps;
	dda.x = start.x;
	dda.y = start.y;
	while ((int)(dda.steps--) >= 0)
	{
		my_mlx_pixel_put(fdf.img, \
			dda.x + fdf.div_x + (int)(WINDOW_WIDTH / 2), \
			dda.y + fdf.div_y + (int)(WINDOW_HEIGHT / 2), \
			dda.color);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
	}
}
