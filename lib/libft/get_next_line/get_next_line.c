/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:00 by ktomoya           #+#    #+#             */
/*   Updated: 2024/05/15 13:59:00 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_return_null(char **target)
{
	free(*target);
	*target = NULL;
	return (NULL);
}

static char	*saverest(char *origin, int delim)
{
	char	*rest;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (origin[i] != delim)
	{
		if (origin[i] == '\0')
			return (free_and_return_null(&origin));
		i++;
	}
	i++;
	while (origin[i + count] != '\0')
		count++;
	rest = ft_calloc(count + 1, sizeof(char));
	if (rest == NULL)
		return (free_and_return_null(&origin));
	ft_memmove(rest, &origin[i], count);
	free(origin);
	return (rest);
}

static char	*trimdelim(char *before, int delim)
{
	char	*after;
	size_t	len;

	len = 0;
	while (before[len] != delim)
	{
		if (before[len] == '\0')
			return (free_and_return_null(&before));
		len++;
	}
	after = ft_calloc(len + 2, sizeof(char));
	if (after == NULL)
		return (NULL);
	ft_memmove(after, before, len + 1);
	return (after);
}

static char	*read_delim(int fd, char *save, int delim)
{
	char	*buf;
	ssize_t	read_size;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL && save != NULL)
		return (free_and_return_null(&save));
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == READ_ERROR)
			break ;
		else if (read_size == END_OF_FILE)
			break ;
		buf[read_size] = '\0';
		save = gnl_strjoin(save, buf);
		if (save == NULL)
			break ;
		if (ft_strchr(buf, delim) != NULL)
			break ;
	}
	free(buf);
	if (read_size == READ_ERROR && save != NULL)
		return (free_and_return_null(&save));
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd == -1 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	save = read_delim(fd, save, '\n');
	if (save == NULL)
		return (NULL);
	if (*save == '\0')
		return (free_and_return_null(&save));
	if (ft_strchr(save, '\n') != NULL)
	{
		line = trimdelim(save, '\n');
		save = saverest(save, '\n');
	}
	else
	{
		line = gnl_strjoin(line, save);
		free(save);
		save = NULL;
	}
	return (line);
}
