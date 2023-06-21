/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:44:59 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/21 22:12:06 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_fdf *fdf_alloc(t_double *map)
// {
// 	t_fdf		*res;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	res = malloc(sizeof(struct t_fdf)  + 1);
// 	if (!res)
// 		return (NULL);
// 	res->col = col_num(map);
// 	res->line = malloc((sizeof(t_line) * res->col) + 1);
// 	if (!res->line)
// 	{
// 		free_fdf(res);
// 		return (NULL);
// 	}
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i]->arr[j])
// 			j++;
// 		res->line[i] = malloc((sizeof(t_point) * j) + 1);
// 		if (!res->line[i])
// 		{
// 			free_fdf(res);
// 			return (NULL);
// 		}
// 		res->line[i].row = j;
// 		i++;
// 	}
// 	res->line[i] = NULL;
// 	return (res);
// }

// void	alloc_points(t_fdf *fdf)
// {
// 	size_t i;
// 	size_t j;

// 	i = 0;
// 	while (i < (*fdf).col)
// 	{
// 		j = 0;
// 		while (j < (*fdf)->line[i].row)
// 		{
// 			(*fdf)->line[i].p = malloc(sizeof(t_point));
// 			j++;
// 		}
// 		(*fdf)->line[i] = NULL;
// 		i++;
// 	}
// }

t_fdf	populate_fdf(t_double *map, int col)
{
	size_t i;
	size_t j;
	t_fdf fdf;
	
	i = 0;
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

// functino to count the number of line in map tdouble
// int col_num(t_double *map)
// {
// 	size_t col;

// 	col = 0;
// 	while (map[col])
// 		col++;
// 	dprintf(1, "col = %zu\n", col);
// 	return (col);
// }

// void	print_map(t_fdf fdf)
// {
// 	size_t	i_col;
// 	size_t	i_row;

// 	i_col = -1;

// 	while (++i_col < fdf->col)
// 	{
// 		i_row = 0;
// 		while (++i_row < fdf->line[i_col]->row)
// 			dprintf(1, "x = %f, y = %f, row = %zu\t", fdf->line[i_col][i_row].p->x, fdf->line[i_col][i_row].p->y, fdf->line[i_col]->row);
// 		dprintf(1, "\n");
// 	}
// }
