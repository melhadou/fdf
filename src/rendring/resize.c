/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:42:55 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/05 04:54:35 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void resize_map(t_fdf *fdf)
{
	int x_max;
	int y_max;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	x_max = 0;
	y_max = 0;

	printf("hello");
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{		
			if (fdf->map[i].p[j]->x > x_max)
				x_max = fdf->map[i].p[j]->x;
			if (fdf->map[i].p[j]->y > y_max)
				y_max = fdf->map[i].p[j]->y;
			j++;
		}
		i++;
	}
}
