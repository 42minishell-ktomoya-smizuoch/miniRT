/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:02:18 by smizuoch          #+#    #+#             */
/*   Updated: 2024/06/12 16:11:48 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
# include "./get_next_line/get_next_line_bonus.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_sscanf
{
	int		count;
	int		*ip;
	double	*dp;
	char	*s;
	char	*c;
}	t_sscanf;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
size_t	ft_strspn(const char *s, const char *accept);
size_t	ft_strcspn(const char *s, const char *reject);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_sscanf(const char *str, const char *format, ...);
double	read_double(const char **str, int s);
double	ft_atof(const char *str);
size_t	ft_strlens(const char *s);

void	*ft_realloc(void *ptr, size_t new_size);
void	*xmalloc(size_t size);
int		ft_isxdigit(int c);
int		ft_islower(int c);

unsigned long	simple_strtoul(const char *cp,char **endp, unsigned int base);
long			simple_strtol(const char *cp,char **endp,unsigned int base);

unsigned long long	simple_strtoull(const char *cp, char **endp, unsigned int base);
long long			simple_strtoll(const char *cp, char **endp, unsigned int base);

int		skip_atoi(const char **s);
void	handle_char(const char **str, va_list args, int field_width, int *num);
void	handle_string(const char **str, va_list args, int field_width, int *num);
void	handle_percent(const char **str, int *num);
void	handle_n(const char *buf, const char **str, va_list args);

#endif