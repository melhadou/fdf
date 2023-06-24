/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:19:14 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/24 19:34:32 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_t_double(t_double *p, size_t col)
{
	size_t	i;

	i = -1;
	while (++i < col)
		free(p[i].arr);
	free(p);
}

void	ft_free_string(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_zome(t_fdf fdf)
{
	int	nbx;
	int	nby;
	int	zome;

	nbx = 0;
	nby = 0;
	while (nbx * fdf.col < WINDOW_WIDTH)
		nbx++;
	while (nby * fdf.line[0].row < WINDOW_HEIGHT)
		nby++;
	zome = (nbx + nby) / 6 + 1;
	return (zome);
}

t_double	**free_parsed_map(t_double **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]->arr);
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
