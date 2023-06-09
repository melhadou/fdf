/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:28:17 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/09 16:07:00 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// normed
int	key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(1);
	else if (key == UP_KEY)
		fdf->div_y -= 20;
	else if (key == RIGHT_KEY)
		fdf->div_x += 20;
	else if (key == DOWN_KEY)
		fdf->div_y += 20;
	else if (key == LEFT_KEY)
		fdf->div_x -= 20;
	else if (key == PLUS_KEY)
		fdf->zoom *= 1.2;
	else if (key == MINUS_KEY)
		fdf->zoom /= 1.2;
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	fdf->img->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bits_per_pixel,
			&fdf->img->line_lenght,
			&fdf->img->endian);
	rendring(fdf);
	return (0);
}

int	destroy_win()
{
		exit(1);
	return (0);
}
