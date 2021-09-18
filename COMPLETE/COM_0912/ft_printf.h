/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:43:55 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/11 18:46:06 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <float.h>

# define PRINTF_MAX_FLOAT				1e22
# define PRINTF_NTOA_BUFFER_SIZE		32
# define PRINTF_FTOA_BUFFER_SIZE		32
# define PRINTF_DEFAULT_FLOAT_PRECISION	6
# define TRUE							1
# define FALSE							0

// # define FLAGS_ZEROPAD					0b00000000000000001
// # define FLAGS_LEFT						0b00000000000000010
// # define FLAGS_PLUS						0b00000000000000100
// # define FLAGS_SPACE					0b00000000000001000
// # define FLAGS_HASH						0b00000000000010000
// # define FLAGS_UPPERCASE				0b00000000000100000
// # define FLAGS_CHAR						0b00000000001000000
// # define FLAGS_SHORT					0b00000000010000000
// # define FLAGS_LONG						0b00000000100000000
// # define FLAGS_LONG_LONG				0b00000001000000000
// # define FLAGS_PRECISION				0b00000010000000000
// # define FLAGS_ADAPT_EXP				0b00000100000000000
// # define FLAGS_ASTER					0b00001000000000000
// # define FLAGS_ASTER2					0b00010000000000000
// # define FLAGS_MINUS_WIDTH				0b00100000000000000
// # define FLAGS_MINUS_PRECISION			0b01000000000000000
// # define CONSECUTIVE_ZERO				0b10000000000000000

typedef enum e_flags
{
	FLAGS_ZEROPAD =			(1 << 0),
	FLAGS_LEFT =			(1 << 1),
	FLAGS_PLUS =			(1 << 2),
	FLAGS_SPACE =			(1 << 3),
	FLAGS_HASH =			(1 << 4),
	FLAGS_UPPERCASE =		(1 << 5),
	FLAGS_CHAR =			(1 << 6),
	FLAGS_SHORT =			(1 << 7),
	FLAGS_LONG =			(1 << 8),
	FLAGS_LONG_LONG =		(1 << 9),
	FLAGS_PRECISION =		(1 << 10),
	FLAGS_ADAPT_EXP =		(1 << 11),
	FLAGS_ASTER =			(1 << 12),
	FLAGS_ASTER2 =			(1 << 13),
	FLAGS_MINUS_WIDTH =		(1 << 14),
	FLAGS_MINUS_PRECISION =	(1 << 15),
	CONSECUTIVE_ZERO =		(1 << 16),
}			t_flags;

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	base;
	size_t			maxlen;
	size_t			idx;
	char			buf[PRINTF_NTOA_BUFFER_SIZE];
	int				negative;
	int				qualifier;
}			t_format;

typedef struct s_ftoa
{
	unsigned long long	whole;
	int					negative;
	size_t				len;
	double				diff;
	unsigned long long	frac;
}				t_ftoa;

typedef struct s_etoa
{
	int				expval;
	int				exp2;
	int				negative;
	unsigned int	minwidth;
}				t_etoa;

typedef union u_conv
{
	unsigned long	u;
	double			f;
}				t_conv;

int				is_digit(char ch);
void			ft_printf_internal(const char *format,
					va_list va, t_format *fmt);
void			ft_putchar(char c);
void			out_char(char character, size_t idx);
size_t			out_rev(size_t idx, const char *buf, size_t len, t_format *fmt);
size_t			ntoa_format(size_t idx, size_t len, t_format *fmt);
size_t			ntoa_long(size_t idx, unsigned long value, t_format *fmt);
size_t			ntoa_long_long(size_t idx,
					unsigned long long value, t_format *fmt);
size_t			ftoa(size_t idx, double value, t_format *fmt);
size_t			etoa(size_t idx, double value, t_format *fmt);
unsigned int	ft_atoi_pf(const char **str);
unsigned int	ft_strnlen(const char *str, size_t maxsize);
void			ft_base_num(const char *format, t_format *fmt);

const char		*ft_flags(const char *format, t_format *fmt);
const char		*consecutive_zero(const char *format, t_format *fmt);
const char		*ft_width(const char *format, va_list va, t_format *fmt);
const char		*ft_precision(const char *format, va_list va, t_format *fmt);
const char		*ft_length(const char *format, t_format *fmt);
const char		*ft_type(const char *format, va_list va, t_format *fmt);

const char		*ft_type_n(const char *format, va_list va, t_format *fmt);
const char		*ft_type_f(const char *format, va_list va, t_format *fmt);
const char		*ft_type_ptr(const char *format, va_list va, t_format *fmt);
const char		*ft_type_str(const char *format, va_list va, t_format *fmt);
const char		*ft_type_char(const char *format, va_list va, t_format *fmt);

#endif
