/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:06:40 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/22 09:41:42 by ktomoya          ###   ########.fr       */
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
	printf("sphere.center.x:%lf\nsphere.center.y:%lf\nsphere.center.z:%lf\nsphere.diameter:%lf\nsphere.color.r:%lf\nsphere.color.g:%lf\nsphere.color.b:%lf\n",
	data.sp->center.x, data.sp->center.y, data.sp->center.z, data.sp->diameter, data.sp->color.r, data.sp->color.g, data.sp->color.b);
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
	
	data.sp = ft_calloc(1, sizeof(t_sphere));
	data.sp->center.x = 0;
	data.sp->center.y = 0;
	data.sp->center.z = 0;
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
			i += ft_strspn(text, " \t");
			printf("&text[i]:%s\n", &text[i]);
			if (ft_strncmp(&text[i], "sp ", ft_strlen("sp ")) == 0) {
				if (sscanf(text, "%s %lf,%lf,%lf %lf %lf,%lf,%lf", type,
					&data.sp->center.x, &data.sp->center.y, &data.sp->center.z, &data.sp->diameter, &data.sp->color.r, &data.sp->color.g, &data.sp->color.b) != 8) {
					print_struct(data);
					printf("Error1\n");
					exit(1);
				}
				print_struct(data);
			}
		}
		free(text);
	}
	free(data.sp);
	close(fd);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q playground.out");
}
