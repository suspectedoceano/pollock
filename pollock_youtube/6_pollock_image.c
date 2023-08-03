#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	srand(time(NULL));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "pollock image");
	img.img = mlx_new_image(mlx, 600, 600);

	/*
	 * Init all the image data
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	/*
	 * Line Len is in bytes
	*/
	printf("600 Pixels->%d\n", img.line_length);

	for (int y = 50; y < 550; ++y)
	{
		for (int x = 50; x < 550; ++x)
		{
			my_mlx_pixel_put(&img,
					x,
					y,
					0xff0000);
		}
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
}
