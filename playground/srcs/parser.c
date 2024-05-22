/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:06:40 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/18 17:36:55 by ktomoya          ###   ########.fr       */
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
	t_sphere	sphere;
	
	sphere.center.x = 0;
	sphere.center.y = 0;
	sphere.center.z = 0;
	text = NULL;
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
			// “sp 0.0,0.0,20.6 12.6  10,0,255”
			while (text[i] == ' ')
				i++;
			printf("&text[i]:%s\n", &text[i]);
			if (ft_strncmp(&text[i], "sp", ft_strlen("sp")) == 0) {
				if (sscanf(text, "%s %lf,%lf,%lf %lf %d,%d,%d", type,
					&sphere.center.x, &sphere.center.y, &sphere.center.z, &sphere.diameter, &sphere.color.r, &sphere.color.g, &sphere.color.b) != 8) {
					printf("x:%lf, y:%lf, z:%lf, diameter:%lf\n, r:%d, g:%d, b:%d",
					sphere.center.x, sphere.center.y, sphere.center.z, sphere.diameter, sphere.color.r, sphere.color.g, sphere.color.b);
					printf("Error1\n");
					exit(1);
				}
				printf("x:%lf, y:%lf, z:%lf, diameter:%lf, r:%d, g:%d, b:%d\n",
					sphere.center.x, sphere.center.y, sphere.center.z, sphere.diameter, sphere.color.r, sphere.color.g, sphere.color.b);
			}
		}
		free(text);
		text = NULL;
	}
	close(fd);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q playground.out");
}
