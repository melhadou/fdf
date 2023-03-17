/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/18 00:23:13 by melhadou         ###   ########.fr       */
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
	size_t y;
	size_t x;
	y = 1;
	x = 0;
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
		
		
		i_map = parse_map(map);
		t_map **f_map = final_map(i_map);

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	
		while (y < f_map[0]->row)
		{
			x = 1;
			while (x < f_map[0]->col)
			{
				bresenham(mlx, mlx_win, *f_map[y]->p[x - 1], *f_map[y]->p[x]);
				bresenham(mlx, mlx_win, *f_map[y - 1]->p[x], *f_map[y]->p[x]);
				x++;
			}
			y++;
		}
		resize_map(f_map);
		mlx_loop(mlx);
	}
}
