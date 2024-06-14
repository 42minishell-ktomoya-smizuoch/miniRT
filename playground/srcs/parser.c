/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:06:40 by ktomoya           #+#    #+#             */
/*   Updated: 2024/06/13 17:44:21 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdbool.h>

int	check_file_extension(const char *file_path, const char *extension)
{
	int	i;

	i = 0;
	if (*file_path == '.')
		return (1);
	while (file_path[i] != '.' && file_path[i] != '\0')
		i++;
	if (file_path[i] == '\0')
		return (1);
	if (ft_strncmp(&file_path[i], extension, ft_strlen(extension) + 1) != 0) {
		return (1);
	}
	return (0);
}

bool	in_range(double num, double lower, double upper)
{
	return (lower <= num && num <= upper);
}

bool	out_of_range(double num, double lower, double upper)
{
	return (num < lower || upper < num);
}

bool out_of_rgb_range(t_color color)
{
    return (out_of_range(color.r, 0, 255) || out_of_range(color.g, 0, 255) || out_of_range(color.b, 0, 255));
}

bool	out_of_vec3_range(t_vec3 vec3, double lower, double upper)
{
	return (out_of_range(vec3.x, lower, upper) || out_of_range(vec3.y, lower, upper)
			|| out_of_range(vec3.z, lower, upper));
}

bool	is_rgb_in_range(double r, double g, double b)
{
	return (in_range(r, 0, 255) && in_range(g, 0, 255) && in_range(b, 0, 255));
}

void	print_struct(t_data data)
{
	printf("-----------------------------amb-----------------------------------\n"
       "ratio     : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.amb.ratio, data.amb.color.r, data.amb.color.g, data.amb.color.b);

	printf("----------------------------camera---------------------------------\n"
       "origin.x  : %lf\n"
       "origin.y  : %lf\n"
       "origin.z  : %lf\n"
       "normal.x  : %lf\n"
       "normal.y  : %lf\n"
       "normal.z  : %lf\n"
       "fov       : %lf\n",
       data.camera.origin.x, data.camera.origin.y, data.camera.origin.z, 
       data.camera.normal.x, data.camera.normal.y, data.camera.normal.z, 
       data.camera.fov);

	printf("----------------------------light----------------------------------\n"
       "origin.x  : %lf\n"
       "origin.y  : %lf\n"
       "origin.z  : %lf\n"
       "ratio     : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.light.position.x, data.light.position.y, data.light.position.z, 
       data.light.intensity, data.light.color.r, data.light.color.g, data.light.color.b);

	printf("----------------------------sphere---------------------------------\n"
       "center.x  : %lf\n"
       "center.y  : %lf\n"
       "center.z  : %lf\n"
       "diameter  : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.sphere.center.x, data.sphere.center.y, data.sphere.center.z, 
       data.sphere.diameter, data.sphere.color.r, data.sphere.color.g, data.sphere.color.b);

	printf("----------------------------plane----------------------------------\n"
       "origin.x  : %lf\n"
       "origin.y  : %lf\n"
       "origin.z  : %lf\n"
       "normal.x  : %lf\n"
       "normal.y  : %lf\n"
       "normal.z  : %lf\n"
       "color.r   : %lf\n"
       "color.g   : %lf\n"
       "color.b   : %lf\n",
       data.plane.origin.x, data.plane.origin.y, data.plane.origin.z, 
       data.plane.normal.x, data.plane.normal.y, data.plane.normal.z, 
       data.plane.color.r, data.plane.color.g, data.plane.color.b);

	printf("----------------------------cylinder-------------------------------\n"
       "center.x   : %lf\n"
       "center.y   : %lf\n"
       "center.z   : %lf\n"
       "axisnorm.x : %lf\n"
       "axisnorm.y : %lf\n"
       "axisnorm.z : %lf\n"
       "diameter   : %lf\n"
       "height     : %lf\n"
       "color.r    : %lf\n"
       "color.g    : %lf\n"
       "color.b    : %lf\n",
       data.cylinder.center.x, data.cylinder.center.y, data.cylinder.center.z, 
       data.cylinder.axisnorm.x, data.cylinder.axisnorm.y, data.cylinder.axisnorm.z, 
       data.cylinder.diameter, data.cylinder.height, 
       data.cylinder.color.r, data.cylinder.color.g, data.cylinder.color.b);
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc != 2)
		exit(1);
	if (check_file_extension(argv[1], ".rt") != 0)
		exit(2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(3);
	char		*text;
	char		type[10] = {0};
	int			i;
	t_data		data;
	
	while (1)
	{
		i = 0;
		text = get_next_line(fd);
		if (text == NULL) {
			printf("get_next_line return NULL\n");
			break ;
		} else if (*text == '\n') {
			printf("newline\n");
		} else { 
			i += ft_strspn(text, " \t");
			printf("&text[i]:%s", &text[i]);
			if (ft_strncmp(&text[i], "A", 1) == 0 && ft_isspace(text[i + 1]) != 0)
			{
				// "A 0.22 255,255,255"
				if (sscanf(text, "%s %lf %lf,%lf,%lf", type, &data.amb.ratio, &data.amb.color.r, &data.amb.color.g, &data.amb.color.b) != 5)
				{
					print_struct(data);
					printf("Error1\n");
					exit(1);
				}
				// 0.0 <= ratio <= 1.0 && 0.0 <= color <= 255
				if (out_of_range(data.amb.ratio, 0, 1) || out_of_rgb_range(data.amb.color))
				{
					print_struct(data);
					printf("Error1-B\n");
					exit(1);
				}
			}
			else if (ft_strncmp(&text[i], "C", 1) == 0 && ft_isspace(text[i + 1]) != 0)
			{
				// "C -50.0,0,20 0,0,1 70"
				if (sscanf(text, "%s %lf,%lf,%lf %lf,%lf,%lf %lf", type, &data.camera.origin.x, &data.camera.origin.y, &data.camera.origin.z, &data.camera.normal.x, &data.camera.normal.y, &data.camera.normal.z, &data.camera.fov) != 8)
				{
					print_struct(data);
					printf("Error2\n");
					exit(1);
				}
				// -1.0 <= normal <= 1.0 && 0.0 <= fov <= 180.0
				if (out_of_vec3_range(data.camera.normal, -1.0, 1.0)
					|| out_of_range(data.camera.fov, 0.0, 180.0))
				{
					print_struct(data);
					printf("Error2-B\n");
					exit(1);
				}
			}
			else if (ft_strncmp(&text[i], "L", 1) == 0 && ft_isspace(text[i + 1]) != 0)
			{
				// "L -40.0,50.0,0.0 0.6 10,0,255"
				if (sscanf(text, "%s %lf,%lf,%lf %lf %lf,%lf,%lf", type, &data.light.position.x, &data.light.position.y, &data.light.position.z, &data.light.intensity, &data.light.color.r, &data.light.color.g, &data.light.color.b) != 8)
				{
					print_struct(data);
					printf("Error3\n");
					exit(1);
				}
				// 0.0 <= intensity <= 1.0 || 0.0 <= color <= 255.0
				if (out_of_range(data.light.intensity, 0.0, 1.0) || out_of_rgb_range(data.light.color))
				{
					print_struct(data);
					printf("Error3-B\n");
					exit(1);
				}
			}
			else if (ft_strncmp(&text[i], "sp", 2) == 0 && ft_isspace(text[i + 2]) != 0)
			{
				// "sp 0.0,0.0,20.6 12.6  10,0,255"
				if (sscanf(text, "%s %lf,%lf,%lf %lf %lf,%lf,%lf", type,
					&data.sphere.center.x, &data.sphere.center.y, &data.sphere.center.z, &data.sphere.diameter, &data.sphere.color.r, &data.sphere.color.g, &data.sphere.color.b) != 8)
				{
					print_struct(data);
					printf("Error4\n");
					exit(1);
				}
				// 0.0 <= color <= 255.0
				if (out_of_rgb_range(data.sphere.color))
				{
					print_struct(data);
					printf("Error4-B\n");
					exit(1);
				}
			}
			else if (ft_strncmp(&text[i], "pl", 2) == 0 && ft_isspace(text[i + 2]) != 0)
			{
				// "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225"
				if (sscanf(text, "%s %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf", type, &data.plane.origin.x, &data.plane.origin.y, &data.plane.origin.z, &data.plane.normal.x, &data.plane.normal.y, &data.plane.normal.z, &data.plane.color.r, &data.plane.color.g, &data.plane.color.b) != 10)
				{
					print_struct(data);
					printf("Error5\n");
					exit(1);
				}
				// -1.0 <= norm <= 1.0 || 0.0 <= color <= 255.0
				if (out_of_vec3_range(data.plane.normal, -1.0, 1.0) || out_of_rgb_range(data.plane.color))
				{
					print_struct(data);
					printf("Error5-B\n");
					exit(1);
				}
			}
			else if (ft_strncmp(&text[i], "cy", 2) == 0 && ft_isspace(text[i + 2]) != 0)
			{
				if (sscanf(text, "%s %lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf", type, &data.cylinder.center.x, &data.cylinder.center.y, &data.cylinder.center.z, &data.cylinder.axisnorm.x, &data.cylinder.axisnorm.y, &data.cylinder.axisnorm.z, &data.cylinder.diameter, &data.cylinder.height, &data.cylinder.color.r, &data.cylinder.color.g, &data.cylinder.color.b) != 12)
				{
					print_struct(data);
					printf("Error6\n");
					exit(1);
				}
				// -1.0 <= axisnorm <= 1.0 && 0.0 <= color <= 255.0
				if (out_of_vec3_range(data.cylinder.axisnorm, -1.0, 1.0) || out_of_rgb_range(data.cylinder.color))
				{
					print_struct(data);
					printf("Error6-B\n");
					exit(1);
				}
			}
		}
		free(text);
	}
	print_struct(data);
	close(fd);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q playground.out");
}
