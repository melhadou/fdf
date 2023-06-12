/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:19:14 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/12 16:41:26 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_t_double(t_double *p)
{
	int	i;

	i = -1;
	while (p->arr[++i])
		free(p->arr);
	free(p);
}

int	free_fdf(t_fdf *res)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < res->row)
	{
		len = 0;
		while (len < res->col)
		{
			free(res->map[i].p[len]);
			len++;
		}
		free(res->map[i].p);
		i++;
	}
	free(res->map);
	free(res);
	return (0);
}

// need to check file ending
// int	check_file_extension(char *file_name)
// {
// 	int	i;
// 	int	len;

// 	if (!file_name)
// 		return (0);
// 	i = 0;
// 	len = ft_strlen(file_name);
// 	while (file_name[len] && i != 4)
// 	{
// 		if (ft_strncmp(".fdf", ft_substr(file_name, len - 4, 4), 4))
// 			return (0);
// 		i++;
// 		len--;
// 	}
// 	return (0);
// }

int	ft_zome(t_fdf *fdf)
{
	int	nbx;
	int	nby;
	int	zome;

	nbx = 0;
	nby = 0;
	while (nbx * fdf->col < WINDOW_WIDTH)
		nbx++;
	while (nby * fdf->row < WINDOW_HEIGHT)
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
