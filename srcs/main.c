#include "../includes/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	int		x;
	int		y;
	t_data	data;

	x = 0;
	y = 0;

	init_data(&data);
	//画面をグラデーションで塗りつぶす
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            float t = (float)x / WINDOW_WIDTH;
            float u = (float)y / WINDOW_HEIGHT;

            int red = (1 - t) * (1 - u) * 255 + t * (1 - u) * 0 + (1 - t) * u * 255 + t * u * 0;
            int green = (1 - t) * (1 - u) * 0 + t * (1 - u) * 0 + (1 - t) * u * 255 + t * u * 255;
            int blue = (1 - t) * (1 - u) * 0 + t * (1 - u) * 0 + (1 - t) * u * 0 + t * u * 255;

            int color = (red << 16) | (green << 8) | blue; // Combine red, green, and blue values into color value
            my_mlx_pixel_put(&data, x, y, color);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	wait_input(&data);
	return (0);
}
