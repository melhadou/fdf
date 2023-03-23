/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:32:42 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/23 01:46:51 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

float sc(t_map **map)
{
	int x_max;
	int y_max;
	int x_min;
	int y_min;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	x_min = map[i]->p[j]->x;
	y_min = map[i]->p[j]->y;
	x_max = x_min;
	y_max = y_min;
	while (i < map[0]->row)
	{
		j = 0;
		while (j < map[0]->col)
		{
			if (map[i]->p[j]->x > x_max)
				x_max = map[i]->p[j]->x;
			if (map[i]->p[j]->y > y_max)
				y_max = map[i]->p[j]->y;

			if (map[i]->p[j]->x < x_min)
				x_min = map[i]->p[j]->x;
			if (map[i]->p[j]->y < y_min)
				y_min = map[i]->p[j]->y;
			j++;
		}
		i++;
	}
	x_max += WINDOW_WIDTH / 2;
	y_max += WINDOW_HEIGHT / 2;

	float y_scale;
	y_scale = ((float) WINDOW_HEIGHT / (y_max - y_min));
	float x_scale;
	x_scale = ((float)WINDOW_WIDTH / (x_max - x_min));

	printf("y ==> max --> %d\t min --> %d,\t distance = %d ,\t scale -> %f \n",y_max,y_min, y_max - y_min,y_scale);

	printf("x ==> max --> %d\t min --> %d,\t distance = %d ,\t scale -> %f \n",x_max,x_min,x_max - x_min,x_scale);
	return (fmin(y_scale,x_scale));
}
