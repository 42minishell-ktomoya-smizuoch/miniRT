#include "libft.h"
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

#define ZEROPAD 1               /* pad with zero */
#define SIGN    2               /* unsigned/signed long */
#define PLUS    4               /* show plus */
#define SPACE   8               /* space if plus */
#define LEFT    16              /* left justified */
#define SPECIAL 32              /* 0x */
#define LARGE   64              /* use 'ABCDEF' instead of 'abcdef' */

typedef struct 	s_int_list
{
	int	num;
	int	qualifier;
	int	base;
	int	field_width;
	int	is_sign;
}	t_int_list;

void handle_integer(const char **str, va_list args, int base, int is_sign, int qualifier, int *num) {
    char *next;
    if (qualifier == 'H') {
        if (is_sign) {
            signed char *s = (signed char *) va_arg(args, signed char *);
            *s = (signed char) simple_strtol(*str, &next, base);
        } else {
            unsigned char *s = (unsigned char *) va_arg(args, unsigned char *);
            *s = (unsigned char) simple_strtoul(*str, &next, base);
        }
    } else if (qualifier == 'h') {
        if (is_sign) {
            short *s = (short *) va_arg(args, short *);
            *s = (short) simple_strtol(*str, &next, base);
        } else {
            unsigned short *s = (unsigned short *) va_arg(args, unsigned short *);
            *s = (unsigned short) simple_strtoul(*str, &next, base);
        }
    } else if (qualifier == 'l') {
        if (is_sign) {
            long *l = (long *) va_arg(args, long *);
            *l = simple_strtol(*str, &next, base);
        } else {
            unsigned long *l = (unsigned long *) va_arg(args, unsigned long *);
            *l = simple_strtoul(*str, &next, base);
        }
    } else if (qualifier == 'L') {
        if (is_sign) {
            long long *l = (long long *) va_arg(args, long long *);
            *l = simple_strtoll(*str, &next, base);
        } else {
            unsigned long long *l = (unsigned long long *) va_arg(args, unsigned long long *);
            *l = simple_strtoull(*str, &next, base);
        }
    } else if (qualifier == 'Z' || qualifier == 'z') {
        size_t *s = (size_t *) va_arg(args, size_t *);
        *s = (size_t) simple_strtoul(*str, &next, base);
    } else {
        if (is_sign) {
            int *i = (int *) va_arg(args, int *);
            *i = (int) simple_strtol(*str, &next, base);
        } else {
            unsigned int *i = (unsigned int *) va_arg(args, unsigned int *);
            *i = (unsigned int) simple_strtoul(*str, &next, base);
        }
    }
    if (!next)
        return;
    *str = next;
    (*num)++;
}

int vsscanf(const char *buf, const char *fmt, va_list args) {
    const char *str = buf;
	t_int_list i;

	i.num = 0;
	i.is_sign = 0;
    while (*fmt && *str) {
        if (isspace(*fmt)) {
            while (isspace(*fmt))
                ++fmt;
            while (isspace(*str))
                ++str;
        }

        if (*fmt != '%' && *fmt) {
            if (*fmt++ != *str++)
                break;
            continue;
        }

        if (!*fmt)
            break;
        ++fmt;

        if (*fmt == '*') {
            while (!isspace(*fmt) && *fmt)
                fmt++;
            while (!isspace(*str) && *str)
                str++;
            continue;
        }

        i.field_width = -1;
        if (isdigit(*fmt))
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

        while (isspace(*str))
            str++;

        char digit = *str;
        if (i.is_sign && digit == '-')
            digit = *(str + 1);

        if (!digit || (i.base == 16 && !isxdigit(digit)) || (i.base == 10 && !isdigit(digit)) || (i.base == 8 && (!isdigit(digit) || digit > '7')) || (i.base == 0 && !isdigit(digit)))
            break;

        handle_integer(&str, args_copy, i.base, i.is_sign, i.qualifier, &i.num);
        va_end(args_copy);
    }
    return (i.num);
}

int ft_sscanf(const char * buf, const char * fmt, ...)
{
	va_list args;
	int		i;

	va_start(args,fmt);
	i = vsscanf(buf,fmt,args);
	va_end(args);
	return (i);
}