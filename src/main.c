/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/30 01:49:34 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		int_array **i_map;
		char **map;
		t_map **f_map;
		fd = open(argv[1],O_RDONLY);
		if(fd == 0)
		{
			printf("could not open file %s\n", argv[1]);
			return 1;
		}
		map = read_map(fd);
		if(!map)
			return 1;
		i_map = parse_map(map);
		f_map = final_map(i_map);


		f_map[0]->img = malloc(sizeof(t_data));
		f_map[0]->mlx = mlx_init();
		f_map[0]->mlx_win = mlx_new_window(f_map[0]->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
		f_map[0]->img->img = mlx_new_image(f_map[0]->mlx,WINDOW_WIDTH, WINDOW_HEIGHT);
		f_map[0]->img->addr = mlx_get_data_addr(f_map[0]->img->img, &f_map[0]->img->bits_per_pixel, &f_map[0]->img->line_length, &f_map[0]->img->endian);

		f_map[0]->div_x = 0;
		f_map[0]->div_y = 0;

		// redring
		rendring(f_map);

		mlx_key_hook(f_map[0]->mlx_win, &key_hook, f_map);
		mlx_loop(f_map[0]->mlx);
	}
}
