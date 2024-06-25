/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:04:34 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/25 14:10:46 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	parse_file(const char *file_path, t_data *data)
{
	int		fd;
	int		obj_cnt[8];
	char	*line;

	if (check_file_extension(file_path, ".rt") != 0)
		exit_with_error(ERR_FILE_EXTENSION);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_with_error(ERR_OPEN_FILE);
	ft_memset(obj_cnt, 0, sizeof(int) * 8);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else if (*line != '\n')
		{
			parse_line(line, data, obj_cnt);
			data->obj_size++;
			check_object_size(obj_cnt, data->obj_size);
		}
		free(line);
	}
	if (obj_cnt[TYPE_AMBIENT_LIGHT] == 0 || obj_cnt[TYPE_CAMERA] == 0)
		error_pixselput(data);
}
