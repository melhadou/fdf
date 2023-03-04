#include "fdf.h"
#include <stdio.h>

// typedef struct t_vars {
// 	void *mlx;
// 	void *mlx_win;
// } t_vars;

// int	ft_close(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[])
{

	// int i = -1;
	// int j ; 
	// // void *img;
	// t_vars vars;

	// vars.mlx = mlx_init();
	// vars.mlx_win = mlx_new_window(vars.mlx, 600, 600, "Hello world!");
	// // img = mlx_new_image(vars.mlx, 700, 700);
	// j = 40;
	// while (j < 600 )
	// {
	// 	while (++i < 600)
	// 	{
	// 		mlx_pixel_put(vars.mlx, vars.mlx_win, i , j, 0xFF0033);
	// 		mlx_pixel_put(vars.mlx, vars.mlx_win, j , i, 0xFF0033);
	// 	}
	// 	j += 40;
	// 	i = 0;
	// }

	// j = ft_strlen("mohamed");
	// printf("%d ", j);
	// // mlx_put_image_to_window(vars.mlx, vars.mlx_win, img, 300, 300);
	// mlx_hook(vars.mlx_win, 2, 1L<<0, ft_close, &vars);
	// mlx_loop(vars.mlx);
	
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
			printf("could not open file %s\n", argv[1]);
		map = read_map(fd);
		printf("%s",map[0]);
	}
}
