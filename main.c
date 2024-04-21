#include "../includes/minirt.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

//オレンジを表示mlxで
int main(void)
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;

	x = 0;
	y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	while (y < WINDOW_HEIGHT)
	{
		while (x < WINDOW_WIDTH)
		{
			mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFA500);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(mlx);
	return (0);
}
