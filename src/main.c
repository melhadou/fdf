/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:32:25 by melhadou          #+#    #+#             */
/*   Updated: 2023/06/12 16:41:33 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

// normed
t_fdf	*fdf_init(int fd)
{
	t_fdf			*fdf;
	char			**map;
	t_double		**i_map;

	map = read_map(fd);
	if (!map)
		return (NULL);
	i_map = parse_map(map);
	fdf = final_map(i_map);
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
	return (fdf);
}

int	main(int argc, char *argv[])
{
	int			fd;
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
		fdf = fdf_init(fd);
		rendring(fdf);
		mlx_hook(fdf->mlx_win, 2, 0, &key_hook, fdf);
		mlx_hook(fdf->mlx_win, 17, 0, &destroy_win, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
