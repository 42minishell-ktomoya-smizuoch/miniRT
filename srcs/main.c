#include "../includes/minirt.h"

//オレンジを表示mlxで
//int main(void)
//{
//	int		x;
//	int		y;
//	void	*mlx;
//	void	*mlx_win;
//
//	x = 0;
//	y = 0;
//
//	// 使用例
//    const char *data = "123 456 test A 3.1415926";
//	double d;
//    int n1, n2;
//    char str[10], ch;
//
//    if (ft_sscanf(data, "%d %d %s %c %lf", &n1, &n2, str, &ch ,&d) == 5) {
//        printf("Read int: %d\n", n1);
//        printf("Read int: %d\n", n2);
//        printf("Read string: %s\n", str);
//        printf("Read char: %c\n", ch);
//		printf("Read double: %lf\n", d);
//    } else {
//        printf("Error in sscanf\n");
//    }
//	printf("=====================================\n");
//	sscanf(data, "%d %d %s %c %lf", &n1, &n2, str, &ch ,&d);
//	printf("Read int: %d\n", n1);
//	printf("Read int: %d\n", n2);
//	printf("Read string: %s\n", str);
//	printf("Read char: %c\n", ch);
//	printf("Read double: %lf\n", d);
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
//	while (y < WINDOW_HEIGHT)
//	{
//		while (x < WINDOW_WIDTH)
//		{
//			mlx_pixel_put(mlx, mlx_win, x, y, 0x00FFA500);
//			x++;
//		}
//		x = 0;
//		y++;
//	}
//	mlx_loop(mlx);
//	return (0);
//}

int	main(void)
{
	t_data	data;

	init_data(&data);
	wait_input(&data);
}
