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
	for (int i = 0; i < 100; ++i)
	{
		mlx_pixel_put(mlx,
			win, 
			200 + i, 
			200,
			0xff0000);
	}
	mlx_loop(mlx);
}
