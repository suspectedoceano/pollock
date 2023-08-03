#include "mlx/mlx.h"
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	void	*win;
	void	*mlx;

	srand(time(NULL));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 
				600,
				600,
				"Pollock");
	for (int y = 50; y < 550; ++y)
	{
		for (int x = 50; x < 550; ++x)
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
			500,
			575,
			0xff0000,
			"POLLOCK");
	mlx_loop(mlx);
}
