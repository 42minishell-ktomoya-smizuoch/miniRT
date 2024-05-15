/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:06:40 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/15 10:14:05 by ktomoya          ###   ########.fr       */
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
	int	fd;

	if (argc != 2)
		exit(1);
	if (check_file_extension(argv[1], ".rt") != 0)
		exit(2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(3);
	char	*text = get_next_line(fd);
	printf("%s", text);
	close(fd);
}
