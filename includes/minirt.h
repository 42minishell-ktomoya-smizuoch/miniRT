/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:44:38 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/25 18:42:36 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

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

# ifndef OBJ_MAX_SIZE
#  define OBJ_MAX_SIZE 100
# endif

# ifndef LIGHT_MAX_SIZE
#  define LIGHT_MAX_SIZE 100
# endif

typedef int		t_material_type;

typedef enum s_type
{
	TYPE_AMBIENT_LIGHT,
	TYPE_CAMERA,
	TYPE_LIGHT,
	TYPE_SPHERE,
	TYPE_PLANE,
	TYPE_CYLINDER,
	TYPE_RECTANGLE,
	TYPE_UNKNOWN
}	t_type;

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
	t_color	color;
	double	ratio;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	normal;
	t_vec3	lower_left_corner;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	double	fov;
	double	lens_radius;
	double	focus_distance;
	double	time0;
	double	time1;
}	t_camera;

typedef struct s_init_cam
{
	t_vec3	lookfrom;
	t_vec3	lookat;
	t_vec3	vup;
	double	vfov;
	double	aspect_ratio;
	double	aperture;
	double	focus_dist;
	double	time0;
	double	time1;
	bool	no_option;
}	t_init_cam;

typedef struct s_light
{
	t_vec3	position;
	t_color	color;
	double	intensity;
}	t_light;

typedef struct s_light_list
{
	t_light	*lights;
	int		count;
}	t_light_list;

typedef struct s_sphere
{
	t_vec3			center;
	double			diameter;
	double			radius;
	t_color			color;
	t_material_type	material;
}	t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
	t_material_type	material;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axisnorm;
	double			diameter;
	double			height;
	t_color			color;
	t_material_type	material;
}	t_cylinder;

typedef struct s_rectangle
{
	t_vec3			p0;
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_vec3			normal;
	t_material_type	material;
	t_color			color;
}	t_rectangle;

typedef struct s_limits
{
	double	max;
	double	min;
}	t_limits;

// Structure to store hit information
typedef struct s_hit_record
{
	t_vec3			point;
	t_vec3			normal;
	double			t;
	int				front_face;
	t_color			color;
	double			fuzz;
	double			ref_idx;
	t_material_type	material;
}	t_hit_record;

struct			s_hittable;
typedef int		(*t_hit_fn)(struct s_hittable *,
	t_ray *, t_limits, t_hit_record *);

// Hittable structure
typedef struct s_hittable
{
	void		*data;
	t_hit_fn	hit;
	void		(*free_data)(void *);
}	t_hittable;

typedef struct s_hittable_list
{
	t_hittable	*objects;
	int			size;
	int			capacity;
}	t_hittable_list;

typedef struct s_ray_color
{
	t_hittable_list	*world;
	t_light_list	*lights;
	t_ambient		*ambient;
	int				depth;
}	t_ray_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				samples_per_pixel;
	int				max_depth;
	int				obj_size;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_light_list	lights;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	t_rectangle		rectangle;
	t_hittable_list	*world;
}	t_data;

//utils
void	print_progress(int current, int total);

// parser
int		check_file_extension(const char *file_path, const char *extension);
void	parse_file(const char *file, t_data *data);
void	parse_line(const char *line, t_data *data, int obj_cnt[8]);
void	parse_ambient_light(const char *line, t_ambient *amb);
void	parse_camera(const char *line, t_camera *camera);
void	scan_camera(const char *line, t_init_cam *setter);
void	parse_light(const char *line, t_data *data);
void	scan_light(const char *line, t_light *light);
void	parse_sphere(const char *line, t_hittable_list *obj_list);
void	scan_sphere(const char *line, t_sphere *sphere);
void	parse_plane(const char *line, t_hittable_list *obj_list);
void	scan_plane(const char *line, t_plane *plane);
void	parse_cylinder(const char *line, t_hittable_list *obj_list);
void	scan_cylinder(const char *line, t_cylinder *cylinder);
bool	is_out_of_range_int(int num, int lower, int upper);
bool	is_out_of_range_double(double num, double lower, double upper);
bool	is_rgb_out_of_range(t_color color);
bool	is_vec3_out_of_range(t_vec3 vec3, double lower, double upper);
void	parse_rectangle(const char *line, t_hittable_list *obj_list);
t_type	get_object_type(const char *id);
void	check_object_size(int obj_cnt[8], int obj_size);

// mlx
void	init_data(t_data *data);
void	wait_input(t_data *data);
int		esc_close(int keycode, t_data *data);
int		exit_on_close(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//ray
void	render(t_data *data);
t_color	ray_color(t_ray *ray, t_ray_color r);
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
t_vec3	vec_mul(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
t_color	vec3_to_color(t_vec3 v);

//random
double	random_double(void);
double	random_double_range(double min, double max);
t_vec3	random_in_unit_sphere(void);
t_vec3	random_unit_vector(void);
t_vec3	random_in_hemisphere(const t_vec3 *normal);
t_vec3	color_to_vec3(t_color c);
t_color	scale_color(t_color color, int samples_per_pixel);

//error
void	exit_with_error(const char *err_msg);

t_color	compress_rgb(t_color color);

void	error_pixselput(t_data *data);

#endif
