/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:30:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/08 01:13:29 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_frees(int_array **p)
{
	int i;
	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
}

int_array *split_line(char *line)
{
	int_array *res;
	char **sp_line;
	int i;

	i = 0;
	res = malloc(sizeof(int_array));
	if(!res)
		return NULL;
	sp_line = ft_split(line, ' ');
	res->size = arr_len(sp_line);
	res->arr = malloc(res->size * sizeof(int));
	if(!res->arr)
	{
		free(res);
		return NULL;
	}
	while (sp_line[i])
	{
		res->arr[i] = ft_atoi(sp_line[i]);
		i++;
	}
	// dprintf(1,"%d",res->arr[0]);
	i = 0;
	while (sp_line[i])
	{
		free(sp_line[i]);
		i++;
	}
	free(sp_line);
	return res;
}

int_array **parse_map(char **map)
{
	int_array **ret_fdf;
	size_t len;
	size_t i;

	i = 0;
	if(!map)
		return NULL;
	len = arr_len(map);
	ret_fdf = malloc((len + 1) * sizeof(int_array *));
	if (!ret_fdf)
		return NULL;
	while (map[i])
	{
		ret_fdf[i] = split_line(map[i]);
		i++;
	}

	ret_fdf[i] = NULL;
	return ret_fdf;
}

t_fdf *final_map(int_array **map)
{
	t_fdf *res;
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	res = malloc(sizeof(t_fdf));
	if (!res)
		return NULL;

	res->row = len;
	res->col = map[0]->size;
	i = 0;
	
	res->map = malloc(res->col * sizeof(t_map *));
	if (!res->map)
	{
		free(res);
		return NULL;
	}

	while (i < res->row)
	{
		len = 0;
		res->map[i].p = malloc((res->col + 1) * sizeof(t_point *));
		if (!res->map[i].p)
		{
			free(res->map);
			free(res);
			return NULL;
		}
		while (len < res->col)
		{
			res->map[i].p[len] = malloc(sizeof(t_point));
			if (!res->map[i].p[len])
			{
				free(res->map[i].p);
				free(res->map);
				free(res);
				return NULL;
			}
			to_Isometric(i, len, map[i]->arr[len], res->map[i].p[len]);
			len++;
		}
		res->map[i].p[len] = NULL;
		i++;
	}
	res->map[i].p = NULL;
	return (res);
}
