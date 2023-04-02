/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:30:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/04/01 06:25:08 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return res;
}

int_array **parse_map(char **map)
{
	int_array **ret_map;
	size_t len;
	size_t i;

	i = 0;
	if(!map)
		return NULL;
	len = arr_len(map);
	ret_map = malloc((len + 1) * sizeof(int_array *));
	if (!ret_map)
		return NULL;
	while (map[i])
	{
		ret_map[i] = split_line(map[i]);
		i++;
	}

	ret_map[i] = NULL;
	return ret_map;
}

t_map **final_map(int_array **map)
{
	t_map **res;
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	while (map[len])
		len++;

	res = malloc((len + 1) * sizeof(t_map *));
	if (!res)
		return NULL;

	while (i < len)
	{
		res[i] = malloc(sizeof(t_map));
		if (!res[i])
		{
			free(res);
			return NULL;
		}
		i++;
	}

	res[0]->row = len;
	res[0]->col = map[0]->size;
	i = 0;	

	while (i < res[0]->row)
	{
		len = 0;
		res[i]->p = malloc((res[0]->col + 1) * sizeof(t_point *));
		if (!res[i]->p)
		{
			free(res);
			return NULL;
		}
		while (len < res[0]->col)
		{
			res[i]->p[len] = malloc(sizeof(t_point));
			if (!res[i]->p[len])
			{
				printf("hello");
				free(res[i]->p);
				free(res);
				return NULL;
			}
			to_Isometric(i, len, map[i]->arr[len], res[i]->p[len]);
			len++;
		}
		res[i]->p[len] = NULL;
		i++;
	}
	res[i] = NULL;
	return (res);
}
