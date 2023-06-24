/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:44:59 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/24 19:10:17 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
t_fdf	populate_fdf(t_double *map, int col)
{
	size_t	i;
	size_t	j;
	t_fdf	fdf;

	i = 0;
	validate_map(map, col);
	fdf.line = malloc(sizeof(t_line) * col);
	fdf.col = col;
	while (i < fdf.col)
	{
		j = 0;
		fdf.line[i].row = map[i].size;
		fdf.line[i].p = malloc(sizeof(t_point) * fdf.line[i].row);
		while (j < fdf.line[i].row)
		{
			fdf.line[i].p[j] = to_isometric(i, j, map[i].arr[j]);
			j++;
		}
		i++;
	}
	return (fdf);
}
