#include "mlx/mlx.h"

int	main(void)
{
	void	*win;
	void	*mlx;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 
				800,
				800,
				"Pixel put");
	for (int y = 50; y < 750; ++y)
	{
		for (int x = 50; x < 750; ++x)
		{
			mlx_pixel_put(mlx,
				win, 
				x, 
				y,
				0xff0000);
		}
	}
	mlx_loop(mlx);
}
