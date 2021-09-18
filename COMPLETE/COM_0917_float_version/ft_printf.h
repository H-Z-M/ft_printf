/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:43:55 by sudatsu           #+#    #+#             */
/*   Updated: 2021/09/17 12:40:02 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>

# define PRINTF_MAX_FLOAT				1e22
# define PRINTF_FTOA_BUFFER_SIZE		32
# define PRINTF_DEFAULT_FLOAT_PRECISION	6
# define TRUE							1
# define FALSE							0

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
	FLAGS_MINUS_WIDTH =		(1 << 14),
	FLAGS_PTR =				(1 << 15),
}			t_flags;

typedef struct s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	base;
	size_t			idx;
	int				negative;
	int				qualifier;
}			t_format;

typedef struct s_ftoa
{
	unsigned long long	whole;
	unsigned long long	frac;
	char				buf[PRINTF_FTOA_BUFFER_SIZE];
	size_t				len;
	double				diff;
	int					negative;
}				t_ftoa;

typedef struct s_etoa
{
	unsigned int	minwidth;
	int				expval;
	int				exp2;
	int				negative;
}				t_etoa;

typedef union u_conv
{
	unsigned long	u;
	double			f;
}				t_conv;

int		ft_printf(const char *format, ...);
int		is_digit(char ch);
void	ft_base_num(const char *format, t_format *fmt);
void	ft_putchar(char c);
void	out_char(char character, size_t idx);
void	ft_type_else_format(const char **format, va_list va, t_format *fmt);
size_t	out_rev(size_t idx, const char *buf, size_t len, t_format *fmt);
size_t	ntoa_format(char *buf, size_t idx, size_t len, t_format *fmt);
size_t  ntoa_format_len(size_t len, t_format *fmt);
size_t	ntoa_format_hash_len(size_t len, t_format *fmt);
size_t	ntoa_long(size_t idx, unsigned long value, t_format *fmt);
size_t	ntoa_long_long(size_t idx, unsigned long long value, t_format *fmt);
size_t	ftoa(size_t idx, double value, t_format *fmt);
size_t	etoa(size_t idx, double value, t_format *fmt);
size_t	ft_atoi_pf(const char **str);
size_t	ft_strnlen(const char *str, int maxsize);

void	ft_flags(const char **format, t_format *fmt);
void	ft_width(const char **format, va_list va, t_format *fmt);
void	ft_precision(const char **format, va_list va, t_format *fmt);
void	ft_length(const char **format, t_format *fmt);
void	ft_type(const char **format, va_list va, t_format *fmt);

void	ft_type_n(const char **format, va_list va, t_format *fmt);
void	ft_type_f(const char **format, va_list va, t_format *fmt);
void	ft_type_ptr(const char **format, va_list va, t_format *fmt);
void	ft_type_str(const char **format, va_list va, t_format *fmt);
void	ft_type_char(const char **format, va_list va, t_format *fmt);

#endif
