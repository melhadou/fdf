/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/07 17:07:41 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	* 	BUG: 	fdf cant read from a file with only one line
	 
	* 	TODO: 		huge refactore of code

	* 	NOTE: 		use float instead of int => task 1 === DONE
	
	*		WARNING:	z scale should be smaller, dvided by a number === DONE

*/

#include "fdf.h"
#include "mlx.h"

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
		t_double **i_map;
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
		mlx_hook(fdf->mlx_win, 17, 0, &destroy_win, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
