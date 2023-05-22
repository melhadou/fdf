/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/05/22 19:20:23 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_zome(t_fdf *fdf)
{
	int    nbx;
	int    nby;
	int    zome;

	nbx = 0;
	nby = 0;
	while (nbx * fdf->col < WINDOW_WIDTH)
		nbx++;
	while (nby * fdf->row < WINDOW_HEIGHT)
		nby++;
	zome = (nbx + nby) / 6 + 1;
	return (zome);
}

int	main(int argc, char *argv[])
{
	if ( argc != 2 )
	{
		printf( "usage: %s filename", argv[0] );
		return (1);
	}
	else
	{
		int fd;
		t_int **i_map;
		char **map;
		t_fdf *fdf;
		fd = open(argv[1],O_RDONLY);
		if(fd == 0)
		{
			printf("could not open file %s\n", argv[1]);
			return (1);
		}
		
		map = read_map(fd);
		if(!map)
			return (1);
		i_map = parse_map(map);
		fdf = final_map(i_map);

		fdf->img = malloc(sizeof(t_data));
		fdf->mlx = mlx_init();
		fdf->mlx_win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
		fdf->img->img = mlx_new_image(fdf->mlx,WINDOW_WIDTH, WINDOW_HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_lenght, &fdf->img->endian);
		fdf->zoom = ft_zome(fdf);
		fdf->div_x = 0;
		fdf->div_y = 0;

		rendring(fdf);

		mlx_hook(fdf->mlx_win, 2, 0, &key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
