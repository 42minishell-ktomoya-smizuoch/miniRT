#include "../includes/minirt.h"

//オレンジを表示mlxで
int main(void)
{
	int		x;
	int		y;
	t_data	data;

	x = 0;
	y = 0;

	// 使用例
    const char *buf = "123 456 test A 3.1415926";
	double d;
    int n1, n2;
    char str[10], ch;

    if (ft_sscanf(buf, "%d %d %s %c %lf", &n1, &n2, str, &ch ,&d) == 5) {
        printf("Read int: %d\n", n1);
        printf("Read int: %d\n", n2);
        printf("Read string: %s\n", str);
        printf("Read char: %c\n", ch);
		printf("Read double: %lf\n", d);
    } else {
        printf("Error in sscanf\n");
    }
	printf("=====================================\n");
	sscanf(buf, "%d %d %s %c %lf", &n1, &n2, str, &ch ,&d);
	printf("Read int: %d\n", n1);
	printf("Read int: %d\n", n2);
	printf("Read string: %s\n", str);
	printf("Read char: %c\n", ch);
	printf("Read double: %lf\n", d);

	init_data(&data);
	while (y < WINDOW_HEIGHT)
	{
		while (x < WINDOW_WIDTH)
		{
			mlx_pixel_put(data.mlx, data.win, x, y, 0x00FFA500);
			x++;
		}
		x = 0;
		y++;
	}
	wait_input(&data);
	return (0);
}
