/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/12 16:43:43 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// normed
size_t	arr_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

char	**append_to_arr(char **map, char *line)
{
	char	**ret_map;
	size_t	i;

	i = 0;
	ret_map = NULL;
	if (!map)
	{
		map = malloc(sizeof(char *));
		*map = NULL;
	}
	ret_map = malloc((arr_len(map) + 2) * sizeof(char *));
	if (!ret_map)
		return (NULL);
	while (map[i])
	{
		ret_map[i] = ft_strdup(map[i]);
		i++;
	}
	ret_map[i] = line;
	ret_map[i + 1] = NULL;
	ft_free(map);
	return (ret_map);
}

char	**read_map(int fd)
{
	char	**map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("File Does Not Exist Or its an empty file\n");
		return (NULL);
	}
	while (line)
	{
		if (!line || ft_strlen(line) == 1)
		{
			ft_printf("Error on map: empty line\n");
			return (NULL);
		}
		map = append_to_arr(map, line);
		line = get_next_line(fd);
	}
	return (map);
}
