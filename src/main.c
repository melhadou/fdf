/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/14 16:35:14 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	void *mlx;
	void *mlx_win;
	// void *mlx_img;
	int_array **i_map;
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	if ( argc != 2 )
	{
		printf( "usage: %s filename", argv[0] );
		return (1);
	}else
	{
		int fd;
		char **map;
		fd = open(argv[1],O_RDONLY);
		if(fd == 0)
		{
			printf("could not open file %s\n", argv[1]);
			return 1;
		}
		map = read_map(fd);
		if(!map)
			return 1;

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 3080, 1720, "FDF");
		// mlx_img = mlx_new_image(mlx, 1080, 720);
		i_map = parse_map(map);

		t_vec *u;
		u = malloc(sizeof(t_vec));


		t_vec *v;
		v = malloc(sizeof(t_vec));
		while(i_map[i])
		{
			j = 0;
			while (j < i_map[i]->size)
			{
				draw_line(mlx, mlx_win, u->x * 30, u->y * 30, v->x * 30, v->y * 30, 0xFFFFFF);
				j++;
			}
			i++;
		}
				// draw_line(mlx, mlx_win, j * 30, i * 30, (j + 1) * 30, i * 30, 0xFF0000);
				// draw_line(mlx, mlx_win, iso_map[j]->x * 3, iso_map[j]->y * 3,iso_map[j]->x * 3, iso_map[j]->y * 3, 0xFF0000);
				// draw_line(mlx, mlx_win, j * 30, i * 30, j * 30, (i + 1) * 30, 0x00FF00);
		mlx_loop(mlx);
	}
}
