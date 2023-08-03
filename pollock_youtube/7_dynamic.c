#include "mlx/mlx.h"
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 700


int	main(void)
{
	void	*win;
	void	*mlx;

	srand(time(NULL));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 
				WIDTH,
				HEIGHT,
				"Pollock");
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
		{
			mlx_pixel_put(mlx,
				win, 
				x, 
				y,
				rand() % 0xffffff);
		}
	}

	mlx_string_put(mlx,
			win,
			WIDTH * 0.7,
			HEIGHT * 0.95,
			0xff,
			"POLLOCK");
	mlx_loop(mlx);
}
