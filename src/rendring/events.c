/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:28:17 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/08 16:28:47 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, t_fdf *f)
{
	if (key == 53)
		exit(1);
	else if (key == UP_KEY)
		f->div_y -= 20;
	else if (key == RIGHT_KEY)
		f->div_x += 20;
	else if (key == DOWN_KEY)
		f->div_y += 20;
	else if (key == LEFT_KEY)
		f->div_x -= 20;
	else if (key == PLUS_KEY)
		f->zoom *= 1.2;
	else if (key == MINUS_KEY)
		f->zoom /= 1.2;
	mlx_clear_window(f->mlx, f->mlx_win);
	f->i->i = mlx_new_image(f->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	f->i->a = mlx_get_data_addr(f->i->i, &f->i->b, &f->i->l, &f->i->e);
	rendring(f);
	return (0);
}
