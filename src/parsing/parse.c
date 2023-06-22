/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:30:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/22 16:50:52 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//normed
t_double	*parse_map(char **map)
{
	t_double	*ret_fdf;
	size_t		len;
	size_t		i;

	i = 0;
	if (!map)
		return (NULL);
	len = arr_len(map);
	ret_fdf = malloc(len * sizeof(t_double));
	if (!ret_fdf)
		return (NULL);
	while (map[i])
	{
		ret_fdf[i] = split_line(map[i]);
		i++;
	}
	return (ret_fdf);
}

t_double	split_line(char *line)
{
	t_double	res;
	char		**sp_line;
	int			i;

	i = 0;
	sp_line = ft_split(line, ' ');
	res.size = arr_len(sp_line);
	res.arr = malloc(res.size * sizeof(double));
	if (!res.arr)
	{
		free(res.arr);
		return (res);
	}
	while (sp_line[i])
	{
		res.arr[i] = ft_atoi(sp_line[i]);
		i++;
	}
	ft_free_string(sp_line);
	return (res);
}
