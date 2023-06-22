/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:21 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	fdf_init(int fd)
{
	t_fdf			fdf;
	char			**map;
	t_double		*i_map;
	size_t			col;

	map = read_map(fd);
	if (!map)
		exit(1);
	col = arr_len(map);
	i_map = parse_map(map);
	fdf = populate_fdf(i_map, col);
	fdf.img = malloc(sizeof(t_data));
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	fdf.img->img = mlx_new_image(fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.img->addr = mlx_get_data_addr(fdf.img->img, \
									&fdf.img->bits_per_pixel, \
									&fdf.img->line_lenght, \
									&fdf.img->endian);
	fdf.zoom = ft_zome(fdf);
	fdf.div_x = 0;
	fdf.div_y = 0;
	ft_free_string(map);
	ft_free_t_double(i_map, col);
	return (fdf);
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_fdf		fdf;

	if (argc != 2)
	{
		ft_printf("usage: %s filename", argv[0]);
		return (1);
	}
	else
	{
		fd = open_file(argv[1]);
		if (!check_file_extension(argv[1]))
		{
			ft_printf("invalid file extension\n");
			return (1);
		}
		fdf = fdf_init(fd);
		rendring(fdf);
		mlx_hook(fdf.mlx_win, 2, 0, &key_hook, &fdf);
		mlx_hook(fdf.mlx_win, 17, 0, &destroy_win, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}
