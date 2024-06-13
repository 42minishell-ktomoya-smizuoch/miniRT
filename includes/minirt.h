#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../lib/libft/get_next_line/get_next_line_bonus.h"
# include "error.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

# define KEY_ESC 53
# define ON_DESTROY 17

# define ERR_FILE_EXTENSION "Error: The filename is not appropriate."
# define ERR_OPEN_FILE "Error: failed to open the file"
# define ERR_READ_FILE "Error: failed to read the file"
# define ERR_PARSE_FILE "Error: failed to parse the file"
# define ERR_MALLOC "Error: failed to allocate memory"
# define ERR_ARG "Error: invalid argument"
# define ERR_FILE_FORMAT "Error: invalid file format"

# define LAMBERTIAN 1
# define METAL 2
# define DIELECTRIC 3

//int型のt_material_typeを定義
typedef int t_material_type;

//structure
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	double	time;
}	t_ray;

typedef struct s_ambient
{
    t_color color;
    double ratio;
} t_ambient;


typedef struct s_camera {
    t_vec3 origin;
	t_vec3	normal;
    t_vec3 lower_left_corner;
    t_vec3 horizontal;
    t_vec3 vertical;
    t_vec3 u, v, w;
	double	fov;
    double lens_radius;
    double time0, time1; // 新しく追加: シャッターの開閉時間
} t_camera;

typedef struct s_light {
    t_vec3 position;
    t_color color;
    double intensity;
} t_light;

typedef struct s_light_list {
    t_light *lights;
    int count;
} t_light_list;


typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane {
    t_vec3 point;
    t_vec3 normal;
    t_color color;
    t_material_type material;
} t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axisnorm;
	double	diameter;
	double	height;
	t_color	color;
	t_material_type material;
}	t_cylinder;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_ambient	amb;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_data;

//utils
void print_progress(int current, int total);

// parser
int		check_file_extension(const char *file_path, const char *extension);
void	parse_file(const char *file, t_data *data);
void	parse_line(const char *line, t_data *data);
void	parse_ambient_light(const char *line, t_ambient *amb);

// mlx
void	init_data(t_data *data);
void	wait_input(t_data *data);
int		esc_close(int keycode, t_data *data);
int		exit_on_close(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//ray
t_vec3	vec_new(double x, double y, double z);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_scalar(t_vec3 a, double t);
double	vec_dot(t_vec3 a, t_vec3 b);
double	vec_length(t_vec3 a);
t_vec3	vec_normalize(t_vec3 a);
t_vec3	ray_at(t_ray ray, double t);
t_vec3	vec_uint(t_vec3 v);
int		vec_to_color(t_color col);
t_vec3 vec_mul(t_vec3 a, t_vec3 b);
t_vec3 vec_cross(t_vec3 a, t_vec3 b);
t_color vec3_to_color(t_vec3 v);

//random
double random_double(); // 0から1の間のランダムな浮動小数点数を生成
double random_double_range(double min, double max); // 指定された範囲のランダムな浮動小数点数を生成
t_vec3 random_in_unit_sphere();
t_vec3 random_unit_vector();
t_vec3 random_in_hemisphere(const t_vec3 *normal);
t_vec3 color_to_vec3(t_color c);
t_color scale_color(t_color color, int samples_per_pixel);

//error
void	exit_with_error(const char *err_msg);

#endif
