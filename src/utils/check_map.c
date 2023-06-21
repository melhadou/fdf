/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:36:41 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/21 16:39:34 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// get content of map. 
// splite lines of map
// check every element in that map
// free the line, 
// every element should be float not int
int	check_file_extension(char *file_name)
{
	int	fname_len;

	fname_len = ft_strlen(file_name);
	if (file_name[fname_len - 5] == '/')
		fname_len -= 5;
	if (fname_len < 5)
		return (0);
	if (file_name[fname_len - 1] != 'f' || file_name[fname_len - 2] != 'd' \
			|| file_name[fname_len - 3] != 'f' || file_name[fname_len - 4] != '.')
		return (0);
	return (1);
}

// int check_map(t_double **map)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (!map)
// 		return (0);
// 	
// 	while (map)
// 	return (0);
// }
