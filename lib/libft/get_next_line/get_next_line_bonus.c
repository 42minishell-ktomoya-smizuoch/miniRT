/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:14:41 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/17 12:53:47 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*save_buf(int fd, char *buf, char *save)
{
	ssize_t	read_size;
	char	*tmp;

	read_size = 1;
	while (!ft_strchr(save, '\n') && read_size != 0)
	{
		read_size = read (fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!save)
			save = ft_strjoin(buf, "");
		else
		{
			tmp = ft_strjoin(save, buf);
			free (save);
			save = tmp;
		}
		if (!save)
			break ;
	}
	buf = NULL;
	return (save);
}

static char	*line_s(char *save)
{
	size_t	i;
	size_t	n;
	char	*line;

	i = 0;
	n = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i ++;
	line = ft_substr(save, 0, i + 1);
	if (ft_strlens(line) == 0)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

static char	*save_save(char *save)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = 0;
	n = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i ++;
	if (save[i] == '\n')
	{
		n = i + 1;
		while (save[i] != '\0')
			i ++;
		tmp = ft_substr(save, n, i - n);
		free (save);
		save = tmp;
	}
	else
	{
		free (save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*save[OPEN_MAX + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	save[fd] = save_buf(fd, buf, save[fd]);
	if (!save[fd])
		return (NULL);
	line = line_s(save[fd]);
	if (!line)
	{
		free (save[fd]);
		return (NULL);
	}
	save[fd] = save_save(save[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		a = 6;

// 	fd = open("test.txt", O_RDONLY);
// 	while (a)
// 	{
// 		line = get_next_line(fd);
// 		printf("> %s", line);
// 		free(line);
// 		a --;
// 	}
// 	int close(int fd);
// 	return (0);
// }
