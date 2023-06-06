/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:30:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/03 16:23:11 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed but with func more then 25
t_int	*split_line(char *line)
{
	t_int	*res;
	char	**sp_line;
	int		i;

	i = 0;
	res = malloc(sizeof(t_int));
	if (!res)
		return (NULL);
	sp_line = ft_split(line, ' ');
	res->size = arr_len(sp_line);
	res->arr = malloc(res->size * sizeof(int));
	if (!res->arr)
	{
		free(res);
		return (NULL);
	}
	while (sp_line[i])
	{
		res->arr[i] = ft_atoi(sp_line[i]);
		i++;
	}
	ft_free(sp_line);
	return (res);
}

t_int	**parse_map(char **map)
{
	t_int		**ret_fdf;
	size_t		len;
	size_t		i;

	i = 0;
	if (!map)
		return (NULL);
	len = arr_len(map);
	ret_fdf = malloc((len + 1) * sizeof(t_int *));
	if (!ret_fdf)
		return (NULL);
	while (map[i])
	{
		ret_fdf[i] = split_line(map[i]);
		i++;
	}
	ret_fdf[i] = NULL;
	return (ret_fdf);
}

// NOTE: need to be understood
// BUG: should be normed
t_fdf	*allocate_memory(size_t row, size_t col)
{
	t_fdf	*res;

	res = malloc(sizeof(t_fdf));
	if (!res)
		return (NULL);
	res->row = row;
	res->col = col;
	res->map = malloc(col * sizeof(t_map *));
	if (!res->map)
	{
		free_fdf(res);
		return (NULL);
	}
	return (res);
}

int	populate_map(t_fdf *res, t_int **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < res->row)
	{
		j = 0;
		res->map[i].p = malloc((res->col + 1) * sizeof(t_point *));
		if (!res->map[i].p)
			return (0);
		while (j < res->col)
		{
			res->map[i].p[j] = malloc(sizeof(t_point));
			if (!res->map[i].p[j])
			{
				free_fdf(res);
				return (0);
			}
			to_isometric(i, j, map[i]->arr[j], res->map[i].p[j]);
			j++;
		}
		res->map[i].p[j] = NULL;
		i++;
	}
	res->map[i].p = NULL;
	return (1);
}

t_fdf	*final_map(t_int **map)
{
	t_fdf	*res;
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	res = allocate_memory(len, map[0]->size);
	if (!res)
		return (NULL);
	if (!populate_map(res, map))
	{
		free_fdf(res);
		return (NULL);
	}
	return (res);
}
