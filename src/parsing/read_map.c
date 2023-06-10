/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/10 18:01:31 by melhadou         ###   ########.fr       */
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
	
	if (!is_map_valid(map))
	{
		ft_printf("Error on map: invalid map\n");
		return (NULL);
	}
	
	return (map);
}

int	is_map_valid(char **map)
{
	size_t	first_line_len;
	size_t	i;

	if (!map)
		return (0);

	// Check the length of the first line
	first_line_len = 0;
	while (map[0][first_line_len])
		first_line_len++;

	// Check the length of each subsequent line
	i = 1;
	while (map[i])
	{
		size_t line_len = 0;
		while (map[i][line_len])
			line_len++;
		if (line_len != first_line_len)
			return (0);
		i++;
	}

	return (1);
}
