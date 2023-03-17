/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:42:55 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/18 00:09:52 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#include <stdio.h>

void resize_map(t_map **map)
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
	while (i < map[0]->row)
	{
		j = 0;
		while (j < map[0]->col)
		{		
			if (map[i]->p[j]->x > x_max)
				x_max = map[i]->p[j]->x;
			if (map[i]->p[j]->y > y_max)
				y_max = map[i]->p[j]->y;
			j++;
		}
		i++;
	}

	if (x_max > WINDOW_WIDTH || y_max > WINDOW_HEIGHT)
		printf("hello");
}
