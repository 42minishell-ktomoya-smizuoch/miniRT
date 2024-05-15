/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:04:34 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 13:48:46 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//パーサー関数
//パーサー関数は、ファイルを読み込み、各行を解析し、
//各要素を適切なデータ構造に格納する
//パーサー関数は、ファイルの読み込み、行の解析、データの格納の3つのステップに分かれる
//各ステップは、それぞれの関数に分割することができる
//get_next_line関数を使用してファイルを読み込む
//各行を格納ft_sscanf関数を使用する
//全てをparser

/* .rtファイルの例
A 0.2 255,255,255
C -50,0,20 0,0,0 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
*/
int	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int	parse_line(char *line)
{
	char	type;
	int		ret;

	ret = ft_sscanf(line, "%c", &type);
	if (ret != 1)
		return (-1);
	if (type == 'A')
	{
		//ambient light
	}
	else if (type == 'C')
	{
		//camera
	}
	else if (type == 'L')
	{
		//light
	}
	else if (type == 'l')
	{
		//light
	}
	else if (type == 'p')
	{
		//plane
	}
	else if (type == 's')
	{
		//sphere
	}
	else if (type == 'c')
	{
		//cylinder
	}
	else if (type == 't')
	{
		//triangle
	}
	else
		return (-1);
	return (0);
}

int	parser(const char *file)
{
	int		fd;
	char	*line;
	char	*data;
	int		ret;

	if (!file)
		return (error_msg(ERR_ARG));
	if (ft_strncmp(file + ft_strlen(file) - 3, ".rt", 3) != 0)
		return (error_msg(ERR_FILE_FORMAT));
	//階層は../../rt_fileの中にあるのでその階層に移動
	data = ft_strjoin("../../rt_file/", file);
	if (!data)
		return (error_msg(ERR_MALLOC));
	fd = open(data, O_RDONLY);
	free(data);
	if (fd == -1)
		return (error_msg(ERR_OPEN_FILE));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ret = parse_line(line);
		free(line);
		if (ret == -1)
			return (error_msg(ERR_PARSE_FILE));
	}
	close(fd);
	return (0);
}
