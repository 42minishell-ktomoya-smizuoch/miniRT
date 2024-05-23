/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:06:40 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/23 12:04:50 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
       data.light.origin.x, data.light.origin.y, data.light.origin.z, 
       data.light.ratio, data.light.color.r, data.light.color.g, data.light.color.b);

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
			}
			else if (ft_strncmp(&text[i], "L", 1) == 0 && ft_isspace(text[i + 1]) != 0)
			{
				// "L -40.0,50.0,0.0 0.6 10,0,255"
				if (sscanf(text, "%s %lf,%lf,%lf %lf %lf,%lf,%lf", type, &data.light.origin.x, &data.light.origin.y, &data.light.origin.z, &data.light.ratio, &data.light.color.r, &data.light.color.g, &data.light.color.b) != 8)
				{
					print_struct(data);
					printf("Error3\n");
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
			}
			else if (ft_strncmp(&text[i], "cy", 2) == 0 && ft_isspace(text[i + 2]) != 0)
			{
				if (sscanf(text, "%s %lf,%lf,%lf %lf,%lf,%lf %lf %lf %lf,%lf,%lf", type, &data.cylinder.center.x, &data.cylinder.center.y, &data.cylinder.center.z, &data.cylinder.axisnorm.x, &data.cylinder.axisnorm.y, &data.cylinder.axisnorm.z, &data.cylinder.diameter, &data.cylinder.height, &data.cylinder.color.r, &data.cylinder.color.g, &data.cylinder.color.b) != 12)
				{
					print_struct(data);
					printf("Error5\n");
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
