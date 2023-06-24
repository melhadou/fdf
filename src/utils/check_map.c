/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:36:41 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/24 10:57:34 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len > 4)
	{
		if (!ft_strcmp(&file_name[len - 4], ".fdf"))
		{
			return (1);
		}
	}
	ft_printf("invalid file extension\n");
	return (0);
}

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == 0)
	{
		ft_printf("could not open file %s\n", file_name);
		exit(1);
	}
	return (fd);
}

void	validate_map(t_double *map, size_t col)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < col)
	{
		j = 0;
		while (j < map[i].size)
			j++;
		if (j < 2)
		{
			ft_printf("error: invalid map\n");
			exit(1);
		}
		i++;
	}
}

int	check_map_alpha(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_isdigit(map[i][j]) && map[i][j] != '/' && map[i][j] != '*')
			{
				ft_printf("Error on map: Invalid characters\n");
				return (0);
			}
		}
	}
	return (1);
}
