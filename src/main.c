/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/10 15:52:04 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	* 	BUG:		 	fdf cant read from a file with only one line
	 
	* 	NOTE: 		use float instead of int => task 1 === DONE
	
	*		WARNING:	z scale should be smaller, dvided by a number === DONE
*/
#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->img = malloc(sizeof(t_data));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	fdf->img->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, \
									&fdf->img->bits_per_pixel, \
									&fdf->img->line_lenght, \
									&fdf->img->endian);
	fdf->zoom = ft_zome(fdf);
	fdf->div_x = 0;
	fdf->div_y = 0;
}

int	main(int argc, char *argv[])
{
	int			fd;
	char		**map;
	t_double	**i_map;
	t_fdf		*fdf;

	if (argc != 2)
	{
		ft_printf("usage: %s filename", argv[0]);
		return (1);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == 0)
		{
			ft_printf("could not open file %s\n", argv[1]);
			return (1);
		}
		map = read_map(fd);
		if (!map)
			return (1);
		i_map = parse_map(map);
		fdf = final_map(i_map);
		fdf_init(fdf);
		rendring(fdf);
		mlx_hook(fdf->mlx_win, 2, 0, &key_hook, fdf);
		mlx_hook(fdf->mlx_win, 17, 0, &destroy_win, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
