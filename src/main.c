/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/03/16 17:27:03 by melhadou         ###   ########.fr       */
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
	y = 0;
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

		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 2080, 1400, "FDF");
		i_map = parse_map(map);
		t_map **f_map = final_map(i_map);

		draw_line(mlx, mlx_win, 10, 10, 20, 20, 0xFF0000);
	while (y < f_map[0]->row)
	{
		x = 1;
		while (x < f_map[0]->col)
		{
			// printf ("res ---> {%d} {%d}\n", f_map[i]->p[j]->x, f_map[i]->p[j]->y);
			drawline(mlx, mlx_win, f_map[y]->p[x - 1]->x, f_map[y]->p[x - 1]->y, f_map[y]->p[x]->x,f_map[y]->p[x - 1]->y);
			drawline(mlx, mlx_win, f_map[y]->p[x - 1]->x, f_map[y]->p[x - 1]->y, f_map[y]->p[x - 1]->x,f_map[y]->p[x]->y);
				// draw_line(mlx, mlx_win, j * 30, i * 30, j * 30, (i + 1) * 30, 0x00FF00);
			// printf("(x = %d, y = %d)  ",f_map[i]->p[j]->x, f_map[i]->p[j]->y);
			x++;
		}
		y++;
	}
	
				// draw_line(mlx, mlx_win, j * 30, i * 30, (j + 1) * 30, i * 30, 0xFF0000);
				// draw_line(mlx, mlx_win, iso_map[j]->x * 3, iso_map[j]->y * 3,iso_map[j]->x * 3, iso_map[j]->y * 3, 0xFF0000);
				// draw_line(mlx, mlx_win, j * 30, i * 30, j * 30, (i + 1) * 30, 0x00FF00);
		mlx_loop(mlx);
	}
}
