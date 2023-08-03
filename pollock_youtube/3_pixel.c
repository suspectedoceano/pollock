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
	mlx_pixel_put(mlx,
			win, 
			200, 
			200,
			0xff0000);
	mlx_loop(mlx);
}
