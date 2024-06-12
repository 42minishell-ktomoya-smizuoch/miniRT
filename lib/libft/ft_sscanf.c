#include "libft.h"
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

void	process_size_t(const char **str,
		va_list args, int base, char **next)
{
	size_t	*s;

	s = (size_t *)va_arg(args, size_t *);
	*s = (size_t)simple_strtoul(*str, next, base);
}

void handle_integer(const char **str, va_list args, t_int_list i, int *num)
{
    char *next = NULL;

    if (i.qualifier == 'H')
	{
        if (i.is_sign) {
            process_signed_char(str, args, i.base, &next);
        } else {
            process_unsigned_char(str, args, i.base, &next);
        }
    } else if (i.qualifier == 'h') {
        process_short(str, args, i, &next);
    } else if (i.qualifier == 'l') {
        process_long(str, args, i, &next);
    } else if (i.qualifier == 'L') {
        process_long_long(str, args, i, &next);
    } else if (i.qualifier == 'Z' || i.qualifier == 'z'){
        process_size_t(str, args, i.base, &next);
    } else {
        if (i.is_sign) {
            int *j = (int *)va_arg(args, int *);
            *j = (int)simple_strtol(*str, &next, i.base);
        } else {
            unsigned int *j = (unsigned int *)va_arg(args, unsigned int *);
            *j = (unsigned int)simple_strtoul(*str, &next, i.base);
        }
    }
    if (next)
	{
        *str = next;
        (*num)++;
    }
}


int	vsscanf(const char *buf, const char *fmt, va_list args)
{
	const char	*str = buf;
	t_int_list	i;

	i.num = 0;
	i.is_sign = 0;
    while (*fmt && *str)
	{
        if (ft_isspace(*fmt))
		{
            while (ft_isspace(*fmt))
                ++fmt;
            while (ft_isspace(*str))
                ++str;
        }

        if (*fmt != '%' && *fmt)
		{
            if (*fmt++ != *str++)
                break ;
            continue ;
        }

        if (!*fmt)
            break;
        ++fmt;

        if (*fmt == '*') {
            while (!ft_isspace(*fmt) && *fmt)
                fmt++;
            while (!ft_isspace(*str) && *str)
                str++;
            continue;
        }

        i.field_width = -1;
        if (ft_isdigit(*fmt))
            i.field_width = skip_atoi(&fmt);

        i.qualifier = -1;
        if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L' || *fmt == 'Z' || *fmt == 'z') {
            i.qualifier = *fmt++;
            if (i.qualifier == *fmt) {
                if (i.qualifier == 'h') {
                    i.qualifier = 'H';
                    fmt++;
                } else if (i.qualifier == 'l') {
                    i.qualifier = 'L';
                    fmt++;
                }
            }
        }
        i.base = 10;
        i.is_sign = 0;

        if (!*fmt || !*str)
            break;

        va_list args_copy;
        va_copy(args_copy, args);

        if (*fmt == 'c') {
            handle_char(&str, args_copy, i.field_width, &i.num);
            fmt++;
        } else if (*fmt == 's') {
            handle_string(&str, args_copy, i.field_width, &i.num);
            fmt++;
        } else if (*fmt == 'n') {
            handle_n(buf, &str, args_copy);
            fmt++;
        } else if (*fmt == 'o') {
            i.base = 8;
            fmt++;
        } else if (*fmt == 'x' || *fmt == 'X') {
            i.base = 16;
            fmt++;
        } else if (*fmt == 'i') {
            i.base = 0;
            fmt++;
        } else if (*fmt == 'd') {
            i.is_sign = 1;
            fmt++;
        } else if (*fmt == 'u') {
            fmt++;
        } else if (*fmt == '%') {
            handle_percent(&str, &i.num);
            fmt++;
        } else {
            va_end(args_copy);
            return i.num;
        }

        while (ft_isspace(*str))
            str++;

        char digit = *str;
        if (i.is_sign && digit == '-')
            digit = *(str + 1);

        if (!digit || (i.base == 16 && !ft_isxdigit(digit)) || (i.base == 10 && !ft_isdigit(digit)) || (i.base == 8 && (!ft_isdigit(digit) || digit > '7')) || (i.base == 0 && !ft_isdigit(digit)))
            break;

        handle_integer(&str, args_copy, i, &i.num);
        va_end(args_copy);
    }
    return (i.num);
}

int	ft_sscanf(const char *buf, const char *fmt, ...)
{
	int		i;
	va_list	args;

	va_start(args, fmt);
	i = vsscanf(buf, fmt, args);
	va_end(args);
	return (i);
}
