/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:29:20 by ktomoya           #+#    #+#             */
/*   Updated: 2023/06/27 21:53:00 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define END_OF_FILE 0
# define READ_ERROR -1

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*gnl_strjoin(char *s1, char *s2);

#endif