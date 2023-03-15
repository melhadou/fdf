/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:30:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/12 21:44:58 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

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
	int i;

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
